#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <vector>
#include <map>

using namespace std;

typedef struct molecule {
	string name;
	string formula;
	double mass;
} Molecule;

map<string, double> elementTable;
stack<double> Qmass;
int swap_time;

void initElementTable(void);
double getMoleculeMass(const string molecules, int &idx);
double getMoleculeMass(const string molecules);
inline int string2Int(string str);
void QuickSort(vector<Molecule *> &arr, const int left, const int right);
inline void swap(Molecule * (*a), Molecule * (*b));
void printArr(vector<Molecule *> arr, const int swap_time);

int main(void) {
	initElementTable();
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

double getMoleculeMass(const string molecules) {
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
				iter = elementTable.find(element);

				if (iter != elementTable.end()) {

					if (!(molecules[idx + 1] >= '0' && molecules[idx + 1] <= '9'))
						mass += iter->second;
					else Qmass.push(iter->second);

				}
				element.clear();
			}
		}
		else if (ch >= 'a' && ch <= 'z') {
			element += ch;
			iter = elementTable.find(element);

			if (iter != elementTable.end()) {

				if (!(molecules[idx + 1] >= '0' && molecules[idx + 1] <= '9'))
					mass += iter->second;
				else Qmass.push(iter->second);
			}

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

void QuickSort(vector<Molecule *> &arr, const int left, const int right) {
	if (left < right) {

		Molecule *(&pivot) = arr[left];
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
		if (pivot->mass > arr[j]->mass) {
			swap(pivot, (arr[j]));
			swap_time++;
		}
		QuickSort(arr, left, j - 1);
		QuickSort(arr, j + 1, right);
	}
}

void swap(Molecule * (*a), Molecule * (*b)) {
	Molecule *tmp = *a;
	*a = *b;
	*b = tmp;
}

void printArr(vector<Molecule *> arr, const int swap_time) {
	for (int i = 0; i < arr.size(); i++) {
		(arr[i]->name).append(40 - (arr[i]->name).length(), ' ');
		cout << arr[i]->name;

		(arr[i]->formula).append(25 - (arr[i]->formula).length(), ' ');
		cout << arr[i]->formula;

		printf("%10.2f\n", arr[i]->mass);
	}
	cout << swap_time << " swaps during qsort\n";
}

void initElementTable(void) {
	elementTable["H"] = 1.00;
	elementTable["He"] = 4.00;
	elementTable["Li"] = 7.00;
	elementTable["Be"] = 9.00;
	elementTable["B"] = 11.00;
	elementTable["C"] = 12.00;
	elementTable["N"] = 14.00;
	elementTable["O"] = 16.00;
	elementTable["F"] = 19.00;
	elementTable["Ne"] = 20.00;
	elementTable["Na"] = 23.00;
	elementTable["Mg"] = 24.00;
	elementTable["Al"] = 27.00;
	elementTable["Si"] = 28.00;
	elementTable["P"] = 31.00;
	elementTable["S"] = 32.00;
	elementTable["Cl"] = 35.00;
	elementTable["Ar"] = 40.00;
	elementTable["K"] = 39.00;
	elementTable["Ca"] = 40.00;
	elementTable["Sc"] = 45.00;
	elementTable["Ti"] = 48.00;
	elementTable["V"] = 51.00;
	elementTable["Cr"] = 52.00;
	elementTable["Mn"] = 55.00;
	elementTable["Fe"] = 56.00;
	elementTable["Co"] = 59.00;
	elementTable["Ni"] = 59.00;
	elementTable["Cu"] = 64.00;
	elementTable["Zn"] = 65.00;
	elementTable["Ga"] = 70.00;
	elementTable["Ge"] = 73.00;
	elementTable["As"] = 75.00;
	elementTable["Se"] = 79.00;
	elementTable["Br"] = 80.00;
	elementTable["Kr"] = 84.00;
	elementTable["Rb"] = 85.00;
	elementTable["Sr"] = 88.00;
	elementTable["Y"] = 89.00;
	elementTable["Zr"] = 91.00;
	elementTable["Nb"] = 93.00;
	elementTable["Mo"] = 96.00;
	elementTable["Tc"] = 97.00;
	elementTable["Ru"] = 101.00;
	elementTable["Rh"] = 103.00;
	elementTable["Pd"] = 106.00;
	elementTable["Ag"] = 108.00;
	elementTable["Cd"] = 112.00;
	elementTable["In"] = 115.00;
	elementTable["Sn"] = 119.00;
	elementTable["Sb"] = 122.00;
	elementTable["Te"] = 128.00;
	elementTable["I"] = 127.00;
	elementTable["Xe"] = 131.00;
	elementTable["Cs"] = 133.00;
	elementTable["Ba"] = 137.00;
	elementTable["La"] = 139.00;
	elementTable["Ce"] = 140.00;
	elementTable["Pr"] = 141.00;
	elementTable["Nd"] = 144.00;
	elementTable["Pm"] = 145.00;
	elementTable["Sm"] = 150.00;
	elementTable["Eu"] = 152.00;
	elementTable["Gd"] = 157.00;
	elementTable["Tb"] = 159.00;
	elementTable["Dy"] = 163.00;
	elementTable["Ho"] = 165.00;
	elementTable["Er"] = 167.00;
	elementTable["Tm"] = 169.00;
	elementTable["Yb"] = 173.00;
	elementTable["Lu"] = 175.00;
	elementTable["Hf"] = 178.00;
	elementTable["Ta"] = 181.00;
	elementTable["W"] = 184.00;
	elementTable["Re"] = 186.00;
	elementTable["Os"] = 190.00;
	elementTable["Ir"] = 192.00;
	elementTable["Pt"] = 195.00;
	elementTable["Au"] = 197.00;
	elementTable["Hg"] = 201.00;
	elementTable["Tl"] = 204.00;
	elementTable["Pb"] = 207.00;
	elementTable["Bi"] = 209.00;
	elementTable["Po"] = 209.00;
	elementTable["At"] = 210.00;
	elementTable["Rn"] = 222.00;
	elementTable["Fr"] = 223.00;
	elementTable["Ra"] = 226.00;
	elementTable["Ac"] = 227.00;
	elementTable["Th"] = 232.00;
	elementTable["Pa"] = 231.00;
	elementTable["U"] = 238.00;
	elementTable["Np"] = 237.00;
	elementTable["Pu"] = 244.00;
	elementTable["Am"] = 243.00;
	elementTable["Cm"] = 247.00;
	elementTable["Bk"] = 247.00;
	elementTable["Cf"] = 251.00;
	elementTable["Es"] = 252.00;
	elementTable["Fm"] = 257.00;
	elementTable["Md"] = 258.00;
	elementTable["No"] = 259.00;
	elementTable["Lr"] = 262.00;
	elementTable["Rf"] = 267.00;
	elementTable["Db"] = 270.00;
	elementTable["Sg"] = 269.00;
	elementTable["Bh"] = 270.00;
	elementTable["Hs"] = 270.00;
	elementTable["Mt"] = 278.00;
	elementTable["Ds"] = 281.00;
	elementTable["Rg"] = 281.00;
	elementTable["Cn"] = 285.00;
	elementTable["Nh"] = 286.00;
	elementTable["Fl"] = 289.00;
	elementTable["Mc"] = 289.00;
	elementTable["Lv"] = 293.00;
	elementTable["Ts"] = 293.00;
	elementTable["Og"] = 294.00;
}