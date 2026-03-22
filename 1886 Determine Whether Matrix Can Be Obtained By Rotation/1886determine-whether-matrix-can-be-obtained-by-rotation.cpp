class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int ans = 1;
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[i][j]){
                    ans=0;
                    break;
                }
            }
            if(!ans) break;
        }
        if(ans) return true;
    
        ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[j][n-1-i]){
                    ans=0;
                    break;
                }
            }
            if(!ans) break;
        }
        if(ans) return true;
    
        ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[n-1-i][n-1-j]){
                    ans=0;
                    break;
                }
            }
            if(!ans) break;
        }
        if(ans) return true;
    
        ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[n-1-j][i]){
                    ans=0;
                    break;
                }
            }
            if(!ans) break;
        }
        if(ans) return true;

        return false;
    }
};