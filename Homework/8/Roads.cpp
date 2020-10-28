/*
 * Дороги
В некой стране имеются N городов.
Каждые два города соединены не более, чем одной двунаправленной дорогой, всего в стране M дорог.
Имеется C компаний, пронумерованных от 1 до C. Каждая из дорог либо принадлежит одной из компаний,
либо принадлежит государству, тогда владелец равен нулю.

Два города являются столицами — северной CN и южной CS.
Принят новый закон, согласно которому на ЛЮБОМ из возможных путей между столицами должна иметься дорога, принадлежащая КАЖДОЙ из компаний.

Нужно вывести список всех компаний, для которых между столицами существует путь, на котором у этой компании нет ни одной дороги.

Input format
N M C

a1 b1 c1

a2 b2 c2

...

aN bN cN

CN CS

Output format
K

c1 c2 ... cK

Examples
Input
4 5 2
1 2 1
1 3 2
2 4 2
3 4 1
2 3 0
1 4

Output
2
1 2

Input
4 4 2
1 2 1
1 3 2
2 4 2
3 4 1
1 4

Output
0
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void my_dfs(vector<vector<pair<int, int> > > &g, vector<bool> &used, int cur, int global) {
    used[cur] = true;
    for (unsigned i = 0; i < g[cur].size(); ++i) {
        if (g[cur][i].second != global && !used[g[cur][i].first])
            my_dfs(g, used, g[cur][i].first, global);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int N, M, C;
    cin >> N >> M >> C;
    vector<vector<pair<int, int> > > g(N);
    for (int i = 0; i < M;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    int cn, cs;
    cin >> cn >> cs;
    --cn; --cs;
    vector<int> comp;
    int count = 0;
    for (int i = 1; i <= C; i++) {
        vector<bool> used(N);
        my_dfs(g, used, cs, i);
        if (used[cn]) {
            count++;
            comp.push_back(i);
        }
    }
    sort(comp.begin(), comp.end());
    cout << count << endl;
    for (auto i : comp) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}