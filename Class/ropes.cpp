#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x, sum = 0;
    cin >> n;
    vector<int> nails;
    vector<int> pop;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nails.push_back(x);
        pop.push_back(0);
    }
    sort(nails.begin(), nails.end());
    pop[0] = pop[1] = pop[n - 2] = pop[n - 1] = 1;
    sum += (nails[1] - nails[0]) + (nails[n - 1] - nails[n - 2]);
    for (int i = 2; i < n - 1; i++) {
        if (pop[i]) continue;
        int less = nails[i] - nails[i - 1], big = nails[i + 1] - nails[i];
        if (less < big) {
            sum += less;
            pop[i - 1] += 1;
        } else if (big > less) {
            sum += big;
            pop[i + 1] += 1;
        } else {
            if (!pop[i - 1]) {
                sum += less;
                pop[i - 1] += 1;
            } else if (!pop[i + 1]) {
                sum += big;
                pop[i + 1] += 1;
            } else {
                sum += less;
                pop[i - 1] += 1;
            }
        }
        pop[i] += 1;
    }
//    for (auto i : pop) {
//        cout << i << " ";
//    }
//    cout << endl;
    for (int i = 1; i < n - 1; i++) {
        if (pop[i] > 1 && pop[i + 1] > 1) {
            sum -= (nails[i + 1] - nails[i]);
            pop[i] -= 1;
            pop[i + 1] -= 1;
        }
    }
    cout << sum << endl;
    return 0;
}