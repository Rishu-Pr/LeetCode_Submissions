class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minidx = 0, maxidx = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[maxidx]){
                maxidx = i;
            }
            if(nums[i] < nums[minidx]){
                minidx = i;
            }
        }

        int i = min(minidx, maxidx);
        int j = max(minidx, maxidx);

        int ll = max(i, j) + 1;
        int rr = n - min(i, j);
        int lr = i + 1 + n - j;

        return min(ll, min(rr, lr));
    }
};