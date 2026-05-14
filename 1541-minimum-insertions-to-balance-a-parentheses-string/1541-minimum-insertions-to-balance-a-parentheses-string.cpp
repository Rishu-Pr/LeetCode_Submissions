class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int close_req = 0;

        for(char c : s){
            if(c == '('){
                close_req += 2;
                if(close_req % 2){
                    ans++;
                    close_req--;
                }
            }
            else{
                close_req--;
                if(close_req < 0){
                    ans++;
                    close_req = 1;
                }
            }
        }

        return ans + close_req;
    }
};