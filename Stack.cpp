#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX = 100;
    int top;
    char items[MAX];

public:
    Stack() {
        top = -1;
    }

    void push(char elements) {
        if (top == MAX - 1) {
            cout << "stack overflow, cannot push " << elements << endl;
        } else {
            items[++top] = elements;
            cout << "element '" << elements << "' pushed to stack" << endl;
        }
    }

    char pop() {
        if (top == -1) {
            cout << "stack empty, cannot pop" << endl;
            return '\0';
        } else {
            char removeditem = items[top--];
            cout << "element '" << removeditem << "' popped from stack" << endl;
            return removeditem;
        }
    }
};

int main(int argc, char** argv) {
    Stack stack;

    stack.push('j');
    stack.push('k');
    stack.push('l');
    stack.push('m');
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}
