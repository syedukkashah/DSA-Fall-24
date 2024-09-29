#include "iostream"
#include "cctype"  //for isalnum(), check for digit & variable
#include "algorithm" // for reverse()
using namespace std;
class Stack {
    int top;
    int size;
    char *arr;
public:
    Stack(int size) : top(-1), size(size) {
        arr = new char[size];
    }
    bool isEmpty() {
        return top == -1;
    }
    void push(char x) {
        if (top < size - 1) {
            arr[++top] = x;
        } else {
            cout << "Stack overflow" << endl;
        }
    }
    char peek() const {
        if (top >= 0) return arr[top];
        return 0;
    }
    char pop() {
        if (top >= 0) return arr[top--];
        else {
            cout << "Stack underflow" << endl;
            return 0;
        }
    }
};
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3; // Exponent has the highest precedence
    return 0;
}
// Function to convert infix to postfix
string infix_to_postfix(string &infix) {
    string output = "";
    Stack s(infix.size());
    for (char c : infix) {
        if (isalnum(c)) { 
            output += c; // Operand goes directly to output
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                output += s.pop();
            }
            s.pop(); // Pop '(' from the stack
        } else { // Operator encountered
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                output += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        output += s.pop(); // Pop remaining operators
    }
    return output;
}
// Function to convert infix to prefix
string infix_to_prefix(string &infix) {
    // Step 1: Reverse the infix expression
    reverse(infix.begin(), infix.end());
    // Step 2: Replace '(' with ')' and vice versa
    for (size_t i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    // Step 3: Get postfix of the modified expression
    string postfix = infix_to_postfix(infix);
    // Step 4: Reverse the postfix expression to get the final prefix expression
    reverse(postfix.begin(), postfix.end());
    return postfix;
}
int main() {
    string infix = "K+L-M*N+(O^P)*W/U/V*T+Q";   
    cout << "Infix Expression: " << infix << endl;
    // Convert infix to postfix
    string postfix = infix_to_postfix(infix);
    cout << "Postfix Expression: " << postfix << endl;
    // Convert infix to prefix
    string prefix = infix_to_prefix(infix);
    cout << "Prefix Expression: " << prefix << endl;
    return 0;
}
