class Solution {
    bool checkStr(string s, string goal, int i){
        int size = s.size();
        int k = 0;
        for(int j = i;j < size; j++){
            if(s[j] == goal[k]) k++;
            else return false;
        }
        for(int j = 0; j < i; j++){
            if(s[j] == goal[k]) k++;
            else return false;
        }
        return true;
    }
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        for(int i = 0; i < goal.size(); i++){
            if(s[i] == goal[0])
                if(checkStr(s, goal, i)) return true;
        }

        return false;
    }
};