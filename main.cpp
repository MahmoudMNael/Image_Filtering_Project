// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name: main.cpp
// Last Modification Date: 19/10/2023
// Author1: Mahmoud Mohammed Nael, 20220322, A, S12
// Author2: Mazen Mohammed Nayef, 20220268, A, S12
// Author3: Mohammed Ahmed Fathy, N/A, A, S12
// Teaching Assistant: N/A
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file

#include <bits/stdc++.h>
#include "bmplib.h"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char imageq1[128][128];
unsigned char imageq2[128][128];
unsigned char imageq3[128][128];
unsigned char imageq4[128][128];


string inputFilterNumber();
void loadImage();
void loadImage2();
void doSomethingForImage(string filter);
void saveImage();


// Filters
void rotateImage();
void invertImage();
void convertImageToBlackAndWhite();
void flipImage();
void flipVertical();
void flipHorizontal();
void mergeImages();
void lightenOrDarkenImage();
void enlargeImage();
void dividedImage();
void shuffleImage();
void skewHorizontally();
void skewVetically();
void blurImage();
void shrinkImage();
void mirrorLeft();
void mirrorRight();
void mirrorUpper();
void mirrorLower();
void mirrorImage();
void cropImage();
void detectImageEdges();
// End Filters

int main() {
    loadImage();
	string filterNumber = inputFilterNumber();
	doSomethingForImage(filterNumber);
	while (filterNumber[0] != '0'){
		filterNumber = inputFilterNumber();
		doSomethingForImage(filterNumber);
		if(filterNumber[0] == 's'){
			string inputChar;
			cout << "1. Do you want to continue on the same image?\n2. Or choose another one?\n 0. Exit" << endl;
            while (cin>>inputChar) {
				if (inputChar[0] >= '0' || inputChar[0] <= '2') {
					if (inputChar[0] == '1'){
						break;
					} else if (inputChar[0] == '2') {
						loadImage();
						break;
					} else {
						cout << "Thanks for using our program!" << endl;
                        return 0;
					}
				} else {
					cout << "Enter a valid number from 0~2: " << endl;
				}
			}
		}
	}
    return 0;
}

string inputFilterNumber(){
	string filterNumber;
	cout << "1. Black and White\n" << "2. Invert Image\n" << "3. Merge Images\n" << "4. Flip Image\n" << "5. Rotate Image\n" << "6. Darken or Lighten Image\n" << "7. Detect Image Edges\n" << "8. Enlarge Image\n" << "9. Shrink Image\n" << "a. Mirror Image\n" << "b. Shuffle Image\n" << "c. Blur Image\n" << "d. Crop Image\n" << "e. Skew Image Horizontally\n" << "f. Skew Image Vertically\n" << "s. Save the image to a file\n" << "0. Exit\n" << endl;
	cout << "Enter the number of the filter you desire or 0 to exit or 's' to save: " << endl;
	while (cin >> filterNumber) {
		if ((filterNumber[0] >= '0' && filterNumber[0] <= '9' ) || (filterNumber[0] >= 'a' && filterNumber[0] <= 'f') || filterNumber[0] == 's') {
			return filterNumber;
		} else {
			cout << "Enter a valid number from 0~9 or a~f or s: " << endl;
		}
	}
}

void loadImage () {
	char imageFileName[100];
	
	// Get gray scale image file name
	cout << "Enter the source image file name: " << endl;
	cin >> imageFileName;
	
	// Add to it .bmp extension and load image
	strcat (imageFileName, ".bmp");
	readGSBMP(imageFileName, image);
}

void loadImage2() {
    char imageFileName2[100];

    // Get gray scale image file name
    cout << "Enter the second source image file name: ";
    cin >> imageFileName2;

    // Add to it .bmp extension and load image
    strcat (imageFileName2, ".bmp");
    readGSBMP(imageFileName2, image2);
}

