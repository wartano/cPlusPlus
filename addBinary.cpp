#include <iostream>
#include <string>
using namespace std;

string addBinary (const string &a, const string &b) {
	string res;
	int carry = 0;
	int sum = 0;
	int i = a.size() - 1, j = b.size() - 1;
	int a_val = 0, b_val = 0;
	while (i >= 0 || j >= 0 || carry) {
		a_val = (i >= 0 ? a[i] - '0' : 0);
		b_val = (j >= 0 ? b[j] - '0' : 0);
		sum = a_val + b_val + carry;
		carry = sum / 2;
		sum %= 2;
		res.insert(0, 1, sum + '0'); //Inserts 1 consecutive copies of character sum + '0' before position 0
		if (i >= 0)
			--i;
		if (j >= 0)
			--j;
	}
	return res;
}

int main() {
	string binary1 = "10001011", binary2 = "11100111100001";
	string result = addBinary(binary1, binary2);
	cout << binary1 << " + " << binary2 << " is " << result << endl;

	return 0;
}
