class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;

        queue<pair<int, bool>> q;
        q.push({1, false});
        q.push({2, true});
        q.push({5, true});
        q.push({6, true});
        q.push({8, false});
        q.push({9, true});

        vector<int> valid_num = {0, 1, 2, 5, 6, 8, 9};
        vector<bool> is_valid = {false, false, true, true, true, false, true};

        while(!q.empty()){
            auto [num, is_true] = q.front();
            q.pop();

            if(num > n) continue;
            if(is_true) count++;

            for(int i = 0; i < valid_num.size(); i++){
                int next = num * 10 + valid_num[i];
                if(next <= n){
                    int is_allowed = is_true || is_valid[i];
                    q.push({next, is_allowed});
                }
            }
        }

        return count;
    }
};
