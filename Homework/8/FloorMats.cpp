/*
 * Коврики
Имеется прямоугольная область, состоящая из 6⩽N⩽1000 на 6⩽M⩽1000 одинаковых квадратных клеток.
Часть клеток свободна, часть закрашена. Ковриком называется максимальное множество закрашенных клеток, имеющих общую границу.
Коврики размером 1×1 тоже допустимы.

Требуется по заданной раскраске области определить количество находящихся на ней ковриков.

Input format
В первой строке содержатся N и M — размеры области.
В каждой из следующих N строк находится ровно M символов, каждый из которых может быть или точкой, если поле свободно, или плюсом, если поле закрашено.
Output format
Общее количесово ковриков на поле.
Examples
Input
6 6
.++++.
.....+
+..+..
..++..
.+....
.+...+

Output
6
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>

using namespace::std;

void count(vector<vector<char> > &mats, vector<vector<bool> > &used, int i, int j, int N, int M)
{
    if (used[i][j])
        return;
    used[i][j] = true;
    if (mats[i][j] == '+') {
        if (i < N - 1)
            count(mats, used, i + 1, j, N, M);
        if (i > 0)
            count(mats, used, i - 1, j, N, M);
        if (j < M - 1)
            count(mats, used, i, j + 1, N, M);
        if (j > 0)
            count(mats, used, i, j - 1, N, M);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<vector<char> > mats(N, vector<char>(M, ' '));
    vector<vector<bool> > used(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        mats[i] = vector<char>(str.begin(), str.end());
    }
    int s = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!used[i][j]) {
                if (mats[i][j] == '+') {
                    count(mats, used, i, j, N, M);
                    s++;
                }
                used[i][j] = true;
            }
        }
    }
    cout << s << endl;
    return 0;
}