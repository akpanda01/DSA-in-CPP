class MyStack {
private:
    int arr[1000];  // Array to store stack elements
    int top;        // Top index of the stack

public:
    MyStack() { top = -1; } // Constructor initializes top as -1

    // Function to push an element onto the stack
    void push(int x) {
        if (top < 999) { // Ensure stack does not overflow
            arr[++top] = x;
        }
    }

    // Function to pop an element from the stack
    int pop() {
        if (top == -1) {
            return -1; // Stack is empty
        }
        return arr[top--];
    }
};
