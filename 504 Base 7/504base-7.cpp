class Solution {
public:
    string convertToBase7(int num) {
        if(num==0) return "0";
        int isneg=0;
        string ans="";
        if(num<0){
            num*=-1;
            isneg=1;
        }
        while(num>0){
            ans = (char)('0' + (num%7)) + ans;
            num/=7;
        }
        if(isneg) ans = '-'+ans;
        return ans;
    }
};