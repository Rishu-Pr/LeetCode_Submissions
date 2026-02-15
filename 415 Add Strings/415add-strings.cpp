class Solution {
public:
    string addStrings(string num1, string num2) {
        string Ans="";
        int carry = 0;
        int len_num1 = num1.size()-1;
        int len_num2 = num2.size()-1;

        while(len_num1>=0||len_num2>=0||carry){
            if(len_num1>=0)
                carry += num1[len_num1--]-'0';
            if(len_num2>=0)
                carry += num2[len_num2--]-'0';

            Ans += carry%10 + '0';
            carry /= 10;
        }
        reverse(Ans.begin(),Ans.end());
        return Ans;
    }
};