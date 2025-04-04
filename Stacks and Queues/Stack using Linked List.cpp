class MyStack {
  private:
    StackNode* top;

  public:
    MyStack() { 
        top = nullptr; 
    }

    // Push operation
    void push(int x) {
        StackNode* newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
    }

    // Pop operation
    int pop() {
        if (top == nullptr) return -1; // Stack is empty

        int poppedValue = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;

        return poppedValue;
    }
};
