#include<iostream>
#include<vector>

using namespace std;

int min(int x, int y, int z);
 
int min_cost(vector<vector<int>> &cost, int m, int n) {
  vector<vector<int>> tc(cost.size(), vector<int>(cost[0].size(), 0)); 

  tc[0][0] = cost[0][0];

  for (int i = 1; i <= m; i++)
    tc[i][0] = tc[i - 1][0] + cost[i][0];

  for (int j = 1; j <= n; j++)
    tc[0][j] = tc[0][j - 1] + cost[0][j];

  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      tc[i][j] = min(tc[i - 1][j - 1], tc[i - 1][j], tc[i][j - 1]) + cost[i][j];

  return tc[m][n];
}
 
int min(int x, int y, int z) {
  if (x < y)
    return (x < z)? x : z;
  else
    return (y < z)? y : z;
}
 
int main() {
  vector<vector<int>> cost { {1, 2, 3},
		    {4, 8, 2},
		    {1, 5, 3} };
  cout << min_cost(cost, 2, 2) << "\n";
}
