#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void calculateSpan(vector<int> &price, vector<int> &S) {
    int n = price.size();
    stack<int> st;
    st.push(0);

    S[0] = 1;

    for (int i = 1; i < n; i++) {
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();

        S[i] = (st.empty()) ? (i + 1) : (i - st.top());

        st.push(i);
    }
}

int main() {
    vector<int> price { 10, 4, 5, 90, 120, 80 };
    vector<int> S(price.size(), 0);

    calculateSpan(price, S);
    for(auto i: S)
        cout << i << " ";
    cout << "\n";
}
