#include <iostream>
#include <fstream>

using namespace std;

void check(string &s);

int main() {
	ifstream in("./A.input");
	cin.rdbuf(in.rdbuf());

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		string s;
		cin >> n >> s;
		int idx = -1;
		for (int i = 0; i < n; i++) {
			if (s[i] == '8') {
				idx = i;
				break;
			}
		}
		if (idx != -1 && s.size() - idx >= 11) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}