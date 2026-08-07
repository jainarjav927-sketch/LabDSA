#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MAX 100

class Stack
{
private:
    int arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX - 1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (isEmpty())
            return -1;
        return arr[top];
    }
};

int evaluatePostfix(string exp)
{
    Stack s;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        // Ignore spaces
        if (ch == ' ')
            continue;

        // Operand
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        // Operator
        else
        {
            int op2 = s.pop();
            int op1 = s.pop();

            switch (ch)
            {
            case '+':
                s.push(op1 + op2);
                break;
            case '-':
                s.push(op1 - op2);
                break;
            case '*':
                s.push(op1 * op2);
                break;
            case '/':
                s.push(op1 / op2);
                break;
            case '%':
                s.push(op1 % op2);
                break;
            default:
                cout << "Invalid Operator!" << endl;
                return -1;
            }
        }
    }

    return s.pop();
}

int main()
{
    string postfix;

    cout << "Enter Postfix Expression (single-digit operands): ";
    getline(cin, postfix);

    cout << "Result = " << evaluatePostfix(postfix) << endl;

    return 0;
}