class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> V;
        int ans = 0;

        for(int i = height.size() - 1; i >= 0 ; i--){
            while(!V.empty() && height[i] > height[V.back()]){
                int base = V.back(); 
                V.pop_back();
                
                if(V.empty()) break;

                int secHeight = height[V.back()];
                int width = V.back() - i - 1;

                ans += (min(height[i], secHeight) - height[base]) * width;
            }          
            V.push_back(i);
        }
        return ans;
    }
};