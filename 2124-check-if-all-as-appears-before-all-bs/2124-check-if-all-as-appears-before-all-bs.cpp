class Solution {
public:
    bool checkString(string s) {
        int getb = 0;
        for(int i = 0; i < s.size(); i++){
            if(getb && s[i] == 'a'){
                return false;
            }
            if(s[i] == 'b'){
                getb = 1;
            }
        }
        return true;
    }
};