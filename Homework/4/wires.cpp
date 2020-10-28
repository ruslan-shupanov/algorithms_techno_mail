#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int m(vector<int> &vec, int k) {
    for (int i = vec[0]; i > 0; i--) {
        int tmp = 0;
        for (size_t j = 0; j < vec.size(); j++) {
            tmp += vec[j] / i;
            if (tmp >= k)
                return i;
            if (vec[j] < i)
                break;
        }
    }
    return 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    for (auto &i : v) {
        cin >> i;
    }
    sort(v.begin(), v.end(), greater<int>());
    cout << m(v, k);
}