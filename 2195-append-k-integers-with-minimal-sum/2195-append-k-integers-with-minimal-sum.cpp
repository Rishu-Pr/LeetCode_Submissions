class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int i = 0;
        while(i < nums.size() && k > 0){
            if(i > 0 && nums[i] == nums[i - 1]){
                i++;
                continue;
            }
            if(i == 0){
                if((nums[i] - 1) >= k){
                    sum += (k) * 1ll * (k + 1) / 2;
                    k = 0;
                }
                else{
                    sum += (nums[i] - 1) * 1ll * nums[i] / 2;
                    k -= (nums[i] - 1);
                }
            }
            else{
                if(nums[i] - 1 - nums[i - 1] >= k){
                    long long s1 = (nums[i - 1] + k) * 1ll * (nums[i - 1] + k + 1) / 2;
                    long long s2 = (nums[i - 1] + 1) * 1ll * nums[i - 1] / 2;
                    k = 0;
                    sum += (s1 - s2);
                }
                else{
                    long long s1 = (nums[i] - 1) * 1ll * nums[i] / 2;
                    long long s2 = (nums[i - 1] + 1) * 1ll * nums[i - 1] / 2;
                    k -= (nums[i] - 1 - nums[i - 1]);
                    sum += (s1 - s2);
                }
            }
            i++;
        }
        if(k > 0){
            long long s1 = (nums.back() + k) * 1ll * (nums.back() + k + 1) / 2;
            long long s2 = nums.back() * 1ll * (nums.back() + 1) / 2;
            sum += (s1 - s2);
        }

        return sum;
    }
};