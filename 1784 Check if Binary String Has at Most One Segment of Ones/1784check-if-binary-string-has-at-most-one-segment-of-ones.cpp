class Solution {
public:
    bool checkOnesSegment(string s) {
        int ans =  -1;
        for(int i=1;i<s.size();i++){
            if(s[i]=='0') ans=1;
            if(s[i]=='1' && ans==1) return false;
        }
        return true;
    }
};