#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <vector>
#include <map>
// #include "element_table.h"

using namespace std;

map<string, double> elementTable = {
    {"H", 1.00},
    {"He", 4.00},
    {"Li", 7.00},
    {"Be", 9.00},
    {"B", 11.00},
    {"C", 12.00},
    {"N", 14.00},
    {"O", 16.00},
    {"F", 19.00},
    {"Ne", 20.00},
    {"Na", 23.00},
    {"Mg", 24.00},
    {"Al", 27.00},
    {"Si", 28.00},
    {"P", 31.00},
    {"S", 32.00},
    {"Cl", 35.00},
    {"Ar", 40.00},
    {"K", 39.00},
    {"Ca", 40.00},
    {"Sc", 45.00},
    {"Ti", 48.00},
    {"V", 51.00},
    {"Cr", 52.00},
    {"Mn", 55.00},
    {"Fe", 56.00},
    {"Co", 59.00},
    {"Ni", 59.00},
    {"Cu", 64.00},
    {"Zn", 65.00},
    {"Ga", 70.00},
    {"Ge", 73.00},
    {"As", 75.00},
    {"Se", 79.00},
    {"Br", 80.00},
    {"Kr", 84.00},
    {"Rb", 85.00},
    {"Sr", 88.00},
    {"Y", 89.00},
    {"Zr", 91.00},
    {"Nb", 93.00},
    {"Mo", 96.00},
    {"Tc", 97.00},
    {"Ru", 101.00},
    {"Rh", 103.00},
    {"Pd", 106.00},
    {"Ag", 108.00},
    {"Cd", 112.00},
    {"In", 115.00},
    {"Sn", 119.00},
    {"Sb", 122.00},
    {"Te", 128.00},
    {"I", 127.00},
    {"Xe", 131.00},
    {"Cs", 133.00},
    {"Ba", 137.00},
    {"La", 139.00},
    {"Ce", 140.00},
    {"Pr", 141.00},
    {"Nd", 144.00},
    {"Pm", 145.00},
    {"Sm", 150.00},
    {"Eu", 152.00},
    {"Gd", 157.00},
    {"Tb", 159.00},
    {"Dy", 163.00},
    {"Ho", 165.00},
    {"Er", 167.00},
    {"Tm", 169.00},
    {"Yb", 173.00},
    {"Lu", 175.00},
    {"Hf", 178.00},
    {"Ta", 181.00},
    {"W", 184.00},
    {"Re", 186.00},
    {"Os", 190.00},
    {"Ir", 192.00},
    {"Pt", 195.00},
    {"Au", 197.00},
    {"Hg", 201.00},
    {"Tl", 204.00},
    {"Pb", 207.00},
    {"Bi", 209.00},
    {"Po", 209.00},
    {"At", 210.00},
    {"Rn", 222.00},
    {"Fr", 223.00},
    {"Ra", 226.00},
    {"Ac", 227.00},
    {"Th", 232.00},
    {"Pa", 231.00},
    {"U", 238.00},
    {"Np", 237.00},
    {"Pu", 244.00},
    {"Am", 243.00},
    {"Cm", 247.00},
    {"Bk", 247.00},
    {"Cf", 251.00},
    {"Es", 252.00},
    {"Fm", 257.00},
    {"Md", 258.00},
    {"No", 259.00},
    {"Lr", 262.00},
    {"Rf", 267.00},
    {"Db", 270.00},
    {"Sg", 269.00},
    {"Bh", 270.00},
    {"Hs", 270.00},
    {"Mt", 278.00},
    {"Ds", 281.00},
    {"Rg", 281.00},
    {"Cn", 285.00},
    {"Nh", 286.00},
    {"Fl", 289.00},
    {"Mc", 289.00},
    {"Lv", 293.00},
    {"Ts", 293.00},
    {"Og", 294.00}
};

typedef struct molecule {
	string name;
	string formula;
	double mass;
} Molecule;

stack<double> Qmass;
int swap_time;

double getMoleculeMass(const string molecules, int &idx);
double getMoleculeMass(const string molecules);
inline int string2Int(string);
void QuickSort(vector<Molecule *> &arr, const int left, const int right);
inline void swap(Molecule *(*a), Molecule *(*b));
void printArr(vector<Molecule *> arr, const int swap_time);

