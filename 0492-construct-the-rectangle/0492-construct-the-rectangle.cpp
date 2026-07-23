class Solution {
public:
    vector<int> constructRectangle(int area) {
        int leng = sqrt(area);
        while(area % leng){
            leng++;
        }
        int b = area / leng;
        if(leng > b){
            return {leng, b};
        }
        
        return {b, leng};
    }
};