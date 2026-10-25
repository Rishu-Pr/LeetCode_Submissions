class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int i = 1;
        unordered_map<int, int> map;
        for(int x : nums){
            map[x]++;
        }
        for(int i = 1; i < 101; i++){
            if(!map.count(i * k)){
                return i * k;
            }
        }
        return 101 * k;
    }
};