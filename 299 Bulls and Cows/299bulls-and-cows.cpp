class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int cow = 0, bull = 0;
        int i = 0;
        while (i < secret.size() && i < guess.size())
        {
            if (secret[i] == guess[i])
            {
                bull++;
                secret[i] = '*';
                guess[i] = '*';
            }
            i++;
        }

        i = 0;
        int j = 0;
        vector<int> vec1(10, 0);
        vector<int> vec2(10, 0);

        while (i < secret.size())
        {
            if (secret[i] != '*') vec1[secret[i] - '0']++;
            i++;
        }
        while (j < guess.size())
        {
            if (guess[j] != '*') vec2[guess[j] - '0']++;
            j++;
        }

        i = 0;
        while (i < vec1.size())
        {
            if (vec1[i]) cow += min(vec1[i],vec2[i]);
            i++;
        }
        string Ans = "";
        Ans += to_string(bull);
        Ans += 'A';
        Ans += to_string(cow);
        Ans += 'B';

        return Ans;
    }
};