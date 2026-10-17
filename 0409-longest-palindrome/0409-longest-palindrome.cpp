class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> small_V(26, 0);
        vector<int> big_V(26, 0);

        for(char c : s){
            if(c <= 'Z'){
                big_V[c - 'A']++;
            }
            else{
                small_V[c - 'a']++;
            }
        }

        int isOdd = 0;
        int cnt = 0;
        for(int x : small_V){
            if(x % 2){
                isOdd = 1;
                cnt += x - 1;
            }
            else{
                cnt += x;
            }
        }

        for(int x : big_V){
            if(x % 2){
                isOdd = 1;
                cnt += x - 1;
            }
            else{
                cnt += x;
            }
        }

        return cnt + isOdd;
    }
};