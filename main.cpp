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
void rotate ();
void invert ();
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
			break;
        case '2':
            invert();
			break;
		case '3':
			// use Function
			break;
		case '4':
			// use Function
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