// Box Stacking problem

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
 
class Box {
public:
    int length;
    int width;
    int height;
};
 
vector<int> dp(303, -1);
 
int find_max(vector<Box>& boxes, int bottom_box_index, int index) {
    if (index < 0)
        return 0;
 
    if (dp[index] != -1)
        return dp[index];
 
    int maximumHeight = 0;
 
    for (int i = index; i >= 0; i--) {
 
        if (bottom_box_index == -1 || (boxes[i].length < boxes[bottom_box_index].length && boxes[i].width < boxes[bottom_box_index].width))
 
            maximumHeight = max(maximumHeight, find_max(boxes, i, i - 1) + boxes[i].height);
    }
 
    return dp[index] = maximumHeight;
}
 
int max_stack(vector<int> &height, vector<int> &width, vector<int> &length) {
    int types = length.size();

    vector<Box> boxes;
 
    Box box;
 
    for (int i = 0; i < types; i++) {
 
        box.height = height[i];
        box.length = max(length[i], width[i]);
        box.width = min(length[i], width[i]);
 
        boxes.push_back(box);
 
        box.height = width[i];
        box.length = max(length[i], height[i]);
        box.width = min(length[i], height[i]);
 
        boxes.push_back(box);
 
        box.height = length[i];
        box.length = max(width[i], height[i]);
        box.width = min(width[i], height[i]);
 
        boxes.push_back(box);
    }
 
    sort(boxes.begin(), boxes.end(), [](Box b1, Box b2) {
        return (b1.length * b1.width)
               < (b2.length * b2.width);
    });
   
    return find_max(boxes, -1, boxes.size() - 1);
}
 
int main() {
    vector<int> length = { 4, 1, 4, 10 };
    vector<int> width = { 6, 2, 5, 12 };
    vector<int> height = { 7, 3, 6, 32 };
 
    cout << max_stack(height, length, width) << "\n";
}
