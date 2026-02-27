class Solution {
public:
    void swap(vector<char>& str, int i, int j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    void reverse_Str(vector<char>& str, int i, int j) {
        if (i > j)
            return;

        swap(str, i, j);
        reverse_Str(str, i + 1, j - 1);
    }
    void reverseString(vector<char>& s) {
        reverse_Str(s,0,s.size()-1);
    }
};