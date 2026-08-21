class RandomizedSet {
public:
    unordered_map<int, int> V;
    int n;
    RandomizedSet() {
        n = 0;
    }
    
    bool insert(int val) {
        if(V.count(val) == 0){
            V[val] = n;
            n++;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(V.count(val)){
            V.erase(val);
            n--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int rannum = 1 + (rand() % n);
        int ans = 0;
        int count = 0;
        for(const auto pair: V){
            if(count >= rannum){
                break;
            }
            ans = pair.first;
            count++;
        }

        return ans;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */