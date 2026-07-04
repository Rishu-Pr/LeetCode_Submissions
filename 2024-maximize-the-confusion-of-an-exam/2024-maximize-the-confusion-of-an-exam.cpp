class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int m_len = 0;

        char ch = 'F';

        for(int i = 0; i < 2; i++){
            int start = 0;
            int count_same = 0;
            int count_diff = 0;
            for(int j = 0; j < answerKey.size(); j++){
                if(answerKey[j] == ch){
                    count_same++;
                }
                else{
                    count_diff++;
                }

                while(count_diff > k){
                    if(answerKey[start] == ch){
                        count_same--;
                    }
                    else{
                        count_diff--;
                    }

                    start++;
                }
                m_len = max(m_len, j - start + 1);
            }
            ch = 'T';
        }

        return m_len;
    }
};