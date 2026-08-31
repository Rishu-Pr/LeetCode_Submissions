class Solution {
public:
    int minDeletions(string s) {
        vector<int> V(26, 0);
        for(char c : s){
            V[c - 'a']++;
        }

        vector<int> Nums;
        
        for(int x : V){
            if(x){
                Nums.push_back(x);
            }
        }

        sort(Nums.begin(), Nums.end());
        int chng = 0;
        for(int i = Nums.size() - 1; i > 0; i--){
            if(Nums[i] <= Nums[i - 1] && Nums[i] == 0){
                chng += Nums[i - 1];
                Nums[i - 1] = 0;
            }
            else if(Nums[i] <= Nums[i - 1]){
                chng += Nums[i - 1] - Nums[i] + 1;
                Nums[i - 1] = Nums[i] - 1;
            }
        }

        return chng;
    }
};