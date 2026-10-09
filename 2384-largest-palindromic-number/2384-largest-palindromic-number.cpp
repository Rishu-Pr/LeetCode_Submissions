class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> V(10, 0);
        for(char c : num){
            V[c - '0']++;
        };
        int single = -1;
        for(int i = 9; i >= 0; i--){
            if(V[i] % 2 &&  single == -1){
                single = i;
            }
            if(V[i] > 1 && (V[i] % 2)){
                V[i]--;
            }
        }
        int sum = 0;
        for(int i = 1; i < 10; i++){
            sum += V[i] / 2;
        }
        if(sum == 0){
            if(single != -1){
                return to_string(single);
            }
            else{
                return "0";
            }
        }

        string str = "";
        for(int i = 9; i >= 0; i--){
            int n = V[i] / 2;
            for(int j = 0; j < n; j++){
                if(n != 0){
                    str += (i + '0');
                }
            }
        }
        if(single != -1){
            str += (single + '0');
        }
        for(int i = 0; i < 10; i++){
            int n = V[i] / 2;
            for(int j = 0; j < n; j++){
                if(n != 0){
                    str += (i + '0');
                }
            }
        }

        return str;
    }
};