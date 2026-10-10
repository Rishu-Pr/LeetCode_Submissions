class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = k1 + k2;
        long long t_diff = 0;
        int max_Diff = 0;

        vector<int> diff(n);
        for(int i = 0; i < n; i++){
            diff[i] = abs(nums1[i] - nums2[i]);
            t_diff += diff[i];
            max_Diff = max(max_Diff, diff[i]);
        }

        if(t_diff < k){
            return 0;
        }
        vector<int> bucket(max_Diff + 1, 0);
        for(int x : diff){
            bucket[x]++;
        }

        for(int i = max_Diff; i > 0 && k > 0; i--){
            long long maxV = min((long long)bucket[i], k);
            bucket[i] -= maxV;
            bucket[i - 1] += maxV;
            k -= maxV;
        }

        long long ans = 0;
        for(int i = 0; i <= max_Diff; i++){
            ans += (i * 1ll * i) * bucket[i];
        }

        return ans;
    }
};