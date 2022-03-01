#include <iostream>
#include <algorithm>
using namespace std;
#define MAXSIZE 10
int* my_sort(int list[], int n) {
	// 선택 정렬
	/*
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i+1; j < n; j++){
			if (list[j] < list[min]) {
				min = j;
			}
		}
		int temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}
	*/
	// 버블 정렬
	/*
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (list[i] > list[j]) {
				int temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
	*/
	// 삽입 정렬
	for (int i = 1; i < n; i++) {
		int temp = list[i];
		int j = 0;
		for (j = i - 1; j >= 0; j--) {
			if (temp < list[j]) {
				list[j + 1] = list[j];
			}
			else {
				break;
			}
		}
		list[j + 1] = temp;
	}
	return list;
}

int main() {
	int list[10] = { 23, 11, 15, 8, 17, 33, 7, 14, 19, 21 };
	int i, n = MAXSIZE;
	my_sort(list, n);
	for (i = 0; i < n; i++) {
		cout << list[i] << "\n";
	}
	return 0;
}