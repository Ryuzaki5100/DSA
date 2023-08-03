#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<char, int> precendence = {{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}, {'^', 2}};
    string expression, result = "";
    cin >> expression;
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        if (isalpha(expression[i]))
            result += expression[i];
        else if (expression[i] == '(')
            s.push(expression[i]);
        else if (expression[i] == ')')
        {
            while (s.top() != '(')
            {
                result += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && precendence[s.top()] >= precendence[expression[i]] && s.top() != '(')
            {
                result += s.top();
                s.pop();
            }
            s.push(expression[i]);
        }
    }
    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }
    cout << result;
}