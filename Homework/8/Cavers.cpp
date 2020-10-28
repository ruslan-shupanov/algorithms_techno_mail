#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <climits>
#include <algorithm>

using namespace::std;

const int max_value = INT_MAX / 2;

int main() {
    std::ios_base::sync_with_stdio(false);
    int N, M, K, S, F;
    cin >> N >> M >> K;
    vector<int> bonfires(K);
    vector<vector<int> > caves(N, vector<int>(N, max_value));
    for (int i = 0; i < K; i++) {
        int k;
        cin >> k;
        bonfires[i] = k - 1;
    }
    for (int i = 0; i < M; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        caves[s - 1][d - 1] = w;
        caves[d - 1][s - 1] = w;
    }
    cin >> S >> F;
//    for (int k = 0; k < N; ++k)
//        for (int i = 0; i < N; ++i)
//            for (int j = 0; j < N; ++j)
//                if (caves[i][k] < max_value && caves[k][j] < max_value)
//                    caves[i][j] = min (caves[i][j], caves[i][k] + caves[k][j]);

    long long int spel = caves[S - 1][F - 1];
    if (spel == max_value) {
        cout << -1 << endl;
        return 0;
    }
    long long int bonfire = max_value;
    for (int i = 0; i < K; i++) {
        if (caves[bonfires[i]][F - 1] < bonfire)
            bonfire = caves[bonfires[i]][F - 1];
    }
    if (bonfire <= spel) {
        cout << -1 << endl;
    } else {
        cout << spel << endl;
    }
    return 0;
}