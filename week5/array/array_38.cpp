#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<int> intersect(vector<vector<int>> &sets) {
  vector <int> result;
  int smallSetInd = 0;
  int minSize = sets[0].size();

  for (int i = 1 ; i < sets.size() ; i++) {
    sort(sets[i].begin(), sets[i].end());

    if (minSize > sets[i].size()) {
      minSize = sets[i].size();
      smallSetInd = i;
    }
  }

  map<int,int> elementsMap;

  for (int i = 0; i < sets[smallSetInd].size(); i++) {
    if (elementsMap.find(sets[smallSetInd][i]) == elementsMap.end())
      elementsMap[ sets[smallSetInd][i] ] = 1;
    else
      elementsMap[sets[smallSetInd][i]]++;
  }

  for(auto it = elementsMap.begin(); it != elementsMap.end(); ++it) {
    int elem = it->first;
    int freq = it->second;

    bool bFound = true;

    for (int j = 0 ; j < sets.size() ; j++) {
      if (j != smallSetInd) {
	if (binary_search( sets[j].begin(), sets[j].end(), elem )) {
	 int lInd = lower_bound(sets[j].begin(), sets[j].end(), elem) - sets[j].begin();
	 int rInd = upper_bound(sets[j].begin(), sets[j].end(), elem) - sets[j].begin();

	 if ((rInd - lInd) < freq)
	     freq = rInd - lInd;
	}
	else {
	  bFound = false;
	  break;
	}
      }
    }

    if (bFound) {
      for (int k = 0; k < freq; k++)
	result.push_back(elem);
    }
  }
  return result;
}
  
int main() {
  vector<vector<int>> sets {{1, 1, 2, 2, 5},
			    {1, 1, 4, 3, 5, 9},
			    {1, 1, 2, 3, 5, 6}};

  vector<int> r = intersect(sets);
  for(auto i: r) {
    cout << i << " ";
  }
  cout << "\n";
}
