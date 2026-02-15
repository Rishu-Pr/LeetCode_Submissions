class Solution {
public:
    string addBinary(string a, string b)
    {
        string str_Ans = "";
        int carry = 0;
        int len_a = a.size()-1;
        int len_b = b.size()-1;

        while(len_a>=0||len_b>=0||carry){
            if(len_a>=0) 
                carry += a[len_a--]-'0';
            if(len_b>=0) 
                carry += b[len_b--]-'0';

            str_Ans += carry%2 + '0';
            carry /=2;
        }
        reverse(str_Ans.begin(),str_Ans.end());

        return str_Ans;
    }
};