class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift=0;
        while(right != left){
            shift++;
            left >>= 1;
            right >>= 1;
        }
        return left << shift;
    }
};