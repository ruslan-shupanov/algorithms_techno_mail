#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace:: std;

int wildcmp(const string wild, const string string)
{
    int cp, mp;

    int i = 0, j = 0;
    while (string[i] && wild[j] != '*') {
        if ((wild[j] != string[i]) && (wild[j] != '?'))
            return 0;

        i++;
        j++;
    }

    while (string[i])
    {
        if (wild[j] == '*')
        {
            if (!wild[++j])
                return 1;

            mp = j;
            cp = i+1;
        }
        else if ((wild[j] == string[i]) || (wild[j] == '?'))
        {
            i++;
            j++;
        }
        else
        {
            j = mp;
            i = cp++;
        }

    }

    while (wild[j] == '*')
        j++;

    return !wild[j];
}

int main()
{
    string text, pat;
    cin >> text >> pat;
    auto k = wildcmp(pat, text);
    if (k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}