class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int maxArea=0;
        int size = heights.size();

        int i = 0;
        while(i < size){
            if(stk.empty() || heights[i] > heights[stk.top()]) stk.push(i++);

            else{
                int tp = stk.top();
                stk.pop();
                int width = (stk.empty()) ? i : i-stk.top()-1 ;
                int area = heights[tp]*width;
                if(area>maxArea) maxArea = area;
            }
        }

        while(!stk.empty()){
            int tp = stk.top();
            stk.pop();
            int width = (stk.empty()) ? i : i-stk.top()-1 ;
            int area = heights[tp]*width;
            if(area>maxArea) maxArea = area;
        }

        return maxArea;
    }
};