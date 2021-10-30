#include <iostream>
using namespace std;
int razmer(string str, char sym);

int main() {
	string s;
	char bol = 0;
	cout << razmer(s, bol);
	return 0;
}

int razmer(string str, char sym){
	cin >> str >> sym;
	int count = 0;
	for (auto c : str) {
		if (c == sym) {
			count++;
		}
	}
	return count;
}
