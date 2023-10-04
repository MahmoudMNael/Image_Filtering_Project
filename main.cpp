#include <bits/stdc++.h>
#include "bmplib.h"

using namespace std;
unsigned char image[SIZE][SIZE];

//enum Filters {
//	BW_IMAGE = 1,
//	INVERT_IMAGE,
//	MERGE_IMAGE,
//	FLIP_IMAGE,
//	ROTATE_IMAGE,
//	DARKEN_OR_LIGHTEN_IMAGE
//};

string inputFilterNumber();
void loadImage();
void doSomethingForImage(string filter);
void saveImage();

// Filters
void convertImageToBlackAndWhite();
void flipImage();
void flipVertical();
void flipHorizontal();
// End Filters

int main() {
	string filterNumber = inputFilterNumber();
    loadImage();
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
			// use Function
			break;
		case '3':
			// use Function
			break;
		case '4':
			// use Function
			flipImage();
			break;
		case '5':
			// use Function
			break;
		case '6':
			// use Function
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
	int pixelSum = 0;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			pixelSum += image[i][j];
		}
	}
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
		if (enteredFlipNumber[0] >= '1' && enteredFlipNumber[0] <= '6') {
			break;
		} else {
			cout << "Enter a valid number from 1~6: " << endl;
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