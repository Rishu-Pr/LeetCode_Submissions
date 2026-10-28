class Trie {
public:
    unordered_map<string, int> V;
    Trie() {
        
    }
    void insert(string word) {
        V[word]++;
    }
    
    bool search(string word) {
        for(auto& [K, Val] : V){
            if(K == word){
                return true;
            }
        }
        return false;
    }
    bool startsWith(const string& mainStr, const string& prefix) {
        if (prefix.size() > mainStr.size()) return false;    
        return mainStr.compare(0, prefix.length(), prefix) == 0;
    }
    bool startsWith(string prefix) {
        for(auto& [K, Val] : V){
            if(startsWith(K, prefix)){
                return true;
            }
        }
        
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */