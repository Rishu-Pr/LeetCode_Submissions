class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> Ans(n, 0);    
        unordered_map<int, int> hm1;

        for(int i = 0; i < n; i++) hm1[A[i]] = i;

        for(int idxB = 0 ; idxB < n; idxB++){
            int idxA = hm1[B[idxB]];
            int maxIdx = max(idxA, idxB);
            Ans[maxIdx] += 1;
        }

        int curr_Val = 0;
        for(int i = 0; i < n; i++){
            Ans[i] += curr_Val;
            curr_Val = Ans[i];
        }

        return Ans;
    }
};