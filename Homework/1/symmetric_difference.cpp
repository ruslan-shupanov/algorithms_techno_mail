#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int x;
    vector<int> A, B, Res;
    cin >> x;
    while (x != 0) {
        A.push_back(x);
        cin >> x;
    }
    cin >> x;
    while (x != 0) {
        B.push_back(x);
        cin >> x;
    }
    sort (A.begin(), A.end());
    sort (B.begin(), B.end());
    auto it_A = A.begin(), it_B=B.begin();
    while (it_A != A.end() && it_B != B.end()) {
        if (*it_A == *it_B) {
            it_A++;
            it_B++;
        } else if (*it_A < *it_B) {
            Res.push_back(*it_A);
            it_A++;
        } else {
            Res.push_back(*it_B);
            it_B++;
        }
    }
    if (it_A != A.end() && it_B == B.end())
        Res.insert(Res.end(), it_A, A.end());
    else if (it_A == A.end() && it_B != B.end())
        Res.insert(Res.end(), it_B, B.end());
    for (auto it : Res)
        cout << it << " ";
    return 0;
}
