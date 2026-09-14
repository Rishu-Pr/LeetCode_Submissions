class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int front = 0;
        int back = n - 1;
        int cnt = 0;

        while(front < back){
            int sum = nums[front] + nums[back];
            if(sum < k){
                front++;
            }
            else if(sum > k){
                back--;
            }
            else{
                cnt++;
                front++;
                back--;
            }
        }

        return cnt;
    }
};