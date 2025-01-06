//Palindrome Check

class Solution{	
	public:		
		
		bool palindromeCheck(string& s){
			//your code goes here
			string original = s;
			int start = 0; 
			int end = s.size()-1; 
	
			while(start < end){ 
				swap(s[start], s[end]);
				start++; 
				end--; 
			} 
			if(s==original){
				return true;
			}else{
				return false;
			}
		}
};
