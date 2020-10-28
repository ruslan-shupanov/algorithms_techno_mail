/*
 * Передающие станции
Компания сотовой связи получила лицензии на установку вышек сотовой связи в одном из новых районов города.
На каждую вышку нужно установить приёмо-передатчик, который позволит связаться с другими вышками.
Для снижения общей стоимости проекта приёмо-передатчики решено закупить оптом с большой скидкой, поэтому на всех вышках они будут однотипные.
Выпускается много типов передатчиков, каждый из которых имеет различную мощность, причём, чем больше мощность, тем он дороже и имеет больший радиус охватываемой территории.

Наша задача — подобрать модель передатчика с наименьшей возможной мощностью, исходя из расположения вышек для того,
чтобы можно было передавать сообщения между любыми вышками, возможно, ретранслируя их.

Input format
Первая строка содержит количество вышек 2⩽N⩽2000

В остальных N строках — пары координат вышек в Декартовой системе -10000⩽Xi,Yi⩽10000.

Output format
Одно число — наименьший требуемый радиус, достаточный для функционирования всей системы с точностью до 4-х знаков после запятой.
Examples
Input
5
0 0
1 0
0 1
1 1
3 3

Output
2.8284
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <climits>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace::std;

double len(pair<int, int> &a, pair<int, int> &b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int> > station(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        station[i] = make_pair(x, y);
    }
    vector < vector<double > > g(n, vector<double>(n));
    const int INF = 1000000000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                g[i][j] = len(station[i], station[j]);
            }
        }
    }
    vector<bool> used (n);
    vector<double> min_e (n, INF);
    vector<int> sel_e (n, -1);
    min_e[0] = 0;
    double max = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;

        used[v] = true;
        if (sel_e[v] != -1) {
            if (g[v][sel_e[v]] > max)
                max = g[v][sel_e[v]];
        }

        for (int to = 0; to < n; ++to)
            if (g[v][to] < min_e[to]) {
                min_e[to] = g[v][to];
                sel_e[to] = v;
            }
    }
    cout << fixed << setprecision(4) << max << endl;
    return 0;
}