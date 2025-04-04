// Function to push an element into the stack.
void insert(stack<int> &s, int x) {
    s.push(x);
}

// Function to remove top element from stack.
void remove(stack<int> &s) {
    if (!s.empty()) {
        s.pop();
    }
}

// Function to print the top element of stack.
void headOf_Stack(stack<int> &s) {
    if (!s.empty()) {
        cout << s.top() << " " << endl;
    }
}

// Function to search an element in the stack.
bool find(stack<int> s, int val) {
    while (!s.empty()) {
        if (s.top() == val) {
            return true;
        }
        s.pop();
    }
    return false;
}
