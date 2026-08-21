class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = 0;
        while(num2){
            if(num2 % 2){
                count++;
            }
            num2 >>= 1;
        }

        vector<int> V;
        int powr = 0;
        while(num1 && count){
            if(num1 % 2){
                V.push_back(powr);
            }
            num1 >>= 1;
            powr++;
        }

        int ans = 0;
        int idx = V.size() - 1;
        while(count && idx >= 0){
            ans += pow(2, V[idx]);
            idx--;
            count--;
        }
        if(count){
            idx = 0;
            int cntr = 0;
            V.push_back(INT_MAX);
            while(count){
                if(cntr != V[idx]){
                    ans += pow(2, cntr);
                    count--;
                }
                else{
                    idx++;
                }
                cntr++;
            }
        }
        return ans;
    }
};