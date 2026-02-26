class Solution {
public:
    int numSteps(string s) {

        int count = 0;

        while(!(s.length() == 1 && s[0] == '1'))
        {
            if( s.back() == '0') s.pop_back();
            else{
                s.back() = '0';
                int carry = 1;
                for(int j = s.length() - 2; j>=0; j--)
                {    
                    if(s[j] == '1' && carry == 1) s[j] = '0';

                    else if(s[j] == '0' && carry == 1)
                    {
                        s[j] = '1';
                        carry = 0;
                        break;
                    }
                    
                }
               if(carry == 1) s.insert(0,"1");
            }
            count++;
        }
        return count;
    }
};