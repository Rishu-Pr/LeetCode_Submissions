class Solution {
    
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int x = 1;
        int y = 2;
        for(int i = 0; i < n-2;i++){
            if(x>y) y+=x;
            else x+=y;
        }
        return max(x,y);
    }
};