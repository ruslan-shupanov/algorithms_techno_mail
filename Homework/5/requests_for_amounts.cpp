#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <numeric>

using namespace std;

void build_tree(vector<long long int> &sec, vector<int> &a, int v, int tl, int tr) {
    if (tl == tr)
        sec[v] = a[tl];
    else {
        int tm = (tl + tr) >> 1;
        build_tree (sec, a, v << 1, tl, tm);
        build_tree (sec, a, (v << 1) + 1, tm + 1, tr);
        sec[v] = sec[v << 1] + sec[(v << 1) + 1];
    }
}

long long int sum_tree (vector<long long int> &sec, int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return sec[v];
    int tm = (tl + tr) >> 1;
    return sum_tree (sec, v << 1, tl, tm, l, min(r, tm))
           + sum_tree (sec, (v << 1) + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update_tree (vector<long long int> &sec, int v, int tl, int tr, int pos, long long int new_val) {
    while (tl != tr) {
        int tm = (tl + tr) >> 1;
        if (pos <= tm) {
            v = v << 1;
            tr = tm;
        } else {
            v = (v << 1) + 1;
            tl = tm + 1;
        }
    }
    sec[v] = new_val;
    while (v !=  1) {
        if (v % 2 == 0) {
            v = v >> 1;
        }
        else {
            v = (v - 1) >> 1;
        }
        sec[v] = sec[(v << 1)] + sec[(v << 1) + 1];
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    vector<long long int> sections(4 * N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        v[i] = x;
    }
    build_tree(sections, v, 1, 0, N - 1);
    for (int i = 0; i < M; i++) {
        int fl, a, b;
        scanf("%d %d %d", &fl, &a, &b);
        if (fl == 1) {
            long long int sum = sum_tree(sections, 1, 0, N - 1, a, b);
            printf("%lld\n", sum);
        } else
            update_tree(sections, 1, 0, N - 1, a, b);
    }
    return 0;
};
