stack<int> push(vector<int> &arr) {
    stack<int> s;
    for (int val : arr) {
        s.push(val);
    }
    return s;
}

void pop(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
