/*Счастливые билеты
Номер билета состоит из чётного числа цифр N в M-ричной системе счисления. Счастливым билетом называется билет, сумма цифр первой половины которого равна сумме цифр второй половины.
Для заданных N и M найти количество счастливых билетов. Учтите, их число может быть очень велико.
Input format
N M

2⩽N⩽150, N mod 2 = 0

2⩽M⩽40
Examples
Input
6 10

Output
55252
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace:: std;

struct LongArith {
    const int mask = 1000*1000*1000;
    const int b = 9;
    bool flag = true;
    vector<int> vec;
    LongArith() {
        vec.reserve(0);
    }

    LongArith(int x, bool f) {
        if (!f)
            flag = false;
        else {
            stringstream ss;
            ss << x;
            string s = ss.str();
            for (int i = (int)s.length(); i > 0; i -= b)
                if (i < b)
                    vec.push_back (atoi (s.substr (0, i).c_str()));
                else
                    vec.push_back (atoi (s.substr (i - b, b).c_str()));
            flag = true;
        }

    }
    LongArith(const LongArith &b) {
        if (!b.flag) {
            flag = false;
        } else {
            vec = b.vec;
            flag = true;
        }
    }

    void print() {
        printf ("%d", vec.empty() ? 0 : vec.back());
        for (int i = (int)vec.size() - 2; i >= 0; --i)
            printf ("%09d", vec[i]);
        cout << endl;
    }


    LongArith add(const LongArith &b) {
        int carry = 0;
        for (size_t i = 0; i < max(vec.size(), b.vec.size()) || carry; i++) {
            if (i == vec.size())
                vec.push_back (0);
            vec[i] += carry + (i < b.vec.size() ? b.vec[i] : 0);
            carry = vec[i] >= mask;
            if (carry)  vec[i] -= mask;
        }
        flag = true;
        return *this;
    }

    void operator=(const LongArith& b) {
        if (!b.flag) {
            flag = false;
        } else {
            vec = b.vec;
            flag = true;
        }
    }

    void operator=(int x) {
        stringstream ss;
        ss << x;
        string s = ss.str();
        for (int i = (int)s.length(); i > 0; i -= b)
            if (i < b)
                vec.push_back (atoi (s.substr (0, i).c_str()));
            else
                vec.push_back (atoi (s.substr (i - b, b).c_str()));
        flag = true;
    }
};

LongArith tickets(int n, int m, int left, vector<vector<LongArith> > &tab) {
    if (left < 0) return LongArith(0, true);
    if (n == 1) {
        return LongArith(left <= (m - 1), true);
    }
    LongArith sum(tab[n][left]);
    if (!sum.flag) {
        sum = 0;
        for (int i = 0; i <= (m - 1); i++) {
            sum.add(tickets(n - 1, m, left - i, tab));
        }
        tab[n][left] = sum;
    }
    return sum;
}


int main() {

    int N, M;
    cin >> N >> M;
    int left = (M - 1) * N / 2;
    vector<vector<LongArith> > tab(N + 2, vector<LongArith>(left + 2));


    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < left + 2; j++) {
            tab[i][j] = LongArith(0, false);
        }
    }

    auto res = tickets(N, M, left, tab);

    res.print();

    return 0;
}
