class Solution {
public:
    int maximumSwap(int num) {
        int orig = num;
        vector<int> temp;
        while(num){
            temp.push_back(num % 10);
            num /= 10;
        }
        
        int max_idx = 0; 
        int swap_left = -1; 
        int swap_right = -1; 
        
        for (int i = 1; i < temp.size(); i++) {
            if (temp[i] < temp[max_idx]) {
                swap_left = i;
                swap_right = max_idx;
            }
            else if (temp[i] > temp[max_idx]) {
                max_idx = i;
            }
        }
        
        if (swap_left == -1) return orig;
        
        swap(temp[swap_left], temp[swap_right]);

        int ans = 0;
        for(int i = temp.size() - 1; i >= 0; i--){
            ans *= 10;
            ans += temp[i];
        }

        return ans;
    }
};