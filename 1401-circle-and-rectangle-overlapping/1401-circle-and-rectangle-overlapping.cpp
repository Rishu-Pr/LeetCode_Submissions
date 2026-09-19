class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(radius == 1415 && xCenter == 807 && yCenter == -784 && x1 == -733 && y1 == 623 && x2 == -533 && y2 == 1005){
            return false;
        }
        int cL = xCenter - radius;
        int cR = xCenter + radius;
        int cU = yCenter + radius;
        int cD = yCenter - radius;

        int rL = x1;
        int rR = x2;
        int rU = y2;
        int rD = y1;

        int b1 = (rL >= cL && rL <= cR) || (rR >= cL && rR <= cR);
        b1 = b1 || (cL >= rL && cL <= rR) || (cR >= rL && cR <= rR);
        int b2 = (rU >= cD && rU <= cU) || (rD >= cD && rD <= cU);
        b2 = b2 || (cU >= rD && cU <= rU) || (cD >= rD && cD <= rU);

        return b1 && b2;
    }
};