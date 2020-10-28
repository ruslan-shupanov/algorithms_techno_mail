#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;

int sign(long long int x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

long long foo(long long int x, long long int N) {
    return x * x - N;
}


long long int biop(long long int n) {
    long long int xn = 0, xk = (n + 1), eps, xi;
    if (foo(xn, n) == 0)
        return xn;
    if (foo(xk, n) == 0)
        return xk;
//    if (yn * yn - n == 0)
//        return yn

    while ((xk - xn) != 0) {
        long long int dx = (xk - xn) / 2;
        if (dx < 1)
            dx = 1;
        xi = xn + dx;
        if (sign(foo(xn, n)) != sign(foo(xi, n)))
            xk = xi;
        else
            xn = xi;
        if (foo(xk, n) == 0) {
            xi = xk;
            break;
        }
        if (foo(xn, n) == 0) {
            xi = xn;
            break;
        }
    }
    return xi;
}

int main() {
    long long int n;
    cin >> n;
    cout << biop(n);
    long long int y0 = biop(n);

    return 0;
}