#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;


struct Card {
    string name;
    string value;

    Card(string s1, string s2) : name(s1), value(s2) {}

    bool operator == (Card const & b)
    {
        return name == b.name;
    }
};

struct Phones {
    vector<Card> list;


    void add(string name, string value) {
        Card tmp = Card(name, value);
        auto it = find(list.begin(), list.end(), tmp);
        if (it != list.end()){
            error();
            return;
        }
        list.push_back(tmp);
    }

    void del(string name) {
        Card tmp = Card(name, "");
        auto it = find(list.begin(), list.end(), tmp);
        if (it == list.end()) {
            error();
            return;
        }
        list.erase(it);
    }

    void edit(string name, string value) {
        Card tmp = Card(name, value);
        auto it = find(list.begin(), list.end(), tmp);
        if (it == list.end()) {
            error();
            return;
        }
        *it = tmp;
    }

    void print(string name) {
        Card tmp = Card(name, "");
        auto it = find(list.begin(), list.end(), tmp);
        if (it == list.end()) {
            error();
            return;
        }
        cout << it->name << " " << it->value << endl;
    }

    void error() {
        cout << "ERROR" << endl;
    }
//    phone() : list(NULL) {}
};

int main()
{
    int N;
    cin >> N;
    string cmd, name, num;
    Phones pb;

    for (int i = 0; i < N; i++) {
        cin >> cmd;
        if (cmd == "ADD") {
            cin >> name >> num;
            pb.add(name, num);
            continue;
        }
        if (cmd == "DELETE") {
            cin >> name;
            pb.del(name);
            continue;
        }
        if (cmd == "PRINT") {
            cin >> name;
            pb.print(name);
            continue;
        }
        if (cmd == "EDITPHONE") {
            cin >> name >> num;
            pb.edit(name, num);
            continue;
        }
        cout << "ERROR" << endl;
    }

    return 0;
};
