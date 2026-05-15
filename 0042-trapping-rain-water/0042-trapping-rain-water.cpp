class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int ans = 0;

        for(int i = height.size() - 1; i >=0 ; i--){
            while(!stk.empty() && height[i] > height[stk.top()]){
                int base = stk.top(); stk.pop();
                if(stk.empty()) break;

                int secHeight = height[stk.top()];
                int width = stk.top() - i - 1;

                ans += (min(height[i],secHeight) - height[base]) * width;
            }
            
            stk.push(i);
        }

        return ans;
    }
};