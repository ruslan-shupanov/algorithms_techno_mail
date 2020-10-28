/*  Кузнечик
    Имеется лестница, в которой N ступенек. Кузнечик находится перед лестницей. Он прыгает только вверх и способен прыгнуть вверх не более, чем на M ступенек.
    Определить, сколькими способами кузнечик может допрыгать да самой верхней ступеньки.
    1⩽M⩽N⩽30
    Для N=5 и M=2 имеется 8 маршрутов: (1,2,3,4,5),(1,2,3,5), (1,2,4,5), (1,3,4,5), (1,3,5), (2,3,4,5), (2,3,5), (2,4,5)
        Input format
    N M — количество ступенек в лестнице и наибольший размер прыжка кузнечика.
        Output format
    R — число способов, которыми кузнечик может допрыгать до самой верхней ступеньки.
    Examples
        Input
    5 2
        Output
    8
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//int f(int p, int M)
//{
//    if (p == 0) return 1;
//    if (p < 0) return 0;
//    int sum = 0;
//    for (int i = 0; i < M; i++) {
//        sum += f(p - (i + 1), M);
//    }
//    return sum;
//}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<int> f(N + 1, 0);
    f[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i + j + 1 > N) break;
            f[i + j + 1] += f[i];
        }
    }
    cout << f[N] << endl;
    return 0;
};
