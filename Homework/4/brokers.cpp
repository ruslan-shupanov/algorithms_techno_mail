#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

double percent(double a, double b) {
    return (a + b) / 100;
}

template<typename T> double heap(T& q){
    double b = 0;
    while(!q.empty()) {
        long long int a = q.top();
        q.pop();
        long long int c = q.top();
        q.pop();
        b += percent(c, a);
        if (q.empty())
            break;
        q.push(a + c);
    }
    return b;
}

int main() {
    int n;
    cin >> n;
    std::priority_queue<long long int, std::vector<long long int>, std::greater<long long int> > q;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        q.push(x);
    }
    printf("%.2lf\n", heap(q));
    return 0;
}