class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n1 = INT_MAX;
        int n2 = INT_MAX;

        for(int x : nums){
            if(x <= n1){
                n1 = x;
            }
            else if(x <= n2){
                n2 = x;
            }
            else{
                return true;
            }
        }

        return false;
    }
};