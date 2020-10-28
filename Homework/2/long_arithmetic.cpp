/*
 * Длинное сложение и вычитание
На вход подаётся три строки. Первая содержит десятичное представление длинного числа (первый операнд), вторая — представление операции,
строки + или -, третья — десятичное представление второго операнда.

Длины первой и третьей строки ограничены 100000 символами. Вторая строка содержит ровно один символ.

Требуется исполнить операцию и вывести результат в десятичном представлении.

Examples
Input
232
+
100

Output
332

Input
-100
-
199

Output
-299
 */

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

const int base = 1000*1000*1000;
const int b = 9;

vector<int> add_core(vector<int> &a, vector<int> &b) {
    int carry = 0;
    for (size_t i = 0; i < max(a.size(), b.size()) || carry; i++) {
        if (i == a.size())
            a.push_back (0);
        a[i] += carry + (i < b.size() ? b[i] : 0);
        carry = a[i] >= base;
        if (carry)  a[i] -= base;
    }
    return a;
}

vector<int> succ_core(vector<int> &a, vector<int> &b, bool &flag_a) {
    if (a.size() < b.size() || (a.size() == b.size() && b[b.size() - 1] > a[a.size() - 1])) {
        flag_a = true;
        return succ_core (b, a, flag_a);
    }
    int carry = 0;
    for (size_t i = 0; i < b.size() || carry; i++) {
        a[i] -= carry + (i < b.size() ? b[i] : 0);
        carry = a[i] < 0;
        if (carry)  a[i] += base;
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    return a;
}

vector<int> add(vector<int> &a, bool &flag_a, vector<int> &b, bool &flag_b) {
    if (flag_a && flag_b) {
        flag_a = true;
        return add_core(a, b);
    } else if (flag_a) {
        flag_a = false;
        return succ_core(b, a, flag_a);
    } else if (flag_b) {
        return succ_core(a, b, flag_a);
    } else {
        flag_a = false;
        return add_core(a, b);
    }

}

vector<int> succ(vector<int> &a, bool &flag_a, vector<int> &b, bool &flag_b) {
    if (flag_a && flag_b) {
        flag_a = false;
        return succ_core(b, a, flag_a);
    } else if (flag_a) {
        flag_a = true;
        return add_core(a, b);
    } else if (flag_b) {
        flag_a = false;
        return add_core(a, b);
    } else {
        return succ_core(a, b, flag_a);
    }
}

void read_larr(vector<int> &a, bool &flag, string &s) {
    int j = 0;
    if (s[0] == '-') {
        flag = true;
        j = 1;
    } else flag = false;

    for (int i = (int)s.length(); i > j; i -= b)
        if (i - j < b)
            a.push_back (atoi (s.substr (j, i - j).c_str()));
        else
            a.push_back (atoi (s.substr (i - b, b).c_str()));
}

void print(vector<int> const a, bool flag) {
    if (a.empty()) {
        printf ("0");
        return;
    } else if (flag) {
        printf ("-");
    }
    printf ("%d",  a.back());
    for (int i = (int)a.size() - 2; i >= 0; --i)
        printf ("%09d", a[i]);
}

int main() {
    string str_a, str_b;
    char oper;
    cin >> str_a >> oper >> str_b;
    vector<int> a, b;
    bool flag_a, flag_b;
    read_larr(a, flag_a, str_a);
    read_larr(b, flag_b, str_b);
    vector<int> res;
    if (oper == '+')
        res = add(a, flag_a, b, flag_b);
    else
        res = succ(a, flag_a, b, flag_b);
    print(res, flag_a);
    return 0;
}
