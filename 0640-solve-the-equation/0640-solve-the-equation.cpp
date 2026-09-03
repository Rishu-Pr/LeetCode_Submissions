class Solution {
public:
    string solveEquation(string equation) {
        int left = 0;
        int right = 0;
        int lVar = 0;
        int rVar = 0;
        
        int i = 0;
        while(equation[i] != '='){
            int s = 1;
            int num = 0;
            bool hasNum = false;

            if(equation[i] == '-'){
                s *= -1;
                i++;
            }
            else if(equation[i] == '+'){
                i++;
            }
            while(equation[i] >= '0' && equation[i] <= '9'){
                num *= 10;
                num += (equation[i] - '0');
                hasNum = true;
                i++;
            }
            if(equation[i] == 'x'){
                if(!hasNum){
                    lVar += s;
                }
                else{ 
                    lVar += (s * num);
                }
                i++;
            }
            else{
                left += (s * num);
            }
        }
        i++;
        while(i < equation.size()){
            int s = 1;
            int num = 0;
            bool hasNum = false;

            if(equation[i] == '-'){
                s *= -1;
                i++;
            }
            else if(equation[i] == '+'){
                i++;
            }
            while(i < equation.size() && equation[i] >= '0' && equation[i] <= '9'){
                num *= 10;
                num += (equation[i] - '0');
                hasNum = true;
                i++;
            }
            if(i < equation.size() && equation[i] == 'x'){
                if(!hasNum){
                    rVar += s;
                }
                else{
                    rVar += (s * num);
                }
                i++;
            }
            else{ 
                right += (s * num);
            }
        }

        left -= right;
        rVar -= lVar;
        if(rVar == 0){
            if(left != 0){
                return "No solution";
            }
            return "Infinite solutions";
        }
        if(left == 0){
            if(rVar == 0){
                return "Infinite solutions";
            }
            else{
                return "x=0";
            }
        }
        return ("x=" + to_string(left/rVar));
    }
};