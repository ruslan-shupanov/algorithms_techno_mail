#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




int main() {
    enum {OUT, IN1, IN2, IN3, IN4} state = OUT;
    int one = 0, two = 0, three = 0, four = 0;
    char c;
    c = getchar();
    while (c != EOF) {

        if (state == IN1 && c == '*') {
            c = getchar();
            if (c == ')') {
                state = OUT;
                one++;
            }
            else continue;
        } else if (state == IN2 && c == '}') {
            state = OUT;
            two++;
        } else if (state == IN3 && c == '\n') {
            three++;
            state = OUT;
        } else if (state == IN4 && c == '\'') {
            four++;
            state = OUT;
        } else if (state == OUT && c == '(') {
            c = getchar();
            if (c == '*') state = IN1;
            else continue;
        } else if (state == OUT && c == '{') state = IN2;
        else if (state == OUT && c == '/' ) {
            c = getchar();
            if (c == '/') state = IN3;
            else continue;
        } else if (state == OUT && c == '\'' ) state = IN4;

        c = getchar();
    }
    cout << one << " " << two << " " << three << " " << four << endl;
    return 0;
}
