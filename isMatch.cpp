#include <iostream>
#include <cassert>

using namespace std;

bool isMatch(const char *s, const char *p) {
  assert(s && p);
  if (*p == '\0') return *s == '\0';
 
  assert(*p != '*');
  // next char is not '*': must match current character
  if (*(p+1) != '*') {
    return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
  }
  // next char is '*'
  while ((*p == *s) || (*p == '.' && *s != '\0')) {
    if (isMatch(s, p+2)) return true;
    s++;
  }
  //*p != *s, lets * match empty
  return isMatch(s, p+2);
}

void print_result(bool match) {
	if (match)
                cout << "matched" << endl;
        else
                cout << "not matched" << endl;
}


int main() {
	print_result(isMatch("aa","a"));
	print_result(isMatch("aa","aa"));
	print_result(isMatch("aaa","aa"));
	print_result(isMatch("aa", "a*"));
	print_result(isMatch("aa", ".*"));
	print_result(isMatch("ab", ".*"));
	print_result(isMatch("aab", "c*a*b"));

	return 0;
}
