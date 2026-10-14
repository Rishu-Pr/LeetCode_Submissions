class Solution {
    struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        // A common way to combine hashes
        return h1 ^ (h2 << 1); 
    }
};
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<pair<int,int>, int, pair_hash> row;
        unordered_map<pair<int,int>, int, pair_hash> col;
        vector<vector<int>> V(9, vector<int>(9, 0));

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int val = board[i][j] - '0' - 1;
                    if(row.count({val, i}) || col.count({val, j})){
                       return false;
                    }
                    int idx = (i / 3) + ((j / 3) * 3) + 1;
                    if(V[val][idx - 1] == 1){
                        return false;
                    }
                    row[{val, i}] = 1;
                    col[{val, j}] = 1;
                    V[val][idx - 1] = 1;
                }
            }
        }

        return true;
    }
};