#include <iostream>

using namespace std;

int main() {
    int n, x, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > sum + 1) break;
        sum += x;
    }
    cout << sum + 1 << endl;
    return 0;
}