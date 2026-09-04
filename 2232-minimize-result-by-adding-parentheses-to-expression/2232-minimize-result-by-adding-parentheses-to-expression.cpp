class Solution {
public:
    string minimizeResult(string expression) {
        int minV = INT_MAX;
        string minS = "";

        int i = 0;
        while(expression[i] != '+'){
            i++;
        }
        int lcntr = i - 1;
        int rcntr = i + 1;
        
        for(int t = lcntr; t >= 0; t--){
            for(int k = rcntr; k < expression.size(); k++){
                string mL = (expression.substr(0, t));
                string mR = (expression.substr(k + 1));
                int val_mL = mL.empty() ? 1 : stoi(mL);
                int val_mR = mR.empty() ? 1 : stoi(mR);

                string sumL = (expression.substr(t, i - t));
                string sumR = (expression.substr(i + 1, k - i));
                
                int tVal = val_mL * (stoi(sumL) + stoi(sumR)) * val_mR;
                if(minV > tVal){
                    minV = tVal;
                    minS = mL + "(" + sumL + "+" + sumR + ")" + mR;
                }
            }
        }

        return minS;
    }
};