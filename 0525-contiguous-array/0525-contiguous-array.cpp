class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(!nums[i]){
                nums[i] = -1;
            }
        }
        vector<int> V = {0};
        for(int i = 0; i < n; i++){
            V.push_back(V[i] + nums[i]);
        }

        int maxL = 0;
        unordered_map<int, int> map;
        for(int i = 0; i < n + 1; i++){
            if(!map.count(V[i])){
                map[V[i]] = i;
            }
            else{
                maxL = max(maxL, i - map[V[i]]);
            }
        }

        return maxL;
    }
};