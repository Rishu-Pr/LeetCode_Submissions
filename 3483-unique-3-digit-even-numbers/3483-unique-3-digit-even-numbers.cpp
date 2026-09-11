class Solution {
    int facto(int x){
        if(x <= 1){
            return 1;
        }
        return x * facto(x - 1);
    }
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> V(10);
        for(int i : digits){
            V[i]++;
        }
        
        int ans = 0;
        for(int i = 1; i < 10; i++){
            if(!V[i]) continue;
            V[i]--;
            for(int j = 0; j < 10; j += 2){
                if(!V[j]) continue;
                V[j]--;
                int temp = 0;
                for(int x = 0; x < 10; x++){
                    if(V[x]){
                        temp++;
                    }
                }
                ans += temp;

                V[j]++;
            }
            V[i]++;
        }
        
        return ans;
    }
};