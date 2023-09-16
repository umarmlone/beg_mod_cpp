#include <stdio.h>
#include <stdlib.h>
#include <iostream>
void Malloc() {
	//int *p = (int*)calloc(5, sizeof(int));
	int *p = (int*)malloc(5 * sizeof(int));
	if (p == NULL) {
		printf("Failed to allocate memory\n");
		return;
	}
	*p = 5;
	printf("%d", *p);
	//free(p);
	p = NULL;
	//free(p);
}

void New() {
	int *p = new int(5);
	*p = 6;
	std::cout << *p << std::endl;
	delete p;
	p = nullptr;
}
void NewArrays() {
	int *p = new int[5];
	for (int i = 0; i < 5; ++i) {
		p[i] = i;
	}
	delete[]p;
}
void Strings() {
	char *p = new char[4];
	strcpy_s(p, 4, "C++");
	std::cout << p << std::endl;
	delete[]p;
}
void TwoD() {
	int *p1 = new int[3];
	int *p2 = new int[3];

	int **pData = new int *[2];
	pData[0] = p1;
	pData[1] = p2;

	pData[0][1] = 2;

	delete[]p1;//delete pData[0]
	delete[]p2;

	delete[] pData;
}
int main() {
	int data[2][3] = {
		1,2,3,
		4,5,6
	}; //1,2,3,4,5,6
	   //data[0][1]
	Strings();



	return 0;
}