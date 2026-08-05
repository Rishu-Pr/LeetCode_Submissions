class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> map;
        for(int i = 0; i < rectangles.size(); i++){
            double val = (double)rectangles[i][0] / (double)rectangles[i][1];
            map[val]++;
        }

        long long sum = 0;

        for (auto i = map.begin(); i != map.end(); i++){
            long long cnt = i->second;
            sum += cnt * (cnt - 1) / 2;
        }
        return sum;
    }
};