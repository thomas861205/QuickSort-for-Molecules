#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <vector>
#include <iomanip>
#include "element_table.h"

using namespace std;

typedef struct molecule {
	string name;
	string formula;
	double mass;
} Molecule;

stack<double> Qmass;

double getMoleculeMass(const string molecules, int &idx);
double getMoleculeMass(const string molecules);
inline int string2Int(string);
void printArr(vector<Molecule *> arr, const int swap_time);

int main(void) {
	int groups;
	int molecules;

	cin >> groups;
	cout << groups << endl;
	for (int i = 0; i < groups; i++) {
		int swap_time = 0;

		cin >> molecules;
		cout << molecules << endl;

		vector<Molecule *> arr(molecules);
		for (int j = 0; j < molecules; j++) {
			Molecule *ptr = new Molecule;

			cin >> ptr->name >> ptr->formula >> ptr->mass;
			if (ptr->mass == 0) ptr->mass = getMoleculeMass(ptr->formula);
			arr[j] = ptr;
		}
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

void printArr(vector<Molecule *> arr, const int swap_time){
	for (int i = 0; i < arr.size(); i++){
		(arr[i]->name).append(40 - (arr[i]->name).length(), ' ');
		cout << arr[i]->name;

		(arr[i]->formula).append(25 - (arr[i]->formula).length(), ' ');
		cout << arr[i]->formula;

		// cout << arr[i]->mass << endl;
		printf("%10.2f\n", arr[i]->mass);
	}
	cout << swap_time << " swaps during qsort\n";
}