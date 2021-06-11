#include<iostream>
#include<vector>

bool canMatch(char a, char b) {
  return (a == b || b == '.');
}

bool isMatch(const char *s, const char *p) {
  int lS = strlen(s);
  int lP = strlen(p);
  vector<vector<bool> > F(lS + 1, vector<bool>(lP + 1));
  F[0][0] = true;
  for (int i = 0; i <= lS; i++) {
    for (int j = 1; j <= lP; j++) {
      if(i>0) {
	if (F[i-1][j-1] && canMatch(s[i-1], p[j-1])) {
	  F[i][j] = true;
	  continue;
	}
      }
      if (i > 0 && j > 1) {
	if (F[i-1][j] && canMatch(s[i-1], p[j-2]) && p[j-1] == '*') {
	  F[i][j] = true;
	  continue;
	}
      }
      if (j > 1) {
	F[i][j] = true;
	continue;
      }
    }
  }
  return F[lS][lP];
}
