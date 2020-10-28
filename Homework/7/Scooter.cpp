//У Еремея есть электроскутер и он хочет доехать от дома до института, затратив как можно меньше энергии. Весь город расположен на холмистой местности и разделён на квадраты. Для каждого перекрёстка известна его высота в метрах над уровнем моря. Если ехать от перекрёстка с большей высотой до смежного с ним перекрёстка с меньшей высотой, то электроэнергию можно не тратить, а если наоборот, то расход энергии равен разнице высот между перекрёстками.
//
//Помогите ему спланировать маршрут, чтобы он затратил наименьшее количество энергии от дома до института. Дом находится в левом верхнем углу, институт --- в правом нижнем.
//
//Input format
//N M
//
//H1,1 H1,2 ... H1,M
//
//H2,1 H2,2 ... H2,M
//
//... ... ... ...
//
//HN,1 HN,2 ... HN,M
//
//3⩽N,M⩽1000
//
//0⩽Hi,j⩽1000
//
//Output format
//MaxConsumingEnergy
//
//        Examples
//Input
//3 5
//3 1 4 1 5
//9 2 6 5 3
//5 9 7 9 3
//
//Output
//5


#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int len(int a, int b) {
    return b - a <= 0 ? 0 : b - a;
}

const int INF = 1000000000;

int main()
{
    std::ios_base::sync_with_stdio(false);
    int N, M;
//    scanf("%d %d", &N, &M);
    cin >> N >> M;
    int n = N * M;
    vector<vector<int>> G(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
//            scanf("%d", &x);
            cin >> x;
            G[i].push_back(x);
        }
    }
    vector < vector < pair<int,int> > > g (n);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j != 0)
                g[i * M + j].push_back(make_pair(i * M + j - 1, len(G[i][j], G[i][j - 1])));
            if (j != M - 1)
                g[i * M + j].push_back(make_pair(i * M + j + 1, len(G[i][j], G[i][j + 1])));
            if (i != 0)
                g[i * M + j].push_back(make_pair((i - 1) * M + j, len(G[i][j], G[i - 1][j])));
            if (i != N - 1)
                g[i * M + j].push_back(make_pair((i + 1) * M + j, len(G[i][j], G[i + 1][j])));
        }
    }
    int s = 0;

    vector<int> d (n, INF),  p (n);
    d[s] = 0;
    set < pair<int,int> > q;
    q.insert (make_pair (d[s], s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase (q.begin());

        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j].first,
                    len = g[v][j].second;
            if (d[v] + len < d[to]) {
                q.erase (make_pair (d[to], to));
                d[to] = d[v] + len;
                p[to] = v;
                q.insert (make_pair (d[to], to));
            }
        }
    }
    cout << d[n - 1] << endl;
    return 0;
};
