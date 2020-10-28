#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;
    vector<char> list_char;
    for (auto i : str) {
        list_char.push_back(i);
    }
    auto i = list_char.end() - 1;
    while (true) {
        vector<char>::iterator i1, i2;

        i1 = i;
        if (*--i < *i1) {
            i2 = list_char.end();
            while (!(*i < *--i2));
            iter_swap(i, i2);
            reverse(i1, list_char.end());
            break;
        }
        if (i == list_char.begin()) {
            reverse(list_char.begin(), list_char.end());
            break;
        }
    }
    for (auto i : list_char) {
        cout << i;
    }

    return 0;
}