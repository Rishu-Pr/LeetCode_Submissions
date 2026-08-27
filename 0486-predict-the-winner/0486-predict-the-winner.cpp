class Solution {
    bool solve(int l, int r, int p1, int p2, int turn, vector<int>& nums){
        if(l > r){
            return p1 >= p2;
        }
        
        bool takeL = false, takeR = false;
        if(turn){
            takeL = solve(l + 1, r, p1 + nums[l], p2, 0, nums);
            takeR = solve(l, r - 1, p1 + nums[r], p2, 0, nums);
            return (takeL || takeR);
        }
        else{
            takeL = solve(l + 1, r, p1, p2 + nums[l], 1, nums);
            takeR = solve(l, r - 1, p1, p2 + nums[r], 1, nums);
            return (takeL && takeR);
        }
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        if(nums.size() == 1){
            return true;
        }
        return solve(0, nums.size() - 1, 0, 0, 1, nums);
    }
};