void doSomethingForImage(string filter) {
	switch (filter[0]) {
		case '0':
			cout << "Thanks for using our program!" << endl;
			return;
		case '1':
			convertImageToBlackAndWhite();
			break;
        case '2':
            invertImage();
			break;
		case '3':
            loadImage2();
            mergeImages();
            break;
		case '4':
			flipImage();
			break;
		case '5':
			rotateImage();
			break;
		case '6':
            lightenOrDarkenImage();
			break;
		case '7':
			detectImageEdges();
			break;
        case '8':
            enlargeImage();
            break;
		case '9':
			shrinkImage();
			break;
		case 'a':
			mirrorImage();
			break;
		case'b':
			dividedImage();
			shuffleImage();
			break;
		case 'c':
            blurImage();
            break;
		case 'd':
			cropImage();
			break;
        case 'e':
            skewHorizontally();
            break;
        case 'f':
            skewVetically();
            break;
		case 's':
			saveImage();
			break;
	}
}

void saveImage () {
	char imageFileName[100];
	
	// Get gray scale image target file name
	cout << "Enter the target image file name: " << endl;
	cin >> imageFileName;
	
	// Add to it .bmp extension and load image
	strcat (imageFileName, ".bmp");
	writeGSBMP(imageFileName, image);
}


// Filters
void convertImageToBlackAndWhite() {
	// Get the average of the pixels
	int pixelSum = 0;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			pixelSum += image[i][j];
		}
	}
	
	// Compare the pixel with the avg if greater than white else black
	int pixelAvg = pixelSum / (SIZE * SIZE);
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (image[i][j] > pixelAvg)
				image[i][j] = 255;
			else
				image[i][j] = 0;
		}
	}
}

void flipVertical() {
	// Loop for half the image and swap every pixel with its corresponding one on the vertical direction
	unsigned char temp;
	for (int i = 0; i < SIZE / 2; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			temp = image[i][j];
			image[i][j] = image[SIZE - 1 - i][j];
			image[SIZE - 1 - i][j] = temp;
		}
	}
}

void flipHorizontal(){
	// Loop for half the image and swap every pixel with its corresponding one on the horizontal direction
	unsigned char temp;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE / 2; ++j) {
			temp = image[i][j];
			image[i][j] = image[i][SIZE - 1 - j];
			image[i][SIZE - 1 - j] = temp;
		}
	}
}

void flipImage() {
	string enteredFlipNumber;
	cout << "1. Horizontal Flip\n" << "2. Vertical Flip\n" << "3. Horizontal and Vertical Flip" << endl;
	cout << "Enter the desired number: " << endl;
	while (cin >> enteredFlipNumber) {
		if (enteredFlipNumber[0] >= '1' && enteredFlipNumber[0] <= '3') {
			break;
		} else {
			cout << "Enter a valid number from 1~3: " << endl;
		}
	}
	switch (enteredFlipNumber[0]) {
		case '1':
			// use Function
			flipHorizontal();
			break;
		case '2':
			// use Function
			flipVertical();
			break;
		case '3':
			// use Function
			flipVertical();
			flipHorizontal();
			break;
	}
	
}

void invertImage(){
	for (int i=0;i<255;i++){
		for(int j=0 ;j<255;j++) {
			image[i][j] = 255 - image[i][j];
		}
	}
}

void rotateImage () {
	long long degree;
	cout << "Enter the degree you desire (90, 180, 270): " << endl;
	while (cin >> degree) {
		if (degree == 90 || degree == 180 || degree == 270) {
			break;
		} else {
			cout << "Enter a valid degree (90, 180, 270): " << endl;
		}
	}
	for(int k=0;k<(degree/90);k++) {
		for (int i = 0; i < 256; i++) {
			for (int j = i + 1; j < 256; j++) {
				swap(image[i][j], image[j][i]);
			}
		}
		for (int i = 0; i < 256; i++) {
			int left = 0, right = 255;
			while (left < right) {
				swap(image[i][left], image[i][right]);
				left++;
				right--;
			}
		}
	}
}

void mergeImages() {
	int average;
	
	// Add 2 photos to each other by taking the average of grey level of each corresponding pixel.
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			average = ( image[i][j] + image2[i][j] ) / 2;
			image[i][j] = average;
		}
	}
}

void lightenOrDarkenImage() {
	string type;
	
	// Get the operation that customer wants.
	cout << "Please Choose If You Want It (L)ighten/(D)arken By 50%: ";
	while (cin >> type) {
		if (type[0] == 'L' || type[0] == 'D' || type[0] == 'l' || type[0] == 'd') {
			break;
		} else {
			cout << "Enter a valid letter either (L/l) or (D/d): " << endl;
		}
	}
	
	// Process of lighten images.
	if (type[0] == 'L' || type[0] == 'l'){
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				image[i][j] = image[i][j] + (255-image[i][j])*0.5;
			}
		}
	}
		
    // Process of darken images.
	else if (type[0] == 'D' || type[0] == 'd'){
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				image[i][j] = image[i][j] * 0.5;
			}
		}
	}
}


