class Solution {
    bool isPalid(string s){
        int st = 0;
        int ed = s.size() - 1;
        while(st < ed){
            if(s[st] != s[ed]){
                return false;
            }
            st++;
            ed--;
        }
        return true;
    }
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        string ans = "z";
        for(int i = 0; i < n; i++){
            ans += 'z';
        }
        string ifBreak = ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 26; j++){
                string temp = palindrome;
                temp[i] = ((((temp[i] - 'a') + j) % 26) + 'a');
                if(!isPalid(temp) && temp < ans){
                    ans = temp;
                }
            }
            
        }
        if(ans == ifBreak){
            return "";
        }
        return ans;
    }
};