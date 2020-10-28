#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Field {
    string s = "";
    vector<int> map = vector<int>();

    Field () {
        s = "";
        map = vector<int>();
    }
    Field (string str, vector<int> vec) : s(str), map(vec) {}

    bool operator > (const Field& field) const
    {
        for (size_t i = 0; i < map.size(); i++) {
            if (map[i] == field.map[i])
                continue;
            else
                return map[i] > field.map[i];
        }
        return false;
    }

    void print (bool flag) {
        cout << s << " ";
        if (flag)
            for (size_t i = 0; i < map.size(); i++) {
                cout << map[i] << " ";
            }
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<Field> map(n);
    vector<int> stand(k, 0);
    for (auto &it : stand) {
        cin >> it;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<int> vec(k);
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            auto match = std::find(stand.begin(), stand.end(), (j + 1));
            vec[match - stand.begin()] = x;
        }
        map[i] = Field(s, vec);
    }
    sort(map.begin(), map.end(), greater<Field>());
    for (auto it : map) {
        it.print(false);
        cout << endl;
    }
    return 0;
}