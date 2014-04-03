#include <iostream>
#include <string>

using namespace std;

string longestCommonPrefix(string strs[], int n) {
	if (n == 0)
		return "";
	int index = 0;
	while (index < strs[0].length()) {
		char c = strs[0][index];
		for (int i = 1; i < n; ++i) {
			if (index >= strs[i].length() || strs[i][index] != c) {
				return strs[0].substr(0, index);
			}
		}
		index++;
	}
	return strs[0];
}

int main() {
	string strings[] = {"abcdefghij", "abcdeefsdklfjl", "abcdfjdksljflak", "abecccckd"};
	string lcp = longestCommonPrefix(strings, 4);
	if (lcp.compare("") != 0)
		cout << lcp << endl;

	return 0;
}
