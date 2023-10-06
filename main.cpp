#include <bits/stdc++.h>
#include "bmplib.h"

using namespace std;
unsigned char image[SIZE][SIZE];

string inputFilterNumber();
void loadImage();
void doSomethingForImage(string filter);
void saveImage();

// Filters
void rotate ();
void invert ();
void convertImageToBlackAndWhite();
void flipImage();
void flipVertical();
void flipHorizontal();
// End Filters

int main() {
    loadImage();
	string filterNumber = inputFilterNumber();
	doSomethingForImage(filterNumber);
	saveImage();
    return 0;
}

string inputFilterNumber(){
	string filterNumber;
	cout << "1. Black and White\n" << "2. Invert Image\n" << "3. Merge Images\n" << "4. Flip Image\n" << "5. Rotate Image\n" << "6. Darken or Lighten Image\n" << endl;
	cout << "Enter the number of the filter you desire: " << endl;
	while (cin >> filterNumber) {
		if (filterNumber[0] >= '1' && filterNumber[0] <= '6') {
			return filterNumber;
		} else {
			cout << "Enter a valid number from 1~6: " << endl;
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

void doSomethingForImage(string filter) {
	switch (filter[0]) {
		case '1':
			// use Function
			convertImageToBlackAndWhite();
			break;
        case '2':
            invert();
			break;
		case '3':
			// use Function
			break;
		case '4':
			// use Function
			flipImage();
			break;
		case '5':{
                    rotate();
			break;}
		case '6':
			// use Function
			break;
	}
}
void invert(){
for (int i=0;i<255;i++){
    for(int j=0 ;j<255;j++) {

        image[i][j] = 255 - image[i][j];
    }
}
}
void rotate () {
    int Degree;
    cout << "enter the degree: ";
    cin >> Degree;
for(int k=0;k<(Degree/90);k++) {
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
	int pixelAvg = pixelSum / 65025;
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
// End Filters