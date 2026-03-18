class Solution
{
    int facto(int x)
    {
        int multi = 1;
        for (int i = 2; i <= x; i++) multi *= i;

        return multi;
    }

public:
    string getPermutation(int n, int k)
    {
        string temp = "";
        for (int i = 1; i <= n; i++)
            temp = temp + char(i + '0');

        int x = 1;
        while (k > facto(x)) x++;

        int idx = n - x;
        while (k != 1)
        {
            int idx_next = idx + 1;
            int fact_num = facto(x - 1);
            while (k > fact_num)
            {
                k -= fact_num;
                swap(temp[idx], temp[idx_next]);
                idx_next++;
            }
            idx++;
            x--;
        }
        return temp;
    }
};