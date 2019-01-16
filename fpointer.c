#include <stdio.h>


typedef unsigned char bool;

int * filter(int * arrayToBeFiltered, int size, bool (*keep)(int item)) {
	int * filteredArray;
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (keep(arrayToBeFiltered[i])) {
			filteredArray[j] = arrayToBeFiltered[i];
			j++;
		}
	}
	return filteredArray;
}

bool keepEven(int number) {
	return number % 2 == 0;
}

int main() {
	int myArray[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int myArraySize = sizeof(myArray) / sizeof(int);
	bool(*keepEvenPtr)(int) = &keepEven;
	int * filteredArray = filter(myArray, myArraySize, keepEvenPtr);
	for (int i = 0; i < 5; i++) {
		printf("element %d is: %d\n",i,filteredArray[i]);
	}
}