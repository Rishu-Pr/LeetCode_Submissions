class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        if(n < 3) return n-1;

        int lines = 1;
        sort(stockPrices.begin(),stockPrices.end());

        for(int i = 0; i < stockPrices.size() - 2; i++){
            long dx1 = stockPrices[i + 1][0] - stockPrices[i][0];
            long dx2 = stockPrices[i + 2][0] - stockPrices[i + 1][0];
            long dy1 = stockPrices[i + 1][1] - stockPrices[i][1];
            long dy2 = stockPrices[i + 2][1] - stockPrices[i + 1][1];

            if(dx1 * dy2 != dx2 * dy1) lines++;
        }

        return lines;
    }
};