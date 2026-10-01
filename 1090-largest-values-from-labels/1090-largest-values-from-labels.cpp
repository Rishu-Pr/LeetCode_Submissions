class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        long long sum = 0;
        vector<pair<int, int>> map;
        for(int i = 0; i < values.size(); i++){
            map.push_back({values[i], labels[i]});
        }

        sort(labels.begin(), labels.end());
        labels.erase(unique(labels.begin(), labels.end()), labels.end());

        unordered_map<int, int> Freq;
        for(int i : labels){
            Freq[i] = useLimit;
        }
        
        vector<pair<int, int>> vec(map.begin(), map.end());

        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.first > b.first; 
        });

        for (const auto& pair : vec) {
            if(Freq[pair.second] && numWanted){
                sum += pair.first;
                Freq[pair.second]--;
                numWanted--;
            }
        }


        return sum;
    }
};