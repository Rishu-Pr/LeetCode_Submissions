class Solution {
public:
    string toPostfix(string s) {
        string strAns = "";
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == ' ')
                continue;
            if (isdigit(ch)) {
                string num = "";
                while (i < s.size() && isdigit(s[i])) {
                    num.push_back(s[i]);
                    i++;
                }
                i--;
                strAns += num + " ";
            } else if (ch == '(') {
                stk.push(ch);
            } else if (ch == ')') {
                while (!stk.empty() && stk.top() != '(') {
                    strAns.push_back(stk.top());
                    strAns.push_back(' ');
                    stk.pop();
                }
                if (!stk.empty())
                    stk.pop();
            } else if (ch == '+' || ch == '-') {
                int prev = i - 1;
                while (prev >= 0 && s[prev] == ' ') {
                    prev--;
                }
                if (prev < 0 || s[prev] == '(') {
                    strAns += "0 ";
                }
                while (!stk.empty() && stk.top() != '(') {
                    strAns.push_back(stk.top());
                    strAns.push_back(' ');
                    stk.pop();
                }
                stk.push(ch);
            }
        }
        while (!stk.empty()) {
            strAns.push_back(stk.top());
            strAns.push_back(' ');
            stk.pop();
        }
        return strAns;
    }
    
    int calculate(string s) {
        s = toPostfix(s);
        if (s.empty())
            return -1;
            
        stack<long long> stk;
        stringstream ss(s);
        string token;
        
        while (ss >> token) {
            if (isdigit(token[0])) {
                stk.push(stoll(token));
            } else {
                long long a = stk.top();
                stk.pop();
                long long b = stk.top();
                stk.pop();
                
                if (token == "+")
                    stk.push(b + a);
                else
                    stk.push(b - a);
            }
        }
        
        return stk.top(); 
    }
};