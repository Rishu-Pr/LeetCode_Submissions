class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> Vcol;
        vector<int> Vrow;

        for(int i=0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    Vrow.push_back(i);
                    Vcol.push_back(j);
                }
            }
        }
        for(int i : Vrow){
            for(int j=0 ; j<matrix[0].size();j++){
                matrix[i][j]=0;
            }
        }
        for(int i : Vcol){
            for(int j=0 ; j<matrix.size();j++){
                matrix[j][i]=0;
            }
        }
    }
};