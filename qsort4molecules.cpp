#include <iostream>
#include <string>
#include <stack>
#include "element_table.h"

using namespace std;

stack<double> Qmass;

double getMoleculeMass(const string molecules, int &idx);
inline int string2Int(string);

int main(void){
	int n;
	string molecules;

	cin >> n;
	while (n--){
		int idx = 0;
		cin >> molecules;
		cout << getMoleculeMass(molecules, idx) << endl;
	}
	return 0;
}

double getMoleculeMass(const string molecules, int &idx){
	char ch;
	double mass = 0;
	string element;
	map<string, double>::iterator iter;


	while ((ch = molecules[idx]) != '\0'){
		if (ch >= 'A' && ch <= 'Z'){
			element += ch;

			if (!(molecules[idx + 1] >= 'a' && molecules[idx + 1] <= 'z')){
				cout << element << ":";
				iter = elementTable.find(element);

				if (iter != elementTable.end()){
					cout << iter->second << endl;

					if (!(molecules[idx + 1] >= '0' && molecules[idx + 1] <= '9'))
						mass += iter->second;
					else Qmass.push(iter->second);

				}
				else cout <<"Not found" << endl;

				element.clear();
			}
		}
		else if (ch >= 'a' && ch <= 'z'){
			element += ch;
			cout << element << ":";
			iter = elementTable.find(element);

			if (iter != elementTable.end()){
				cout << iter->second << endl;

				if (!(molecules[idx + 1] >= '0' && molecules[idx + 1] <= '9'))
					mass += iter->second;
				else Qmass.push(iter->second);
			}	
			else cout <<"Not found" << endl;

			element.clear();
		}
		else if (ch >= '0' && ch <= '9'){
			element += ch;

			if (!(molecules[idx + 1] >= '0' && molecules[idx + 1] <= '9')){
				mass += string2Int(element) * Qmass.top();
				Qmass.pop();
				element.clear();
			}
		}
		else if (ch == '(' || ch == '['){
			idx++;
			double tmp = getMoleculeMass(molecules, idx);

			if (!(molecules[idx + 1] >= '0' && molecules[idx + 1] <= '9'))
				mass += tmp;
			else Qmass.push(tmp);
		}
		else if (ch == ')' || ch == ']'){
			return mass;
		}
		idx++;
	}

	return mass;
}

inline int string2Int(string str){
	int ret = 0;

	for (int i = 0; i < str.size(); i++){
		ret *= 10;
		ret += str[i] - '0';
	}

	return ret;
}