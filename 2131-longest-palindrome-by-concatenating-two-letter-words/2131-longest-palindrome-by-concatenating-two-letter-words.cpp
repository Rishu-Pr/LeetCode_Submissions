class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int cnt = 0;
        unordered_map<string, int> map;
        for(string str : words){
            map[str]++;
        }

        int isOdd = 0;
        for(auto& [s,V] : map){
            if(s[0] == s[1]){
                if(V % 2){
                    isOdd = 2;
                    cnt += 2 * (V - 1);
                }
                else{
                    cnt += 2 * V;
                }
            }
            else{
                string temp = {s[1], s[0]};
                int val = map.count(temp) ? map[temp] : 0;
                int minV = min(V, val);
                cnt += 4 * minV;
                map[s] -= minV;
                if(map.count(temp)) map[temp] -= minV;
            }
        }

        return cnt + isOdd;
    }
};