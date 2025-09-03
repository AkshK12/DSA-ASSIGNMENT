#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nearestSmallerToLeft(vector<int>& A) {
    stack<int> st;
    vector<int> res;

    for (int i = 0; i < A.size(); i++) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        if (st.empty())
            res.push_back(-1);
        else
            res.push_back(st.top());

        st.push(A[i]);
    }
    return res;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> result = nearestSmallerToLeft(A);

    for (int x : result)
        cout << x << " ";
    return 0;
}
