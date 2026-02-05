class Solution {
public:
    int mySqrt(int x) {
        int start =0;
        int end = x;
        int root;
        while(start<=end){
            long long int mid = start + (end-start)/2;
            if(mid*mid >x){
                end = mid-1;
            }
            else{
                root = mid;
                start = mid+1;
            }
        }
        return root;
    }
};