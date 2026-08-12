class Solution {
    bool isSorted(vector<int>& nums){
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]){
                return false;
            }
        }
        return true;
    }
public:
    int nextGreaterElement(int n) {
        
        vector<int> nums;
        while(n > 0){
            nums.push_back(n % 10);
            n /= 10;
        }

        if(isSorted(nums)){
            return -1;
        }
        
        reverse(nums.begin(), nums.end());

        int peakIdx = nums.size() - 1;
        int curr = nums.size() - 2;

        while(curr >= 0 && nums[curr] >= nums[peakIdx]){
            peakIdx = curr;
            curr--;
        }

        int idx1 = peakIdx;
        int idx2 = nums.size() - 1;
        if(curr != -1){
            while(nums[idx2] <= nums[curr] && idx2 > curr){
                idx2--;
            }
            swap(nums[curr], nums[idx2]);
        }
        idx2 = nums.size() - 1;
        while(idx1 < idx2){
            swap(nums[idx1], nums[idx2]);
            idx1++; idx2--;
        }   idx2++;
        
        long long ans = 0;
        for(int x : nums){
            ans *= 10;
            ans += x;
        }

        return (ans > INT_MAX) ? -1 : ans;
    }
};