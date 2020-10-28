#include <iostream>
#include <stack>
#include <stdio.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include <locale>
#include <vector>

using namespace std;

bool isOperand(string str)
{
    std::locale loc;
    return isdigit(str[0], loc) || (str[0] == '-' && str.length() > 1);
}

int evaluatePolish(vector<string> exp)
{
    stack<int> operand;

    for (int j = exp.size() - 1; j >= 0; j--) {

        if (isOperand(exp[j])) {
            int x = stoi(exp[j]);
            operand.push(x);
        } else {

            int o1 = operand.top();
            operand.pop();
            int o2 = operand.top();
            operand.pop();

            if (exp[j] == "+")
                operand.push(o1 + o2);
            else if (exp[j] == "-")
                operand.push(o1 - o2);
            else if (exp[j] == "*")
                operand.push(o1 * o2);
            else if (exp[j] == "/")
                operand.push(o1 / o2);
        }

    }

    return operand.top();
}

int main() {
    vector<string> expr;
    string str;

    while (cin >> str) {
        expr.push_back(str);
    }
    cout << evaluatePolish(expr) << endl;
    return 0;
}
