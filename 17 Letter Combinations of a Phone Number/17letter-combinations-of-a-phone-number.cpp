class Solution {
    void getAns(vector<string> &Ans,string& temp,string data[],string digits,int index){
        if(index >= digits.length()){
            Ans.push_back(temp);
            return;
        }
        for(int i=0;i < data[digits[index] - '0'].length();i++){
            temp.push_back(data[digits[index] - '0'][i]);
            getAns(Ans,temp,data,digits,index+1);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> Ans;
        if(digits.empty()) return Ans;
        string data[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string temp = "";
        getAns(Ans,temp,data,digits,0);
        return Ans;
    }
};