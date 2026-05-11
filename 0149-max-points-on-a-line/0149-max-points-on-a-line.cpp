class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n < 3) return n;

        int maxpt = 2;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int count = 2;
                for(int k = 0; k < n; k++){
                    if( k != i && k != j){
                        int dy1 = points[k][1]-points[j][1];
                        int dx1 = points[j][0]-points[i][0];
                        int dy2 = points[j][1]-points[i][1];
                        int dx2 =points[k][0]-points[j][0];
                        if(dy1 * dx1 == dy2 * dx2)
                            count++;
                    }
                }
                maxpt = max(count,maxpt);
            }
        }

        return maxpt;
    }
};