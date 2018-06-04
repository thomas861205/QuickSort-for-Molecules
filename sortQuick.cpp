#include <iostream>
#define N 10

using namespace std;

int swap_time;

void swap(double &a, double &b){
	double tmp = a;
	a = b;
	b = tmp;
}

void qsort_middle(double *arr, int left, int right){
	if (left < right){
		double pivot = arr[(left + right)/2];

		int i = left;
		int j = right;

		while (i < j){
			while (arr[i] < pivot) i++;
			while (arr[j] > pivot) j--;
			if (i < j){
				swap(arr[i], arr[j]);
				swap_time++;
			}
		}

		qsort_middle(arr, j + 1, right);
		qsort_middle(arr, left, i - 1);
	}
}

void qsort_left(double *arr, int left, int right){
	if (left < right){
		double &pivot = arr[left];

		int i = left + 1;
		int j = right;

		while (i < j){
			while (arr[i] <= pivot && i < j) i++;
			while (arr[j] > pivot && j > i) j--;
			if (i < j){
				swap(arr[i], arr[j]);
				swap_time++;
			}
		} // by the time i should == j

		if (arr[j] < pivot){
			swap(pivot, arr[j]);
			swap_time++;
		}

		qsort_left(arr, left, i - 1);
		qsort_left(arr, j + 1, right);
	}
}

void QuickSort(double *a, const int left, const int right)
{ // sort a[left..right]
	if (left < right) {
		double &pivot = a[left];
		int i = left;
		int j = right + 1;
		do {
			do j--; while (a[j] > pivot); //find a key ≤pivot
			do { i++; //find a key >pivot
			} while (i < j && a[i] <= pivot);
			if (i < j) {
				swap(a[i], a[j]);
				swap_time++;
			}
		} while (i < j);
		if (left != j){
			swap(pivot, a[j]); //place the pivot between 2 lists
			swap_time++;
		}
		QuickSort(a, left, j - 1); // recursion
		QuickSort(a, j + 1, right); // recursion
	}
}

int main(void){
	double arr[N];
	swap_time = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		cout << arr[i] << " ";
	}cout << endl;

	int func;
	cin >> func;
	if (func == 1) qsort_middle(arr, 0, N - 1);
	else if (func == 2) qsort_left(arr, 0, N - 1);
	else if (func == 3) QuickSort(arr, 0, N - 1);
	cout << swap_time << endl;

	for (int i = 0; i < N; i++) cout << arr[i] << " ";
	cout << endl;

	return 0;
}