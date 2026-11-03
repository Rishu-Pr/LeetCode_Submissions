class Solution {
public:
    long long maxScore(vector<int>& nums) {
        long long maxV = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            long long HCF = 0;
            long long LCM = 1;
            
            for(int j = 0; j < nums.size(); j++){
                if(i != j){
                    HCF = gcd(HCF, (long long)nums[j]);
                    LCM = lcm(LCM, (long long)nums[j]);
                }
            }
            
            maxV = max(maxV, HCF * LCM);
        }
        
        long long HCF = 0;
        long long LCM = 1;
        for(int j = 0; j < nums.size(); j++){
            HCF = gcd(HCF, (long long)nums[j]);
            LCM = lcm(LCM, (long long)nums[j]);
        }
        
        return max(maxV, HCF * LCM);
    }
};