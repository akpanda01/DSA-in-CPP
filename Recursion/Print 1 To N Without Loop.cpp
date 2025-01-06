//Print 1 To N Without Loop


class Solution {
  public:
    // Complete this function
    int cnt = 1;
    void printNos(int n) {
        // Your code here
        
        if(cnt > n) return ;
        cout << cnt++ << " ";
        
        printNos(n);
    }
};
