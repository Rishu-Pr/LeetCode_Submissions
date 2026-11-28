class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0){
            return (n * (n + 1)) / 2;
        }
        vector<int> idxOdd = {-1};
        for(int i = 0; i < n; i++){
            if(nums[i] % 2){
                idxOdd.push_back(i);
            }
        }

        idxOdd.push_back(n);

        if(idxOdd.size() - 2 < k){
            return 0;
        }

        int kCnt = 1;
        int beg = 0;
        int firstIdx = 1;
        int lastIdx = 1;
        while(kCnt < k){
            lastIdx++;
            kCnt++;
        }
        int end = lastIdx + 1;

        int cnt = 0;

        for(int i = 0; i < n && end < idxOdd.size(); i++){
            cnt += (idxOdd[firstIdx] - idxOdd[beg]) * (idxOdd[end] - idxOdd[lastIdx]);
            firstIdx++;
            lastIdx++;
            beg++;
            end++;
        }

        return cnt;
    }
};