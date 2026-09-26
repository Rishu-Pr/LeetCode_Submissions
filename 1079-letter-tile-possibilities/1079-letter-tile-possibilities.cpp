class Solution {
     void choose(string& tiles, set<string>& mySet, int cnt, string temp){
        if(cnt < 0){
            return;
        }
        for(int i = 0; i < tiles.size(); i++){
            char c = tiles[i];
            if(c != '*'){
                temp.push_back(c);
                tiles[i] = '*';
                choose(tiles, mySet, cnt - 1, temp);
                tiles[i] = c;
                mySet.insert(temp);
                temp.pop_back();
            }
        }
        
     }
public:
    int numTilePossibilities(string tiles) {
        set<string> mySet;
        string temp = "";
        choose(tiles, mySet, tiles.size(), temp);
        return mySet.size();
    }
};