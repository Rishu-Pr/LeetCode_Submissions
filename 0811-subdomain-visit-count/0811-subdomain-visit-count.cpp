class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> map;
        for(string str : cpdomains){
            string num = "";
            int size = str.size();
            int i = 0;
            while(str[i] >= '0' && str[i] <= '9'){
                num += str[i++];
            }

            int freq = stoi(num);
            string strtemp = str.substr(i + 1);
            map[strtemp] += freq;
            
            while(i < size && str[i] != '.'){
                i++;
            }
            i++;
            strtemp = str.substr(i);
            map[strtemp] += freq;

            while(i < size && str[i] != '.'){
                i++;
            }
            i++;
            if(i < size){
                strtemp = str.substr(i);
                map[strtemp] += freq;
            }
        }

        vector<string> S;
        for (const auto& [key, value] : map) {
            S.push_back(to_string(value) + " " + key);
        }

        return S;
    }
};