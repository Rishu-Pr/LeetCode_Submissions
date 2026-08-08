class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int sizeA1 = arr1.size();
        int sizeA2 = arr2.size();
        vector<int> bArr;
        vector<int> sArr;
        if(sizeA1 > sizeA2){
            bArr = arr1;
            sArr = arr2;
        }
        else{
            sArr = arr1;
            bArr = arr2;
        }
        for(int i = sArr.size() - 1; i >= 0; i--){
            int rem = 0;
            int bit = sArr[i];
            if(bit == 0){
                continue;
            }
            int offset = bArr.size() - sArr.size();
            int bIdx = i + offset;
            bArr[bIdx] += bit;
            if(bArr[bIdx] == 2){
                bArr[bIdx] = 0;
                rem = -1;
            }
            for(int j = bIdx - 1; j >= 0; j--){
                bArr[j] = bArr[j] + rem;

                if(bArr[j] == 2){
                    bArr[j] = 0;
                    rem = -1;
                }
                else if(bArr[j] == 1){
                    rem = 0;
                }
                else if(bArr[j] == -1){
                    bArr[j] = 1;
                    rem = 1;
                }
                else{
                    rem = 0;
                }
            }
            if (rem != 0) {
                vector<int> temp = bArr;
                reverse(temp.begin(), temp.end());
                if(rem == 1){
                    temp.push_back(1);
                }
                if(rem == -1){
                    temp.push_back(1);
                    temp.push_back(1);
                }
                reverse(temp.begin(), temp.end());
                bArr = temp;
            }
        }

        int start = 0;
        while (start < bArr.size() - 1 && bArr[start] == 0) {
            start++;
        }
        bArr.erase(bArr.begin(), bArr.begin() + start);

        return bArr;
    }
};