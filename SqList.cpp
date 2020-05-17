#include<iostream>
#define InitSize 100

using namespace std;
const int Maxsize = 50;
typedef struct {
	int data[Maxsize];
	int length;
}Sqlist;

typedef struct {
	int* data;
	int MaxSizee, length;
}SeqList;

bool ListInsert(Sqlist& L, int i, int e) {
	if (i<1 || i>L.length + 1) return false;
	if (L.length >= Maxsize) return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return true;
}

bool ListDelete(Sqlist& L, int i, int& e) {
	if (i<1 || i>L.length + 1) return false;
	if (L.length >= Maxsize) return false;
	e = L.data[i-1];
	for (int j = i; j <= L.length; j++)
		L.data[j-1] = L.data[j];
	L.length--;
	return true;
}

int LocateElem(Sqlist& L, int e) {
	int i;
	for (i = 0; i <= L.length; i++)
		if (L.data[i] == e)
			return i+1;
	return 0;
}

int MinDelete(Sqlist& L, int& e) {
	if (L.data[0]<0) {
		cout << "Ë³Ðò±íÎª¿Õ";
		return 0;
	}
	int i,s = 0,temp = L.data[0];
	for (i = 1; i < L.length; ++i) {
		if (L.data[i] < temp) {
			temp = L.data[i];
			s = i;
		}
	}
	e = temp;
	for (int j = s; j<L.length; ++j) {
		L.data[j] = L.data[j + 1];
	}
	--L.length;
	return true;
}

void RevList(Sqlist& L) {
	int temp;
	for (int i = 0; i < L.length / 2; i++)
	{
		temp = L.data[i];
		L.data[i] = L.data[L.length -i - 1];
		L.data[L.length - i - 1] = temp;
	}
}

int main() {
	int e;
	Sqlist test;
	test.length = 5;
	//test.data[0] = 20;
	//test.data[1] = 1;
	//test.data[2] = 2;
	//test.data[3] = 3;
	//test.data[4] = 4;
	MinDelete(test, e);
	cout << e;
}