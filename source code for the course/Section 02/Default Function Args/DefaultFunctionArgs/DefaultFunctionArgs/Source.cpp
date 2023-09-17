#include <iostream>
void CreateWindow(const char * title, int x, int y, int width, int height);


void CreateWindow(const char * title, int x = -1, int y = -1, int width = -1, int height = -1) {
	using namespace std;
	cout << "Title : " << title << endl;
	cout << "x : " << x << endl;
	cout << "y : " << y << endl;
	cout << "Width : " << width << endl;
	cout << "Height : " << height << endl;
}
int main() {
	/*
	Not all arguments are necessary. If you specify arguments,
	they should be specified from right to left.
	*/
	CreateWindow("Notepad", 100, 200);
	return 0;
}