#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    vector<int> stones;
    int N;
    int sum_all = 0;
    cin >> N;
    for (auto i = 0; i < N; i++) {
        int x;
        cin >> x;
        sum_all += x;
        stones.push_back(x);
    }
    int diff = sum_all;
    int j = 1 << N;
    for (auto i = 0; i < j; i++) {
        int t = i;
        int s = 0;
        int k = 0;
        while (t) {
            if (t & 1) s += stones[k];
            t >>= 1;
            k++;
        }
        if (diff > abs(sum_all - 2 * s))
            diff = abs(sum_all - 2 * s);
    }
    cout << abs(diff);
    return 0;
}