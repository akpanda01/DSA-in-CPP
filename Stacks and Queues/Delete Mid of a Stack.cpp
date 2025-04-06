class Solution {
  public:
    void deleteMid(stack<int>& s) {
        int size = s.size();
        deleteMiddleHelper(s, 0, size);
    }

  private:
    void deleteMiddleHelper(stack<int>& s, int current, int size) {
        if (current == size / 2) {
            s.pop();  // Remove the middle element
            return;
        }

        int top = s.top();
        s.pop();
        deleteMiddleHelper(s, current + 1, size);
        s.push(top);  // Push elements back except the middle one
    }
};
