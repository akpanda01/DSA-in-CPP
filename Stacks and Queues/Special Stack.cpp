stack<int> minStack; // Global auxiliary stack to keep track of minimums

void push(stack<int>& s, int a) {
    s.push(a);
    if (minStack.empty() || a <= minStack.top()) {
        minStack.push(a);
    }
}

bool isFull(stack<int>& s, int n) {
    return s.size() == n;
}

bool isEmpty(stack<int>& s) {
    return s.empty();
}

int pop(stack<int>& s) {
    if (s.empty()) return -1;

    int top = s.top();
    s.pop();
    if (!minStack.empty() && top == minStack.top()) {
        minStack.pop();
    }
    return top;
}

int getMin(stack<int>& s) {
    if (minStack.empty()) return -1;
    return minStack.top();
}
