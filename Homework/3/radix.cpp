#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

void radix_8(vector<unsigned int> &a, int n) {
    unsigned int mask = 0xFFU;
    vector<unsigned int> b(n);
    unsigned int count1[2][256] = {}, count2[2][256] = {}, count3[2][256] = {}, count4[2][256] = {};
    for (long i = 0; i < n; i++) {
        count1[0][a[i] & mask]++;
        count2[0][(a[i] >> 8) & mask]++;
        count3[0][(a[i] >> 16) & mask]++;
        count4[0][(a[i] >> 24)]++;
    }

    for (int i = 1; i < 256; i++) {
        count1[1][i] = count1[0][i - 1] + count1[1][i - 1];
        count2[1][i] = count2[0][i - 1] + count2[1][i - 1];
        count3[1][i] = count3[0][i - 1] + count3[1][i - 1];
        count4[1][i] = count4[0][i - 1] + count4[1][i - 1];
    }

    for (long i = 0; i < n; i++)
        b[count1[1][a[i] & mask]++] = a[i];

    for (long i = 0; i < n; i++)
        a[count2[1][(b[i] >> 8) & mask]++] = b[i];

    for (long i = 0; i < n; i++)
        b[count3[1][(a[i] >> 16) & mask]++] = a[i];

    for (long i = 0; i < n; i++)
        a[count4[1][b[i] >> 24]++] = b[i];
}

int main() {
    unsigned int n, k, l, m;
    cin >> n >> k >> m >> l;
    vector<unsigned int> a(n);
    a[0] = k;

    for (unsigned int i = 0; i < n - 1; i++)
        a[i+1] = (unsigned int)((a[i]*(unsigned long long)m)&0xFFFFFFFFU)%l;

    radix_8(a, n);
    unsigned long long sum = 0;
    for (unsigned int i = 0; i < n; i += 2) {
        sum += a[i];
    }
    cout << sum % l << endl;
}
