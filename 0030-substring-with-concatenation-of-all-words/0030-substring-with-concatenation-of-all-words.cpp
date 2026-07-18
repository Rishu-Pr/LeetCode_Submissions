class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> map_words;
        unordered_map<string, int> map_S;
        int len = words[0].size();
        int size_initial = words.size() * len;
        
        for(int i = 0; i <= s.size() - len; i++){
            string str = s.substr(i, len);
            map_words[str] = 0;
            map_S[str] = 0;
        }

        for(string str : words){
            map_words[str]++;
        }
        
        vector<int> ans;

        for(int strt = 0; strt < len; strt++){
            int front = strt;
            int end = strt + size_initial;
            unordered_map<string, int> map_temp = map_S;

            if (end > s.size()) break;

            for(int i = front; i < end; i += len){
                string str = s.substr(i, len);
                map_temp[str]++;
            }

            while(end <= s.size()){
                if(map_temp == map_words){
                    ans.push_back(front);
                }

                if(end + len > s.size()){
                    break;
                }
                string str = s.substr(end, len);
                map_temp[str]++;
                string str_rem = s.substr(front, len);
                map_temp[str_rem]--;

                front += len;
                end += len;
            }
        }

        return ans;
    }
};