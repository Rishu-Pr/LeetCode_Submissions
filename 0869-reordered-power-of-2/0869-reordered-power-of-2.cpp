class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<long long> V;
        long long i = 1;
        while(i < 1.5 * 1e9){
            V.push_back(i);
            i *= 2;
        }

        vector<vector<int>> temp;
        for(int i = 0; i < V.size(); i++){
            vector<int> t;
            int x = V[i];
            while(x){
                t.push_back(x % 10);
                x /= 10;
            }
            sort(t.begin(), t.end());
            temp.push_back(t);
        }

        vector<int> ans;
        while(n){
            ans.push_back(n % 10);
            n /= 10;
        }
        sort(ans.begin(), ans.end());

        for(int i = 0; i < temp.size(); i++){
            if(ans == temp[i]){
                return true;
            }
        }

        return false;
    }
};