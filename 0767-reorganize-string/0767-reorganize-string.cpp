class Solution {
public:
    string reorganizeString(string s) {
        int size = s.size();
        vector<int> V(26, 0);
        for(char c : s){
            V[c - 'a']++;
            if(V[c - 'a'] > (size + 1) / 2){
                return "";
            }
        }

        priority_queue<pair<int, char>> maxHeap;
        for(int i = 0; i < 26; i++) {
            if(V[i] > 0) {
                maxHeap.push({V[i], i + 'a'});
            }
        }

        string ans = "";

        while(maxHeap.size() > 1){
            pair<int, char> p1 = maxHeap.top();
            maxHeap.pop();

            pair<int, char> p2 = maxHeap.top();
            maxHeap.pop();

            ans += p1.second;
            ans += p2.second;

            if(p1.first - 1){
                p1.first = p1.first - 1;
                maxHeap.push(p1);
            }
            if(p2.first - 1){
                p2.first = p2.first - 1;
                maxHeap.push(p2);
            }

        }
        while(!maxHeap.empty()){
            pair<int, char> p = maxHeap.top();
            maxHeap.pop();
            ans += p.second;
        }

        return ans;
    }
};