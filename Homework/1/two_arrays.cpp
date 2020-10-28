#include <iostream>

using namespace std;

int main() {
    int N1, N2;
    cin >> N1 >> N2;
    int *a1 = new int[N1];
    int *a2 = new int[N2];
    for (auto i = 0; i < N1; i++)
        cin >> a1[i];
    for (auto i = 0; i < N2; i++)
        cin >> a2[i];
    int j = 0, i = 0, s = 0;
    while (i < N1 && j < N2) {
        if (a1[i] == a2[j]) {
            s++;
            j++;
            i++;
        } else if (a1[i] > a2[j])
            j++;
        else
            i++;
    }
    cout << s << endl;
    free(a1);
    free(a2);
    return 0;
}
