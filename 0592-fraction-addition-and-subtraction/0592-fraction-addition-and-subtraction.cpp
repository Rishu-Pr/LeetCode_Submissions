class Solution {
public:
    int LCM(vector<int>& d){
        int res = 1;
        for(int i = 0; i < d.size(); i++){
            res = lcm(res, d[i]);
        }
        return res;
    }
    string fractionAddition(string expression) {
        vector<int> N;
        vector<int> D;

        for(int i = 0; i < expression.size(); ){
            int s = 1;
            int n = 0;
            int d = 0;
            if(expression[i] == '-'){
                s *= -1;
                i++;
            }
            else if(expression[i] == '+'){
                i++;
            }
            while(expression[i] != '/'){
                n *= 10;
                n += (expression[i] - '0');
                i++;
            }
            i++;
            while(i != expression.size() && (expression[i] != '-' && expression[i] != '+')){
                d *= 10;
                d += (expression[i] - '0');
                i++;
            }

            N.push_back(n * s);
            D.push_back(d);
        }

        int lcmV = LCM(D);
        for(int j = 0; j < D.size(); j++){
            N[j] = N[j] * (lcmV / D[j]);
        }

        int sum = 0;
        for(int x : N){
            sum += x;
        }
        
        for(int j = max(sum, lcmV); j > 1 ; j--){
            if(lcmV % j == 0 && sum % j == 0){
                lcmV /= j;
                sum /= j;
            }
        }

        if(sum == 0){
            return "0/1";
        }
        else if(lcmV == 1){
            return (to_string(sum) + "/1");
        }

        return to_string(sum) + "/" + to_string(lcmV);
    }
};