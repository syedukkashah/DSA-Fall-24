#include "iostream"
#include "cctype"
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
    void print() {
        for (int i = 0; i <= top; i++) cout << arr[i] << " ";
    }
};
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
int main() {
    string infix = "(100 * (2 + 12)) / 14";
    string output = ""; 
    Stack s(infix.size());

    for (char c : infix) {
        if (isalnum(c)) {
            output += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                output += s.pop();
            }
            s.pop(); 
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                output += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        output += s.pop();
    }
    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << output << endl;
    return 0;
}
