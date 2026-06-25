class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        
        int ans_size = 1e6;
        int left_ptr = 0;
        int right_ptr = 0;
        int curr_sum = nums[0];

        while(left_ptr < size){
            if(right_ptr == size - 1 && curr_sum < target) break;

            else if(curr_sum >= target){
                ans_size = min(ans_size, right_ptr - left_ptr + 1);
                if(left_ptr == right_ptr) return 1;
                else{
                    curr_sum -= nums[left_ptr];
                    left_ptr++;
                }
            }

            else if(curr_sum < target){
                right_ptr++;
                curr_sum += nums[right_ptr];
            }
        }

        return (ans_size == 1e6) ? 0 : ans_size;
    }
};