int main(void) {
	int groups;
	int formulas;

	cin >> groups;
	cout << groups << endl;
	for (int i = 0; i < groups; i++) {

		cin >> formulas;
		cout << formulas << endl;

		vector<Molecule *> arr(formulas);
		for (int j = 0; j < formulas; j++) {
			Molecule *ptr = new Molecule;

			cin >> ptr->name >> ptr->formula >> ptr->mass;
			if (ptr->mass == 0) ptr->mass = getMoleculeMass(ptr->formula);
			arr[j] = ptr;
		}
		swap_time = 0;
		QuickSort(arr, 0, formulas - 1);

		printArr(arr, swap_time);
	}
	return 0;
}

double getMoleculeMass(const string molecules){
	int idx = 0;
	return getMoleculeMass(molecules, idx);
}

double getMoleculeMass(const string molecules, int &idx) {
	char ch;
	double mass = 0;
	string element;
	map<string, double>::iterator iter;


	while ((ch = molecules[idx]) != '\0') {
		if (ch >= 'A' && ch <= 'Z') {
			element += ch;

			if (!(molecules[idx + 1] >= 'a' && molecules[idx + 1] <= 'z')) {
				// cout << element << ":";
				iter = elementTable.find(element);

				if (iter != elementTable.end()) {
					// cout << iter->second << endl;

					if (!(molecules[idx + 1] >= '0' && molecules[idx + 1] <= '9'))
						mass += iter->second;
					else Qmass.push(iter->second);

				}
				// else cout <<"Not found" << endl;

				element.clear();
			}
		}
		else if (ch >= 'a' && ch <= 'z') {
			element += ch;
			// cout << element << ":";
			iter = elementTable.find(element);

			if (iter != elementTable.end()) {
				// cout << iter->second << endl;

				if (!(molecules[idx + 1] >= '0' && molecules[idx + 1] <= '9'))
					mass += iter->second;
				else Qmass.push(iter->second);
			}
			// else cout <<"Not found" << endl;

			element.clear();
		}
		else if (ch >= '0' && ch <= '9') {
			element += ch;

			if (!(molecules[idx + 1] >= '0' && molecules[idx + 1] <= '9')) {
				mass += string2Int(element) * Qmass.top();
				Qmass.pop();
				element.clear();
			}
		}
		else if (ch == '(' || ch == '[') {
			idx++;
			double tmp = getMoleculeMass(molecules, idx);

			if (!(molecules[idx + 1] >= '0' && molecules[idx + 1] <= '9'))
				mass += tmp;
			else Qmass.push(tmp);
		}
		else if (ch == ')' || ch == ']') {
			return mass;
		}
		idx++;
	}

	return mass;
}

inline int string2Int(string str) {
	int ret = 0;

	for (int i = 0; i < str.size(); i++) {
		ret *= 10;
		ret += str[i] - '0';
	}

	return ret;
}

void QuickSort(vector<Molecule *> &arr, const int left, const int right){
	if (left < right) {

		Molecule *pivot = arr[left];
		int i = left;
		int j = right + 1;
		do {
			do j--; while (j > i && (arr[j])->mass > pivot->mass);
			do i++; while (i < j && (arr[i])->mass <= pivot->mass);
			if (i < j) {
				swap(&(arr[i]), &(arr[j]));
				swap_time++;
			}
		} while (i < j);
		if (pivot->mass > arr[j]->mass){
 			swap(&pivot, &(arr[j]));
 			swap_time++;
		}
		QuickSort(arr, left, j - 1);
		QuickSort(arr, j + 1, right);
	}
}

void swap(Molecule *(*a), Molecule *(*b)){
	Molecule *tmp = *a;
	*a = *b;
	*b = tmp;
	cout << "In swap: " << (*a)->mass << " " << (*b)->mass << endl;
}

void printArr(vector<Molecule *> arr, const int swap_time){
	for (int i = 0; i < arr.size(); i++){
		(arr[i]->name).append(40 - (arr[i]->name).length(), ' ');
		cout << arr[i]->name;

		(arr[i]->formula).append(25 - (arr[i]->formula).length(), ' ');
		cout << arr[i]->formula;

		printf("%10.2f\n", arr[i]->mass);
	}
	cout << swap_time << " swaps during qsort\n";
}