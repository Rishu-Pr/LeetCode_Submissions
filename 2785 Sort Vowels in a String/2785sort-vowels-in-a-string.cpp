class Solution {
public:
    string sortVowels(string s) {
        priority_queue<char,vector<char>,greater<char>> q;
        vector<int> idx;
        for(int i=0 ; i < s.size() ; i++){
            char c = s[i];
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
                q.push(c);
                idx.push_back(i);
            }
        }
        
        int i=0;
        while(!q.empty()){
            s[idx[i++]] = q.top();
            q.pop();
        }

        return s;
    }
};