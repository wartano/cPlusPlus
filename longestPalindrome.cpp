#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*

To improve over the brute force solution from a DP approach, first think how we can avoid unnecessary re-computation in validating palindromes. Consider the case “ababa”. If we already knew that “bab” is a palindrome, it is obvious that “ababa” must be a palindrome since the two left and right end letters are the same.


Stated more formally below:

Define P[ i, j ] ← true if the substring Si … Sj is a palindrome, otherwise false.
Therefore,

P[ i, j ] ← ( P[ i+1, j-1 ] and Si = Sj )
The base cases are:

P[ i, i ] ← true
P[ i, i+1 ] ← ( Si = Si+1 )
This yields a straight forward DP solution, which we first initialize the one and two letters palindromes, and work our way up finding all three letters palindromes, and so on… 

This gives us a run time complexity of O(N2) and uses O(N2) space to store the table. 

*/

vector<string> longestPalindrome(string s) {
  int n = s.length();
  int maxLen = 1;
  bool table[1000][1000] = {false};
  vector<int> indexes;
  vector<string> strs;
  bool isCleared = false;

  for (int i = 0; i < n; ++i) {
    table[i][i] = true;
    indexes.push_back(i);
  }

  for (int i = 0; i < n-1; ++i) {
    if (s[i] == s[i+1]) {
      if (!isCleared) {
	indexes.clear();
	isCleared = true;
      }
      table[i][i+1] = true;
      maxLen = 2;
      indexes.push_back(i);
    }
  }

  for (int len = 3; len <= n; ++len) {
    isCleared = false;
    for (int i = 0; i < n-len+1; ++i) { //make sure j is still a part of the string which means j must be less than n
      int j = i+len-1;
      if (s[i] == s[j] && table[i+1][j-1]) {
	if (!isCleared) {
		indexes.clear();
		isCleared = true;
	}
        table[i][j] = true;
        maxLen = len;
        indexes.push_back(i);
      }
    }
  }
  
  for (vector<int>::iterator it = indexes.begin(); it != indexes.end(); ++it)
    strs.push_back(s.substr(*it, maxLen));
  return strs;
}

int main() {
	vector<string> strs = longestPalindrome("aatttaaddeeeabcdcba");
	for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it)
		cout << *it << endl;

	return 0;
}
