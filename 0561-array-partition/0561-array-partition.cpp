class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> cnt(20002);
        for(int x : nums){
            cnt[x + 1e4]++;
        }

        int ans = 0;
        int count = 0;
        for(int i = 0; i < cnt.size(); i++){
            while(cnt[i]){
                if(!(count % 2)){
                    ans += i - 1e4;
                }
                cnt[i]--;
                count++;
            }
        }

        return ans;
    }
};