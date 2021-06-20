#include<iostream>
#include<vector>

using namespace std;
 
 
void printMaxSubSquare(vector<vector<int>> &M) {
  int i,j;
  vector<vector<int>> S (M.size(), vector<int>(M[0].size(), 0));
  int max_of_s, max_i, max_j;
  int r = M.size();
  int c = M[0].size();
   
  for(i = 0; i < r; i++)
    S[i][0] = M[i][0];
   
  for(j = 0; j < c; j++)
    S[0][j] = M[0][j];
       
  for(i = 1; i < r; i++) {
    for(j = 1; j < c; j++) {
      if(M[i][j] == 1)
	S[i][j] = min(S[i][j-1],min(S[i-1][j], S[i-1][j-1])) + 1;
      else
	S[i][j] = 0;
    }
  }
   
  max_of_s = S[0][0]; max_i = 0; max_j = 0;
  for(i = 0; i < r; i++) {
    for(j = 0; j < c; j++) {
      if(max_of_s < S[i][j]) {
	max_of_s = S[i][j];
	max_i = i;
	max_j = j;
      }
    }            
  }

  for(i = max_i; i > max_i - max_of_s; i--) {
    for(j = max_j; j > max_j - max_of_s; j--) {
      cout << M[i][j] << " ";
    }
    cout << "\n";
  }
}
 
 
int main() {
    vector<vector<int>> M {{0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};
                     
    printMaxSubSquare(M);
}
