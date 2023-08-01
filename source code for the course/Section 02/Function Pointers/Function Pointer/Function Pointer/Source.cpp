#include <iostream>
void Print(int count, char ch) {
	using namespace std;
	for (int i = 0; i < count; ++i) {
		cout << ch;
	}
	cout << endl; 
}
void EndMessage() {
	using namespace std;
	cout << "End of program" << endl; 
}
int main() {
	//Register a handler. This handler will be invoked after main returns
	atexit(EndMessage);
	Print(5, '#');
	void(*pfn) (int, char) = Print;
	//One way to invoke function pointer
	(*pfn)(8, '@');
	//Another way to invoke function pointer
	pfn(5, '+');
	using namespace std;
	cout << "end of main" << endl;
	return 0;
}