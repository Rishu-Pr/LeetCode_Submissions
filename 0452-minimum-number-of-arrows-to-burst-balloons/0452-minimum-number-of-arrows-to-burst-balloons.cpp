class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() < 2) return 1;
         sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });


        int num_arr = 1;
        int curr = points[0][1];

        for(int i = 1; i < points.size(); i++){
            if(points[i][0] > curr){
                num_arr++;
                curr = points[i][1];
            }
        }

        return num_arr;
    }
};