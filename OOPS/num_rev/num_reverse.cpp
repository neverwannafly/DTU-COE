#include <iostream>

int reverse(int num) {
	int a=0, mul=10;
	while(num!=0) {
		a = a*mul +  num%10;
		num /= 10;
	}
	return a;
}

int main() {

	int num;	
	while(std::cin >> num) {
		std::cout << reverse(num) << "\n";
	}
	return 0;
}
