#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int sum = 0;
    int max_i = 0;
    for (auto i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x == 5)
            sum--;
        else
            sum += (x - 5) / 5;
        max_i = max(sum, max_i);
    }
    cout << max_i;
    return 0;
}