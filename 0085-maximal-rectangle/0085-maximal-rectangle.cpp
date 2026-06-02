class Solution {

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> intMatrix(row, vector<int>(col, 0));

        
        int ans = 0;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                intMatrix[i][j] = (matrix[i][j] == '1') ? 1 : 0;
        
        for(int i = 0; i < row; i++){
            if(i != 0){
                for(int j = 0; j < col; j++)
                    intMatrix[i][j] = (intMatrix[i][j] == 0) ? 0 : intMatrix[i][j] + intMatrix[i - 1][j];
            }

            stack<int> stk;
            for(int j = 0; j < col; j++){
                while(!stk.empty() && intMatrix[i][j] < intMatrix[i][stk.top()]){
                    int idx = stk.top(); 
                    stk.pop();
                    ans = max(ans, intMatrix[i][idx] * ((stk.empty()) ? j : j - stk.top() - 1));
                }
                stk.push(j);
            }
            while(!stk.empty()){
                int idx = stk.top(); stk.pop();
                ans = max(ans, intMatrix[i][idx] * ((stk.empty()) ? col : col - stk.top() - 1));
            }
        }

        return ans;
    }
};