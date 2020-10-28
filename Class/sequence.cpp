#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using  namespace std;

char foo(int n, int k) {
    if (k == 1)
        return 'a' + (n - 1);
    else if (k <= (1 << (n - 1)) && k > 1){
        return foo(n - 1, k - 1);
    } else {
        return foo(n - 1, k - (1 << (n - 1 )));
    }
}

int main() {
    int N, K, L;
    cin >> N >> K >> L;
    for (auto i = K; i <= L; i++) {
        cout << foo(N, i);
    }
    return 0;
}