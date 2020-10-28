#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <iterator>
#include <cmath>

using namespace std;

template< class InputIt >
unordered_set<long long int>::iterator
beladi(InputIt first, InputIt last, unordered_set<long long int> &c)
{
    auto max = first;
    unordered_set<long long int>::iterator ret;
    for(auto it = c.begin(); it != c.end(); it++) {
        auto i = find(first, last, *it);
        if (i == last)
            return it;
        if (i > max) {
            max = i;
            ret = it;
        }
    }
    return ret;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    unsigned int N, M;

    cin >> N >> M;
    vector<long long int> request(M);
    for (int i = 0; i < M; i++) {
        long long int x;
        cin >> x;
        request[i] = x;
    }
    unordered_set<long long int> cash(N);
    int count = 0;
    for (int i = 0; i < M; i++) {
        auto it = cash.find(request[i]);
        if (it == cash.end()) {
            if (count < N)
                cash.insert(request[i]);
            else {
                auto it2 = beladi(request.begin() + i, request.end(), cash);
                cash.erase(it2);
                cash.insert(request[i]);
            }
            count++;
        }
    }
    cout << count << endl;
};
