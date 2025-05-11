class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
    int length = s.size();
    for(int i=0;i<length;i++){
        if(s[i]>='a' && s[i]<='z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >='0' && s[i] <='9'){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                ans += s[i] + 32;
            }
        	else{
        	    ans += s[i];
        	}
		}
        
    }
    int left = 0;
    int right = ans.length() - 1;
    while(left<=right){
    	
        if(ans[left] != ans[right]){
            return false;
        }
        left++;
        right--;
    }
	return true;
    }
};