class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int size = mat[0].size();
        k = k % size;

        for(int i = 0 ;i < mat.size() ;i++){
            int idx1 = 0, idx2 = 0;
            if(i % 2){
                idx2 = (size - k) % size;
                for(int t = 0; t<size; t++){
                    if(mat[i][idx1++] != mat[i][(idx2++) % size])
                        return false;
                }
            }
            else{
                idx2 = k % size;
                for(int t = 0; t<size; t++){
                    if(mat[i][idx1++] != mat[i][(idx2++) % size])
                        return false;
                }
            }
        }

        return true;
    }
};