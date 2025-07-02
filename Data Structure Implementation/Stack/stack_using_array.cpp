#include<iostream>
using namespace std;

class Stack {
    int *arr;
    int capacity;
    int topIndex;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push operation
    void push(int value) {
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = value;
    }

    // Pop operation
    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        topIndex--;
    }

    // Top operation
    int top() {
        if (topIndex == -1) {
            cout << "Stack is Empty\n";
            return -1; // or throw exception
        }
        return arr[topIndex];
    }

    // Check if stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Check current size
    int size() {
        return topIndex + 1;
    }
};

int main() {
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top Element: " << st.top() << endl; // 30

    st.pop();
    cout << "Top after pop: " << st.top() << endl; // 20

    cout << "Size: " << st.size() << endl; // 2

    return 0;
}
