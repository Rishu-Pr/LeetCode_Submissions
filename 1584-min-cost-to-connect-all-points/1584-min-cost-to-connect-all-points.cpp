class Solution {
public:
    int findParent(vector<int>& parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = findParent(parent, parent[i]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<pair<pair<int, int>, int>> vec;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                vec.push_back({{i, j}, dist});
            }
        }

        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        vector<int> parent(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i; 
        }

        int ans = 0;

        for(auto& item : vec){
            int parentU = findParent(parent, item.first.first);
            int parentV = findParent(parent, item.first.second);
            
            if(parentU != parentV){
                parent[parentU] = parentV; 
                ans += item.second;
            }
        }

        return ans;
    }
};