void enlargeImage(){
    int qrt;
    cout<<"enter the quarter which need to be large: \n";
    while(cin>> qrt){
        if(qrt==1||qrt==2||qrt==3||qrt==4){
            break;
        }else
            cout<<"enter the valid number 1 or 2 or 3 or 4:";
    }
    if(qrt==1) {
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
               imageq1[i][j]=image[i][j];
            }
        }
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for(int k =0;k<2;k++){
                    for(int l=0;l<2;l++){
                        image[(i*2)+k][(j*2)+l]=imageq1[i][j];
                    }
                }
            }
        }

    }else if(qrt==2){
        for (int i = 0; i < 128; i++) {
            int x = 0;
            for (int j = 127; j < 256; j++) {
                imageq1[i][x] = image[i][j];
                x++;
            }
        }
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for(int k =0;k<2;k++){
                    for(int l=0;l<2;l++){
                        image[(i*2)+k][(j*2)+l]=imageq1[i][j];
                    }
                }
            }
        }
    }else if(qrt==3){
        for (int i = 127,x=0; i < 256; i++,x++) {
            for (int j = 0; j < 128; j++) {
                imageq1[x][j] = image[i][j];

            }
        }
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for(int k =0;k<2;k++){
                    for(int l=0;l<2;l++){
                        image[(i*2)+k][(j*2)+l]=imageq1[i][j];
                    }
                }
            }
        }
    }else if(qrt==4){
        for (int i = 127,x=0; i < 256; i++,x++) {
            for (int j = 127,y=0; j < 256; j++,y++) {
                imageq1[x][y] = image[i][j];
            }
        }
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                for(int k =0;k<2;k++){
                    for(int l=0;l<2;l++){
                        image[(i*2)+k][(j*2)+l]=imageq1[i][j];
                    }
                }
            }
        }

    }

}

void dividedImage(){
    for(int i=0;i<128;i++){
        for(int j=0;j<128;j++){
            imageq1[i][j]=image[i][j];
        }
    }
    for(int i=0;i<128;i++){
        for(int j=128,x=0;j<256;j++,x++){
            imageq2[i][x]=image[i][j];
        }
    }
    for(int i=128,y=0;i<256;i++,y++){
        for(int j=0;j<128;j++){
            imageq3[y][j]=image[i][j];
        }
    }
    for(int i=128,y=0;i<256;i++,y++){
        for(int j=128,x=0;j<256;j++,x++){
            imageq4[y][x]=image[i][j];
        }
    }
}
void shuffleImage() {
	int qrt;
	cout << "enter the order of quarter you need: \n";
	for (int k = 0; k < 4; k++) {
		cin >> qrt;
		if (qrt <= 0 && qrt > 4) {
			cout << "enter the valid no between 1 to 4 : \n";
		}
		if (k == 0) {
			for (int i = 0; i < 128; i++) {
				for (int j = 0; j < 128; j++) {
					if (qrt == 1) {
						image[i][j] = imageq1[i][j];
					} else if (qrt == 2) {
						image[i][j] = imageq2[i][j];
					} else if (qrt == 3) {
						image[i][j] = imageq3[i][j];
					} else if (qrt == 4) {
						image[i][j] = imageq4[i][j];
					}
				}
			}
		} else if (k == 1) {
			for (int i = 0; i < 128; i++) {
				for (int j = 128, x = 0; j < 256; j++, x++) {
					if (qrt == 1) {
						image[i][j] = imageq1[i][x];
					} else if (qrt == 2) {
						image[i][j] = imageq2[i][x];
					} else if (qrt == 3) {
						image[i][j] = imageq3[i][x];
					} else if (qrt == 4) {
						image[i][j] = imageq4[i][x];
					}
				}
			}
		} else if (k == 2) {
			for (int i = 128, y = 0; i < 256; i++, y++) {
				for (int j = 0; j < 128; j++) {
					if (qrt == 1) {
						image[i][j] = imageq1[y][j];
					} else if (qrt == 2) {
						image[i][j] = imageq2[y][j];
					} else if (qrt == 3) {
						image[i][j] = imageq3[y][j];
					} else if (qrt == 4) {
						image[i][j] = imageq4[y][j];
					}
				}
			}
		} else if (k == 3) {
			for (int i = 128, y = 0; i < 256; i++, y++) {
				for (int j = 128, x = 0; j < 256; j++, x++) {
					if (qrt == 1) {
						image[i][j] = imageq1[y][x];
					} else if (qrt == 2) {
						image[i][j] = imageq2[y][x];
					} else if (qrt == 3) {
						image[i][j] = imageq3[y][x];
					} else if (qrt == 4) {
						image[i][j] = imageq4[y][x];
					}
				}
			}
		}
	}
}

