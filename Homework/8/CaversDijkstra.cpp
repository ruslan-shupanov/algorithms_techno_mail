/*
 * Спелеологи
Гора состоит из N пещер и M тоннелей между ними. Каждый тоннель имеет определённую длину.

Спелеологи, исследующие гору, находятся в пещере S, выход наружу находится в пещере F.

Продвигаясь по пещерам, спелеологи оставили K не очень хорошо затушенных костров,
но вот в какой-то момент времени произошёл толчок и все костры стали дымить.
Дым распространяется по всем тоннелям, ведущим от пещеры, одновременно со скоростью 1 метр в секунду.
Как только дым доходит до какой-либо пещеры, он начинает распространяться по всем тоннелям, ведущим из неё.
Сами спелеологи, почувствовав толчок, стали пробираться к выходу со скоростью 1 метр в секунду.
Вопрос состоит в том, успеют ли они добраться до выхода прежде чем столкнутся с дымом.
Если спелеологи и дым достигают выхода одновременно, то побеждает дым.
Известно, что в начальный момент времени спелеологи находятся в пещере без дыма.

Input format
N M K

f1 f2 ... fk

s1 d1 w1

s2 d2 w2

...

sn dn wn

S F

Первая строка содержит количество пещер N, количество тоннелей M и количество костров K.

Вторая строка содержит номера пещер с кострами

Далее следует N строк, содержащих описание i-го тоннеля — si и di, соответственно, начало и конец тоннеля, wi — длина тоннеля в метрах.
Тоннели двунаправленные.

Последняя строка — числа S, номер пещеры со спелеологами и F — номер пещеры, являющейся выходом.

3⩽N⩽10000

3⩽M⩽100000

1⩽K⩽100

1⩽wi⩽10000

Output format
Result — число секунд, требующихся спелеологам для выхода из пещеры или -1, если дым успевает их настичь или они не могут выйти из пещеры совсем.
Examples
Input
6 5 1
6
1 2 20
2 3 2
3 4 1
2 5 1
5 6 3
4 1

Output
23

Input
6 6 2
4 1
4 1 1
6 5 1
2 4 1
1 5 2
5 6 2
5 1 2
3 6

Output
-1
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <set>

using namespace::std;

const int INF = INT_MAX / 2;

int dijkstra(vector<vector <pair<int,int> > > &g, int s, int to, int n) {
    vector<int> d (n, INF);
    d[s] = 0;
    set < pair<int,int> > q;
    q.insert (make_pair (d[s], s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase (q.begin());

        for (size_t j = 0; j<g[v].size(); ++j) {
            int to = g[v][j].first,
                    len = g[v][j].second;
            if (d[v] + len < d[to]) {
                q.erase (make_pair (d[to], to));
                d[to] = d[v] + len;
                q.insert (make_pair (d[to], to));
            }
        }
    }
    return d[to];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int N, M, K, S, F;
    cin >> N >> M >> K;
    vector<int> bonfires(K);
    vector<vector <pair<int,int> > > caves(N);
    for (int i = 0; i < K; i++) {
        int k;
        cin >> k;
        bonfires[i] = k - 1;
    }
    for (int i = 0; i < M; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        caves[s - 1].push_back(make_pair(d - 1, w));
        caves[d - 1].push_back(make_pair(s - 1, w));
    }
    cin >> S >> F;


    long long int spel = dijkstra(caves, S - 1, F - 1, N);
    if (spel == INF) {
        cout << -1 << endl;
        return 0;
    }
    long long int bonfire = INF;
    for (int i = 0; i < K; i++) {
        auto temp = dijkstra(caves, bonfires[i], F - 1, N);
        if (temp < bonfire)
            bonfire = temp;
    }
    if (bonfire <= spel) {
        cout << -1 << endl;
    } else {
        cout << spel << endl;
    }
    return 0;
}