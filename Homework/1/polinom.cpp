#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int outline(vector<int> &pol, int x, int mod) {
    long long int result = pol[0];
    for (size_t i = 1; i < pol.size(); i++) {
        result = (result * x);
        result = (result + pol[i]) % mod;
    }
    return result % mod;
}

int main() {
    int n, m, mod, x;
    cin >> n >> m >> mod;
    vector<int> pol;
    vector<int> arg;
    for (int i = 0; i <= n; i++) {
        scanf("%d", &x);
        pol.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        arg.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        printf("%lld\n", outline(pol, arg[i], mod));
    }
    return 0;
}