void mirrorLeft(){
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE / 2; ++j) {
			image[i][SIZE - 1 - j] = image[i][j];
		}
	}
}

void mirrorRight(){
	for (int i = 0; i < SIZE; ++i) {
		for (int j = SIZE / 2 - 1, k = SIZE / 2 - 1; j < SIZE, k >= 0; ++j, --k) {
			image[i][k] = image[i][j];
		}
	}
}

void mirrorUpper(){
	for (int i = 0; i < SIZE / 2; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			image[SIZE - 1 - i][j] = image[i][j];
		}
	}
}

void mirrorLower(){
	for (int i = SIZE / 2 - 1, k = SIZE / 2 - 1; i < SIZE, k >= 0; ++i, --k) {
		for (int j = 0; j < SIZE; ++j) {
			image[k][j] = image[i][j];
		}
	}
}

void mirrorImage() {
	string enteredMirrorNumber;
	cout << "1. Mirror Left\n" << "2. Mirror Right\n" << "3. Mirror Upper\n" << "4. Mirror Lower" << endl;
	cout << "Enter the desired number: " << endl;
	while (cin >> enteredMirrorNumber) {
		if (enteredMirrorNumber[0] >= '1' && enteredMirrorNumber[0] <= '4') {
			break;
		} else {
			cout << "Enter a valid number from 1~4: " << endl;
		}
	}
	switch (enteredMirrorNumber[0]) {
		case '1':
			mirrorLeft();
			break;
		case '2':
			mirrorRight();
			break;
		case '3':
			mirrorUpper();
			break;
		case '4':
			mirrorLower();
			break;
	}
}

void cropImage(){
	int x, y;
	cout << "Please, enter the desired coordinates" << endl;
	cout << "X: \n";
	cin >> x;
	cout << "Y: \n";
	cin >> y;
	
	int length, width, skippedLength, skippedWidth;
	cout << "Please, enter the desired dimensions" << endl;
	cout << "Length: \n";
	cin >> length;
	cout << "Width: \n";
	cin >> width;
	
	skippedLength = (SIZE - 1 - length) / 2;
	skippedWidth = (SIZE - 1 - width) / 2;
	
	unsigned char tempImage[SIZE][SIZE];
	
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			tempImage[i][j] = image[i][j];
			image[i][j] = 255;
		}
	}
	for (int i = y, l = 0; i <= width; ++i, ++l) {
		for (int j = x, m = 0; j <= length; ++j, ++m) {
			image[skippedWidth + l][skippedLength + m] = tempImage[i][j];
		}
	}
}

void detectImageEdges(){
	unsigned char tempImage[SIZE][SIZE];
//	for (int i = 0; i < SIZE; ++i) {
//		for (int j = 0; j < SIZE; ++j) {
//			tempImage[i][j] = image[i][j];
//		}
//	}
	convertImageToBlackAndWhite();
	for (int i = 1; i < SIZE - 1; ++i) {
		for (int j = 1; j < SIZE - 1; ++j) {
			if (image[i][j+1] == 0 && image[i+1][j] == 0 && image[i+1][j+1] == 0 && image[i][j-1] == 0 && image[i-1][j] == 0 && image[i-1][j-1] == 0 && image[i-1][j+1] == 0 && image[i+1][j-1] == 0){
				tempImage[i][j] = 255;
			} else {
				tempImage[i][j] = 0;
			}
		}
	}
	
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			image[i][j] = tempImage[i][j];
		}
	}
}

