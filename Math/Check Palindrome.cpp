//Check Palindrome

class Solution {
public:

    int revNum(int x){
        int revNum = 0;

        while(x!=0){
            int dig = x%10;

            if(revNum > INT_MAX/10 || revNum < INT_MIN/10 ){
                return 0;
            }

            revNum = revNum * 10 +dig;
            x = x / 10;
        }
       return revNum; 
    }

    bool isPalindrome(int x) {
        if(x<0) return false; //Negative numbers (x < 0) are not palindromes, so the function immediately returns false.
        if(x == revNum(x)){
            return true;

        }else{
            return false;
        }
    }
};

//Edge Case 1 : All single-digit numbers are palindromes.
//Edge Case 2 : Negative numbers (x < 0) are not palindromes.
