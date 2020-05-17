#include<iostream>

using namespace std;

int fib_rec(int n);
int fib_no_rec(int n);
//int main() {
//	int x = fib_rec(5);
//	cout << x;
//	return 0;
//}

int fib_rec(int n) {
	if (n <= 1) return 1;
	return fib_rec(n - 1) + fib_rec(n - 2);
}

int fib_no_rec(int n) {
	if (n <= 1) return 1;
	int a = 0, b = 1, c = 1;
	while (n >= 2) {
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}