void skewHorizontally() {
    // Create New Image, Defining The Variables And Getting The Skew Degree.
    unsigned char shrinkedImage[SIZE][SIZE];
    int distance, degree ;
    double shrinkRatio, shrink;
    cout << "Please Enter The Degree Of Skew You Want. : " << endl;
    cin >> degree;

    if (degree < 45){
        // Preparing The Size Of Shrinked Image, Shrinking Ratio And The Other Variables.
        distance = SIZE*tan(degree/57.295779513);
        shrink = 256-distance;
        shrinkRatio = 256/shrink;
        double placement = SIZE-shrink;
        double movementDecrease = placement/SIZE;

        // Whiten The Shrinked Image.
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                shrinkedImage[i][j] = 255;
            }
        }

        // Shrinking The Image Using The Suitable Ratio.
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if ((j*shrinkRatio) <= 255){
                    int var = j*shrinkRatio;
                    shrinkedImage[i][j] = image[i][var];
                }
            }
        }

        // Whiten The Image To Save In It The Skew Image.
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = 255;
            }
        }

        // Skew The Image.
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < shrink; j++) {
                image[i][(int)placement+j] = shrinkedImage[i][j];
            }
            placement -= movementDecrease;
        }
    }

    else {
        // Whiten The Image As The Degree Is More Than 45.
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = 255;
            }
        }
    }
}

void skewVetically() {
    // Create New Image, Defining The Variables And Getting The Skew Degree.
    unsigned char shrinkedImage[SIZE][SIZE];
    double shrink, shrinkRatio;
    int distance = 0,degree = 0;
    cout << "Please Enter The Degree Of Skew You Want. : ";
    cin >> degree;

    if ( degree < 45) {
        // Preparing The Size Of Shrinked Image, Shrinking Ratio And The Other Variables.
        distance = 256*tan(degree/57.295779513);
        shrink = 256-distance;
        shrinkRatio = 256/shrink;
        cout << shrinkRatio << endl;
        double placement = SIZE-shrink;
        double movementDecrease = placement/SIZE;

        // Whiten The Shrinked Image.
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                shrinkedImage[i][j] = 255;
            }
        }

        // Shrinking The Image Using The Suitable Ratio.
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if ((i*shrinkRatio) <= 255){
                    int var = i*shrinkRatio;
                    shrinkedImage[i][j] = image[var][j];
                }
            }
        }

        // Whiten The Image To Save In It The Skew Image.
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = 255;
            }
        }

        // Skew The Image.
        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < shrink; i++) {
                image[(int)placement+i][j] = shrinkedImage[i][j];
            }
            placement -= movementDecrease;
        }
    }

    else {
        // Whiten The Image As The Degree Is More Than 45.
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = 255;
            }
        }
    }
}

void blurImage() {
    int avg = 0;
    for ( int i = 1 ; i < SIZE ; i++) {
        for ( int j = 1 ; j < SIZE ; j++) {
            // Getting Average of Grey color Through a Square 3*3.
            avg += image[i-1][j-1];
            avg += image[i-1][j];
            avg += image[i-1][j+1];
            avg += image[i][j-1];
            avg += image[i][j];
            avg += image[i][j+1];
            avg += image[i+1][j-1];
            avg += image[i+1][j];
            avg += image[i+1][j+1];

            // Make Sure That Average Is Not More Than 255.
            avg = avg/9;
            if ( avg > 255) {
                image[i][j] = 255;
            }
            else {
                image[i][j] = avg;
            }
        }
    }
}

void shrinkImage() {
    int shrinking, type;
    unsigned char shrinkedImage[SIZE][SIZE];

    // Get the scale of shrinking that the customer needs.
    cout << "Shrink to (1)Half, (2)Third or (3)Fourth? ";
    cin >> type;

    // Define the variable shrinking.
    if (type == 1){
        shrinking = 2;
    }
    else if (type == 2){
        shrinking = 3;
    }
    else{
        shrinking = 4;
    }

    // Shrinking process.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            shrinkedImage[i][j] = 255;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ( (i*shrinking) <= 255 && (j*shrinking) <= 255){
                shrinkedImage[i][j] = image[i*shrinking][j*shrinking];
            }
        }
    }

    // Saving edits in the image to preview it.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = shrinkedImage[i][j];
        }
    }
}
// End Filters