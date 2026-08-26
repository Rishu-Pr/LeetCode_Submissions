class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int count1 = 0;
        int back = 0;
        
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                count1++;
            }
            
            while(count1 > k || count1 == k && s[back] == '0'){
                back++;
                
                if(s[back - 1] == '1'){
                    count1--;
                }
            }

            if(count1 == k){
                string temp = s.substr(back, i - back + 1);
                if(ans.empty()){
                    ans = temp;
                }
                else{
                    if (temp.size() < ans.size() || (temp.size() == ans.size() && temp < ans)){
                        ans = temp;
                    }
                }
            }
        }

        return ans;
    }
};