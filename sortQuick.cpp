#include <iostream>
#define N 16

using namespace std;

void swap(double &a, double &b){
	double tmp = a;
	a = b;
	b = tmp;
}

void qsort_recursive(double *arr, int left, int right){
	if (left < right){
		double pivot = arr[(left + right)/2];

		int i = left;
		int j = right;

		while (i < j){
			while (arr[i] < pivot) i++;
			while (arr[j] > pivot) j--;
			if (i < j) swap(arr[i], arr[j]);
		}

		qsort_recursive(arr, j + 1, right);
		qsort_recursive(arr, left, i - 1);
	}
}

int main(void){
	double arr[N];
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		cout << arr[i] << " ";
	}cout << endl;

	// qsort_recursive(arr, 0, N - 1);

	for (int i = 0; i < N; i++) cout << arr[i] << " ";
	cout << endl;

	return 0;
}