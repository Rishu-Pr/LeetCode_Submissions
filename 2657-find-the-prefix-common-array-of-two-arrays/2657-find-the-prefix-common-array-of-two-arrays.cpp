class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> Ans;
        int n = A.size();

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j <= i; j++)
                for(int k = 0; k <= i; k++)
                    if(A[j] == B[k]) cnt++;

            Ans.push_back(cnt);
        }

        return Ans;
    }
};