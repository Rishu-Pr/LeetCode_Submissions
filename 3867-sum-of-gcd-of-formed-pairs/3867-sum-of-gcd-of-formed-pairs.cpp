class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);

        int maxNum = -1;
        for(int i = 0; i < n; i++){
            maxNum = max(maxNum, nums[i]);
            prefix[i] = gcd(maxNum, nums[i]);
        }

        sort(prefix.begin(), prefix.end());
        int front = 0;
        int back = n - 1;

        long long ans = 0;
        while(front < back){
            ans += gcd(prefix[front], prefix[back]);
            front++;
            back--;
        }

        return ans;
    }
};