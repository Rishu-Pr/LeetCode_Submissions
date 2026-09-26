class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> q;
        if(a) q.push({a, 'a'});
        if(b) q.push({b, 'b'});
        if(c) q.push({c, 'c'});

        string ans = "";
        while(q.size() > 1){
            pair<int, char> p1 = q.top();
            q.pop();
            int s1 = min(2, p1.first);

            pair<int, char> p2 = q.top();
            q.pop();
            int s2 = min(2, p2.first);

            if(p1.first > p2.first){
                s2 = 1; 
            }

            if(!ans.empty() && ans.back() == p1.second){
                for(int i = 0; i < s2; i++)
                    ans += p2.second;
                for(int i = 0; i < s1; i++)
                    ans += p1.second;
            }
            else{
                for(int i = 0; i < s1; i++)
                    ans += p1.second;
                for(int i = 0; i < s2; i++)
                    ans += p2.second;
            }

            if(p1.first - s1){
                p1.first = p1.first - s1;
                q.push(p1);
            }
            if(p2.first - s2){
                p2.first = p2.first - s2;
                q.push(p2);
            }
        }

        if(!q.empty()){
            pair<int, char> p = q.top();
            q.pop();
            if(ans.empty() || ans.back() != p.second){
                int s = min(2, p.first);
                for(int i = 0; i < s; i++){
                    ans += p.second;
                }
            }
        }

        return ans;
    }
};