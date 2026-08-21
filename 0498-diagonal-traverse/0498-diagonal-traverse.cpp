class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        int trR = 0, trC = 0;
        vector<int> V;
        for(int i = 0; i < row * col; i++){
            int val = mat[trR][trC];

            if((trR + trC) % 2 == 0){
                if(trC == col - 1){
                    trR++;
                }
                else if(trR == 0){
                    trC++;
                }
                else{
                    trR--;
                    trC++;
                }
            }
            else{
                if(trR == row - 1){
                    trC++;
                }
                else if(trC == 0){
                    trR++;
                }
                else{
                    trR++;
                    trC--;
                }
            }
            V.push_back(val);
        }

        return V;
    }
};