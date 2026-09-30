class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
         unordered_map<int, int> map;
        for (int num : barcodes) {
            map[num]++;
        }

        priority_queue<pair<int, int>> pq;

        for (auto const& [element, count] : map) {
            pq.emplace(count, element);
        }

        vector<int> ans;
        while(pq.size() >= 2){
            pair<int, int> p1 = pq.top();
            pq.pop();
            pair<int, int> p2 = pq.top();
            pq.pop();

            ans.push_back(p1.second);
            ans.push_back(p2.second);
            p1.first--;
            p2.first--;

            if(p1.first > 0){
                pq.push(p1); 
            }
            if(p2.first > 0){
                pq.push(p2);
            }
        }
        if(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }

        return ans;
    }
};