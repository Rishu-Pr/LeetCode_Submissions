class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<int> V;
        int size = nums[0].length();
        int init = 0;
        string ans = "";

        for (auto str : nums)
            V.push_back(stoi(str, nullptr, 2));

        sort(V.begin(), V.end());

        for (int i = 0; i < V.size(); i++) {
            if (V[i] == init)
                init++;
            else
                break;
        }

        while (init > 0) {
            ans = char('0' + (init % 2)) + ans;
            init /= 2;
            size--;
        }

        while (size > 0) {
            ans = '0' + ans;
            size--;
        }

        return ans;
    }
};