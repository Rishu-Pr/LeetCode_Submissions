class Solution {
    int getLength(vector<int>& p1, vector<int>& p2){
        int dx = p1[0] - p2[0];
        int dy = p1[1] - p2[1];
        return dx * dx + dy * dy;
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> l(6);
        l[0] = getLength(p1,p2); 
        l[1] = getLength(p1,p3); 
        l[2] = getLength(p1,p4); 
        l[3] = getLength(p2,p3); 
        l[4] = getLength(p2,p4); 
        l[5] = getLength(p3,p4);

        sort(l.begin(),l.end());

        if(l[0] == l[1] && l[1] == l[2] && l[2] == l[3] && l[3] != l[4] && l[4] == l[5]) return true;
        return false;
    }
};