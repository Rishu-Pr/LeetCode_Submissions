class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> Ans;
        for(int i = 0; i < asteroids.size(); i++){
            if(Ans.empty()) Ans.push_back(asteroids[i]);

            else if(Ans.back() > 0 && asteroids[i] < 0){
                int num = asteroids[i];
                int flag = 0;
                while(!Ans.empty() && num < 0 && Ans.back() > 0){
                    int t = Ans.back();
                    Ans.pop_back();

                    if(t == -num){
                        flag = 1; 
                        break;
                    }
                    else if(t > - num) num = t;
                }
                if(!flag) Ans.push_back(num);
            }

            else Ans.push_back(asteroids[i]);
        }
        return Ans;
    }
};