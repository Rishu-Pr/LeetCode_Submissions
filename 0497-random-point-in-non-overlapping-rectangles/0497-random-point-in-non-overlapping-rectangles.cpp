class Solution {
    mt19937 gen;
    int genRan(int l, int r){
        uniform_int_distribution<> distr(l, r);

        return distr(gen);
    }
public:
    vector<vector<int>> V;
    vector<int> weight;
    Solution(vector<vector<int>>& rects) {
        V = rects;
        for(int i = 0; i < V.size(); i++){
            int xPt = abs(V[i][0] - V[i][2]) + 1;
            int yPt = abs(V[i][1] - V[i][3]) + 1;
            weight.push_back(xPt * yPt);
        }
        for(int i = 1; i < V.size(); i++){
            weight[i] += weight[i - 1];
        }
    }
    
    vector<int> pick() {
        int n = V.size();
        int chc = genRan(0, weight.back() - 1);
        int idx = 0;
        while(chc >= weight[idx]){
            idx++;
        }
        
        int btm_l_x = V[idx][0];
        int btm_l_y = V[idx][1];
        int top_r_x = V[idx][2];
        int top_r_y = V[idx][3];
        
        int x = genRan(btm_l_x, top_r_x);
        int y = genRan(btm_l_y, top_r_y);

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */