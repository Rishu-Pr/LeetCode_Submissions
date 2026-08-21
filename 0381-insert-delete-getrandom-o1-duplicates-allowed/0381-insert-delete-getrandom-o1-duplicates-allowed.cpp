class RandomizedCollection {
public:
    unordered_map<int, int> V;
    int n;
    RandomizedCollection() {
        n = 0;
    }
    
    bool insert(int val) {
        bool ans = false;
        if(V.count(val) == 0){
            ans = true;
        }
        V[val]++;
        n++;
        return ans;
    }
    
    bool remove(int val) {
        if(V.count(val) && V[val] > 1){
            V[val]--;
            n--;
            return true;
        }
        else if(V.count(val) && V[val] == 1){
            V.erase(val);
            n--;
            return true;
        }

        return false;
    }
    
    int getRandom() {
        int ans = 0;
        int ran = 1 + (rand() % n);
        for(const auto pair : V){
            if(ran <= 0){
                break;
            }
            ans = pair.first;
            ran -= pair.second;
        }

        return ans;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */