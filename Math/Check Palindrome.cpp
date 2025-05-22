class Solution {
public:
    bool isPalindrome(int n) {
        int temp = n;
        int revNum=0;
        while(n!=0){
            int digit = n%10;
            revNum = revNum * 10 + digit;
            n = n/10;
        }
        return revNum == temp;

    }
};
