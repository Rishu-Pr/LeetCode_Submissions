class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> ans;
        for(int i=1 ; i<=n ; i++) ans.push_back(i);

        int ptr = 0;

        while(ans.size()>1){
            ptr = (ptr+k-1)%ans.size();
            ans.erase(ans.begin()+ptr);
        }

        return ans[0];
    }
};