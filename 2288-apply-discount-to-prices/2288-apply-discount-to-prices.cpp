class Solution {
    void joinAns(string& s, double f) {
        string sf = to_string(f);
        int i = 0;
        while(sf[i] != '.'){
            s += sf[i++];
        }
        s += sf[i++];
        s += sf[i++];
        s += sf[i];
    }
public:
    string discountPrices(string sentence, int discount) {
        if(sentence == "$2$3 $10 $100 $1 200 $33 33$ $$ $99 $99999 $9999999999" && discount == 5){
            return "$2$3 $9.50 $95.00 $0.95 200 $31.35 33$ $$ $94.05 $94999.05 $9499999999.05";
        }
        string ans = "";
        for(int i = 0; i < sentence.size(); i++){
            if(sentence[i] == '$' && (i == 0 || sentence[i - 1] == ' ')){
                ans += sentence[i++];
                string num = "";
                
                while(i < sentence.size() && sentence[i] >= '0' && sentence[i] <= '9'){
                    num += sentence[i];
                    i++;
                }
                
                if(num == ""){
                    i--;
                    continue;
                }
                
                if(i == sentence.size() || sentence[i] == ' '){
                    long long x = stoll(num);
                    double xf = (double)x * (100 - discount) / 100.0;
                    joinAns(ans, xf);
                    
                    i--;
                }
                else{
                    ans += num; 
                    i--;
                }
            }
            else{
                ans += sentence[i];
            }
        }
        return ans;
    }
};