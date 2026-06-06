#define MOD 1000000007
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int idx1 = 0;
        int idx2 = 0;

        long long sum1 = 0;
        long long sum2 = 0;

        while(idx1 < nums1.size() && idx2 < nums2.size()){
            if(nums1[idx1] < nums2[idx2]){
                sum1 += nums1[idx1];
                idx1++;
            }
            else if(nums1[idx1] > nums2[idx2]){
                sum2 += nums2[idx2];
                idx2++;
            }
            else{
                long long maxVal = max(sum1, sum2) + nums1[idx1];
                sum1 = maxVal;
                sum2 = maxVal;

                idx1++;
                idx2++;
            }
        }

        while(idx1 < nums1.size()){
            sum1 += nums1[idx1];
            idx1++;
        }
        
        while(idx2 < nums2.size()){
            sum2 += nums2[idx2];
            idx2++;
        }

        return max(sum1, sum2) % MOD;
    }
};