class Solution {
public:
    int characterReplacement(string s, int k) {
        int length = 0;

        for(int i = 0; i < 26; i++){
            char chr = 'A' + i;
            int same_chr = 0;
            int diff_chr = 0;

            int start = 0;
            
            for(int end = 0; end < s.size(); end++){
                if(s[end] == chr){
                    same_chr++;
                }
                else{
                    diff_chr++;
                }


                while(diff_chr > k){
                    if(s[start] == chr){
                        same_chr--;
                    }
                    else{
                        diff_chr--;
                    }
                    start++;
                }
                length = max(length, end - start + 1);
            }
        }

        return length;
    }
};