#include <iostream>

namespace Avg {
	float Calculate(float x, float y) {
		return (x + y) / 2;
	}
}

namespace Basic {
	float Calculate(float x, float y) {
		return x + y;
	}
}
namespace Sort {
	void Quicksort() {

	}
	void Insertionsort() {

	}
	void Mergesort() {

	}
	namespace Comparision {
		void Less() {

		}
		void Greater() {

		}
	}
}
namespace {
	void InternalFunction() {

	}
}
int main() {
	//Avoid opening a namespace at a global scope
	
	InternalFunction();
	using namespace Sort::Comparision;
	Sort::Comparision::Less();
	return 0;
}