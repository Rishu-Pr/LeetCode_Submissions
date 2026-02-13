class Solution {
public:
    int start = 0, end = 0, size = 0;
    void checkPalin(string s, int st, int e)
    {
        int left = st;
        int right = e;
        
        while (left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        
        if (right - left + 1 > size){
            start = left;
            end = right;
            size = right - left + 1;
        }
    }

    string longestPalindrome(string s){

        for (int i = 0; i < s.length(); i++){
            checkPalin(s, i, i);
            checkPalin(s, i, i + 1);
        }
        return s.substr(start + 1, size - 2);
    }
};