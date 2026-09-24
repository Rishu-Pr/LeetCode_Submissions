class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int s_End = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(start >= s_End){
                s_End = end;
            }
            else{
                count++;
                s_End = min(s_End, end);
            }
        }

        return count;
    }
};