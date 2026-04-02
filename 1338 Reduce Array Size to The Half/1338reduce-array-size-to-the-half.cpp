class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> map1;
        for(int x : arr) map1[x]++;

        vector<int> freq;
        for (auto &p : map1) {
            freq.push_back(p.second);
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int num_int = 0;
        int size = arr.size()/2;
        int idx = 0;
        while(size > 0) {
            num_int++;
            size -= freq[idx++];
        }

        return num_int;
    }
};