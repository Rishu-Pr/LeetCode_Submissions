class Solution {
    void solve(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& temp, int idx){
        if(idx == graph.size() - 1){
            temp.push_back(idx);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp.push_back(idx);
        for(int x : graph[idx]){
            solve(graph, ans, temp, x);
        }
        temp.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp = {0};
        
        for(int i = 0; i < graph[0].size(); i++){
            solve(graph, ans, temp, graph[0][i]);
        }

        return ans;
    }
};