class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        vector<int> count_wrd;
        for(string str : messages){
            if(str.size() == 0){
                count_wrd.push_back(0);
            }
            else{
                int count = 1;
                for(char c : str){
                    if(c == ' '){
                        count++;
                    }
                }
                count_wrd.push_back(count);
            }
        }
        unordered_map<string, int> map;
        for(int i = 0; i < messages.size(); i++){
            map[senders[i]] += count_wrd[i];
        }
        auto maxIt = max_element(map.begin(), map.end(),
            [](const auto& p1, const auto& p2) {
                if (p1.second == p2.second) {
                    return p1.first < p2.first; 
                }
                return p1.second < p2.second;
            }
        );

        return maxIt->first;
    }
};