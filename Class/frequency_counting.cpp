#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    string str;
    map<char, int> count;
    cin >> str;
    for (auto c : str) {
        auto it = count.find(c);
        if (it != count.end())
            it->second++;
        else
            count[c] = 1;
    }
    for (auto i : count) {
        cout << i->first;
    }
    return 0;
}