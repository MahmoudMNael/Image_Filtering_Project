// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name: main.cpp
// Last Modification Date: 07/10/2023
// Authors: [
//              {
//					name: "Mahmoud Mohammed Nael",
//                  id: 20220322,
//					group: A,
//              },
//              {
//					name: "Mazen Mohammed Nayef",
//                  id: 20220268,
//					group: A,
//              },
//              {
//					name: "Mohammed Ahmed Fathy",
//                  id: N/A,
//					group: A,
//              },
//          ]
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
void dividedImage();

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
void shuffleImage();
// End Filters

int main() {
	cout << "Ahlan ya user ya habibi ;)" << endl;
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
	cout << "1. Black and White\n" << "2. Invert Image\n" << "3. Merge Images\n" << "4. Flip Image\n" << "5. Rotate Image\n" << "6. Darken or Lighten Image\n"<<"8 .Enlarge image\n"<<"b .Suffle Image\n" << "s. Save the image to a file\n" << "0. Exit\n" << endl;
	cout << "Enter the number of the filter you desire or 0 to exit: " << endl;
	while (cin >> filterNumber) {
		if ((filterNumber[0] >= '0' && filterNumber[0] <= '8') || filterNumber[0] == 's'||filterNumber[0]=='b') {
			return filterNumber;
		} else {
			cout << "Enter a valid number from 0~6 or s: " << endl;
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
		case '5':{
			rotateImage();
			break;}
		case '6':
            lightenOrDarkenImage();
			break;
        case '7':
            break;
        case '8':
            enlargeImage();
            break;
        case'b':
            dividedImage();
            shuffleImage();
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
	
	// Add 2 photos to each other by taking the average of gray level of each corresponding pixel.
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
void shuffleImage(){
    int qrt;
    cout<<"enter the order of quarter you need: \n";
    for(int k=0;k<4;k++){
        cin>>qrt;
        if(qrt<=0&&qrt>4){
            cout<<"enter the valid no between 1 to 4 : \n";
        }
        if (k==0){
            for(int i=0;i<128;i++){
                for(int j=0;j<128;j++){
                    if(qrt==1){
                        image[i][j]=imageq1[i][j];
                    }else if (qrt==2){
                        image[i][j]=imageq2[i][j];
                    }else if (qrt==3){
                        image[i][j]=imageq3[i][j];
                    }else if (qrt==4){
                        image[i][j]=imageq4[i][j];
                    }
                }
            }
        }else if (k==1){
            for(int i=0;i<128;i++){
                for(int j=128,x=0;j<256;j++,x++){
                    if(qrt==1){
                        image[i][j]=imageq1[i][x];
                    }else if (qrt==2){
                        image[i][j]=imageq2[i][x];
                    }else if (qrt==3){
                        image[i][j]=imageq3[i][x];
                    }else if (qrt==4){
                        image[i][j]=imageq4[i][x];
                    }
                }
            }
        }else if(k==2){
            for(int i=128,y=0;i<256;i++,y++){
                for(int j=0;j<128;j++){
                    if(qrt==1){
                        image[i][j]=imageq1[y][j];
                    }else if (qrt==2){
                        image[i][j]=imageq2[y][j];
                    }else if (qrt==3){
                        image[i][j]=imageq3[y][j];
                    }else if (qrt==4){
                        image[i][j]=imageq4[y][j];
                    }
                }
            }
        }else if (k==3){
            for(int i=128,y=0;i<256;i++,y++){
                for(int j=128,x=0;j<256;j++,x++){
                    if(qrt==1){
                        image[i][j]=imageq1[y][x];
                    }else if (qrt==2){
                        image[i][j]=imageq2[y][x];
                    }else if (qrt==3){
                        image[i][j]=imageq3[y][x];
                    }else if (qrt==4){
                        image[i][j]=imageq4[y][x];
                    }
                }
            }
        }
    }

}
// End Filters

