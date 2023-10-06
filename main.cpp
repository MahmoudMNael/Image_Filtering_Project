#include <bits/stdc++.h>
#include "bmplib.h"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];

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
void loadImage2();
void doSomethingForImage(string filter);
void saveImage();
void mergeImages();
void lightenAndDarkenImages();

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
		case '1':
			// use Function
			break;
		case '2':
			// use Function
			break;
		case '3':
            loadImage2();
            mergeImages();
            break;
		case '4':
			// use Function
			break;
		case '5':
			// use Function
			break;
		case '6':
            lightenAndDarkenImages();
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

void lightenAndDarkenImages() {
    char type;

    // Get the operation that customer wants.
    cout << "Please Choose If You Want It (L)ighten/(D)arken By 50%: ";
    cin >> type;

    // Process of lighten images.
    if (type == 'L' || type == 'l'){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[i][j] + (255-image[i][j])*0.5;
            }
        }
    }

    // Process of darken images.
    else if (type == 'D' || type == 'd'){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[i][j] * 0.5;
            }
        }
    }
}

