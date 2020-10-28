// Задача не решена, не заходила по времни -> нужна оптимизация или другой алгоритм
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <time.h>

using namespace std;


template <class InputIterator1, class InputIterator2>
int set_intersection (InputIterator1 first1, InputIterator1 last1,
                                 InputIterator2 first2, InputIterator2 last2)
{
    int sum = 0;
    while (first1!=last1 && first2!=last2)
    {
        if (*first1<*first2) ++first1;
        else if (*first2<*first1) ++first2;
        else {
            sum++;
            ++first1; ++first2;
        }
    }
    return sum;
}

int main( ) {
    int n, m;
    cin >> n >> m;
    vector<set<int>> sets(n);
//    clock_t s1 = clock();
    for (int i = 0; i < n; i++) {
        vector<int> set(m);
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            set[j] = x;
        }
        sets[i].insert(set.begin(), set.end());
    }
    int max = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int tmp = set_intersection(sets[i].begin(), sets[i].end(), sets[j].begin(), sets[j].end());
            if (tmp > max) {
                max = tmp;
            }
        }
    }
    cout << max << endl;
    return 0;
}