class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area;
        int length1 = ax2 - ax1;
        int width1 = ay2 - ay1;
        int length2 = bx2 - bx1;
        int width2 = by2 - by1;

        int clength = min(ax2,bx2) - max(ax1,bx1);
        int cwidth = min(ay2,by2) - max(ay1,by1);

        if(clength <= 0 || cwidth <= 0) area = 0;
        else area = clength*cwidth;

        return (length1*width1) + (length2*width2) - area;
    }
};