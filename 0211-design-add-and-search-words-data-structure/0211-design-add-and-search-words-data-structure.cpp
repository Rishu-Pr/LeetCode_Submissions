class WordDictionary {
public:
    vector<string> V;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        V.push_back(word);
    }
    
    bool search(string word) {
        int n = word.size();
        for(int i = 0; i < V.size(); i++){
        if(n != V[i].size()) continue; 
        
        bool ans = true;
        for(int j = 0; j < n; j++){
            if(word[j] != '.'){ 
                if(V[i][j] != word[j]){
                    ans = false;
                    break;
                }
            }
        }
        if(ans){
            return true;
        }
    }

    return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */