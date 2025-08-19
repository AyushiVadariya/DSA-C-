#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;

    s.push('('); // Step 1: Push '('
    infix += ')'; // Add ')' to end of Q

    for (char ch : infix) {
        if (isalnum(ch)) { // Step 3: Operand → add to P
            postfix += ch;
        } 
        else if (ch == '(') { // Step 4: Left parenthesis → push
            s.push(ch);
        } 
        else if (isOperator(ch)) { // Step 5: Operator
            while (isOperator(s.top()) && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        } 
        else if (ch == ')') { // Step 6: Right parenthesis
            while (s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove '('
        }
    }
    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
