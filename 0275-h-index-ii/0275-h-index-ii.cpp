class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 1 && citations[0] < 1){
            return 0;
        }
        
        int count = 1;

        for(int i = citations.size() - 1; i >= 0; i--){
            if(count <= citations[i]){
                count++;
            }
            else break;
        }

        return (count - 1);
    }
};