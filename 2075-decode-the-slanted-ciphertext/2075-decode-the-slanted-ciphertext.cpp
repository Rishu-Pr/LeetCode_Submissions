class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int colm = encodedText.size() / rows;
        string ans = "";
        for(int i = 0; i < colm; i++){
            int row = 0;
            int c = i;
            while(row < rows && c < colm){
                int t = c + row * colm;
                ans += encodedText[t];
                row++;
                c++;
                
            }
        }
        while(!ans.empty() && ans.back() == ' '){
            ans.pop_back();
        }
        return ans;
    }
};