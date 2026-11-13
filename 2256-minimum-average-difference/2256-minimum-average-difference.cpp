class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long n = nums.size();
        if (n == 1) {
            return 0;
        }

        vector<long long> prefV(n, 0);
        long long sum = 0;
        for (int x : nums) {
            sum += x;
        }

        long long sumC = sum;
        for (int i = 0; i < n; i++) {
            prefV[i] = sum;
            sum -= nums[i];
        }

        long long minDiff = LLONG_MAX;
        int ans = 0;

        for (int i = 1; i < n; i++) {
            long long num1 = prefV[i];
            long long num2 = sumC - num1;

            long long diff = abs((num2 / i) - (num1 / (n - i)));
            if (diff < minDiff) {
                minDiff = diff;
                ans = i - 1;
            }
        }

        long long lastDiff = sumC / n;
        if (lastDiff < minDiff) {
            ans = n - 1;
        }

        return ans;
    }
};