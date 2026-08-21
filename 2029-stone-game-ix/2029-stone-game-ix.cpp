class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int mod0 = 0;
        int mod1 = 0;
        int mod2 = 0;

        for(int x : stones){
            if(x % 3 == 0){
                mod0++;
            }
            else if(x % 3 == 1){
                mod1++;
            }
            else{
                mod2++;
            }
        }

        if(mod0 % 2 == 0){
            if(mod1 > 0 && mod2 > 0){
                return true;
            }
        }
        else{
            if(mod1 - mod2 > 2 || mod2 - mod1 > 2){
                return true;
            }
        }
        return false;
    }
};