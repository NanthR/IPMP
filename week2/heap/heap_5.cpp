#include <iostream>
#include<cstring>

using namespace std; 

#define DELIM '\n' 
  
void print_last_lines(char *str, int n)  { 
    if (n <= 0) 
      return; 
  
    size_t cnt = 0;
    char *target_pos = NULL;
    target_pos = strrchr(str, DELIM); 
  
    if (target_pos == NULL) { 
        cout << "ERROR: string doesn't contain '\\n' character\n"; 
        return; 
    } 
    while (cnt < n)  { 
        while (str < target_pos && *target_pos != DELIM) 
            target_pos--; 
        if (*target_pos == DELIM) 
            target_pos--, ++cnt; 
        else
            break; 
    } 
  
    if (str < target_pos) 
        target_pos += 2; 
  
    cout << target_pos << "\n"; 
} 
  
int main() { 
    char* str1 ="1\n2\n3\n4\n5\n6\n7\n8\n9\n"
                "\n10\n11\n12\n13\n14\n15\n16\n17"
                "\n18\n19\n20\n21\n22\n23\n24\n25"; 
  
    print_last_lines(str1, 10); 
} 
