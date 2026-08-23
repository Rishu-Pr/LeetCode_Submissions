class Solution {
public:
    bool sumGame(string num) {
        int leftsum = 0;
        int left_blank = 0;
        int rightsum = 0;
        int right_blank = 0;

        int idx1 = num.size() / 2;
        for(int i = 0; i < idx1; i++){
            if(num[i] == '?'){
                left_blank++;
            }
            else{
                leftsum += (num[i] - '0');
            }
        }
        for(int i = idx1; i < num.size(); i++){
            if(num[i] == '?'){
                right_blank++;
            }
            else{
                rightsum += (num[i] - '0');
            }
        }

        if(left_blank - right_blank == 0){
            return (!(leftsum == rightsum));
        }
        if((left_blank + right_blank) % 2){
            return true;
        }
        else{
            int netblank = left_blank - right_blank;
            int netsum = leftsum - rightsum;
            if((netblank*netsum < 0) && (abs(netblank) / 2) * 9 == abs(netsum)){
                return false;
            }
            return true;
        }
    }
};