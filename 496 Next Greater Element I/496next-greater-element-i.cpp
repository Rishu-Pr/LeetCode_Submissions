class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
    for(int i = 0;i<nums1.size();i++){
        int j = 0;
        while(j<nums2.size() && nums2[j]!=nums1[i]){
            j++;
        }
        int max = j+1;
        while(max<nums2.size() && nums2[max]<nums2[j]){
            max++;
        }
        nums1[i] = (max==nums2.size())?-1:nums2[max];
    }
    return nums1;
}
};