class Solution {
public:
    string simplifyPath(string path) {
        vector<string> V;
        string str = "";
        path += "/";
        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/'){
                if(str.size() == 0){
                    continue;
                }
                else if(str == "."){
                }
                else if(str == ".."){
                    if(V.size()){
                        V.pop_back();
                    }
                }
                else{
                    V.push_back(str);
                }
                str = "";
                while(i < path.size() && path[i] == '/'){
                    i++;
                }
                i--;
            }
            else{
                str += path[i];
            }
        }

        if(V.size() == 0){
            return "/";
        }
        string ans = "";
        for(string s : V){
            ans += "/";
            ans += s;
        }

        return ans;
    }
};