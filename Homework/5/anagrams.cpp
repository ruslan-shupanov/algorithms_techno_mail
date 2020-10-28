#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <unordered_set>

using namespace std;

string strSort(string s) {
    int count[26] = {0}, n = s.length();
    for (int i = 0; i < n; i++)
        count[s[i] - 'A']++;
    int p = 0;
    string t(n, 'A');
    for (int j = 0; j < 26; j++)
        for (int i = 0; i < count[j]; i++)
            t[p++] += j;
    return t;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    unordered_set<string> ann(4 * N);
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        string t = strSort(str);
        ann.insert(t);
    }
    cout << ann.size() << endl;
    return 0;
};
