#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> foo (vector<int> &num, int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (num[i] != 2) {
            num[i]++;
            break;
        } else {
            num[i] = 0;
        }
    }
    return num;
}

int main() {
    int v, n;
    vector<int> coins;
    scanf("%d%d", &v, &n);
    int count = 2 * n;
    int sum = 0;
    bool change = true;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        coins.push_back(x);
//        coins.push_back(x);
        sum += 2 * x;
    }
    if (sum < v) {
        cout << "Impossible";
        return 0;
    } else if (sum == v) {
        cout << count;
        return 0;
    }
    int j = pow(3, n);
    vector<int> vec(n);
    for (int i = 0; i < j; i++) {
        int s = 0, c = 0;
        for (int k = n - 1; k >= 0; k--) {
            s += coins[k] * vec[k];
            if (s > v)
                break;
            c += vec[k];
        }

        if (s == v) {
            count = c;
            change = false;
            break;
        }
        vec = foo(vec, n);
    }
    if (change) {
        cout << "Change";
    } else {
        cout << count;
    }
    return 0;
}
