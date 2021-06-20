#include <iostream>
#include <string.h>
 
using namespace std;
 
char* helper(char *str, char *last_removed) {
  if (str[0] == '\0' || str[1] == '\0')
    return str;

  if (str[0] == str[1]) {
    *last_removed = str[0];
    while (str[1] && str[0] == str[1])
	str++;
    str++;
    return helper(str, last_removed);
  }

  char* rem_str = helper(str+1, last_removed);

  if (rem_str[0] && rem_str[0] == str[0]) {
    *last_removed = str[0];
    return (rem_str+1);
  }

  if (rem_str[0] == '\0' && *last_removed == str[0])
    return rem_str;

  rem_str--;
  rem_str[0] = str[0];
  return rem_str;
}
 
char *remove(char *str) {
  char last_removed = '\0';
  return helper(str, &last_removed);
}
 
int main() {
  char str1[] = "azxxxzy";
  cout << remove(str1) << "\n";
}