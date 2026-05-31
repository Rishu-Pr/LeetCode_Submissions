class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        if(mass < asteroids[0]) return false;
        asteroids[0] += mass;
        if(asteroids.size() > 1 && asteroids[0] < asteroids[1]) return false;

        for(int i = 1; i < asteroids.size() - 1; i++){
            if(asteroids[i - 1] > 100000 || asteroids[i - 1] > asteroids.back()) return true;
            asteroids[i] += asteroids[i - 1];
            if(asteroids[i] < asteroids[i + 1]) return false;
        }

        return true;
    }
};