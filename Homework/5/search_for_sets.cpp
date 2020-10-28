#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    set<vector<int>> model;
    for (int i = 0; i < N; i++) {
        vector<int> set(M);
        for (int j = 0; j < M; j++) {
            int x;
            scanf("%d", &x);
            set[j] = x;
        }
        sort(set.begin(), set.end());
        model.insert(set);apez
    }
    for (int i = 0; i < K; i++) {
        vector<int> trial(M);
        for (int j = 0; j < M; j++) {
            int x;
            scanf("%d", &x);
            trial[j] = x;
        }
        sort(trial.begin(), trial.end());
        auto it = model.find(trial);
        if (it != model.end())
            printf("%d\n", 1);
        else
            printf("%d\n", 0);
    }
    return 0;
};
