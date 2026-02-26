class Solution {
public:
    string complexNumberMultiply(string num1, string num2)
    {
        int real1 = 0, real2 = 0, complex1 = 0, complex2 = 0;

        int i = 0;
        int isneg = 1;
        if (num1[i] == '-')
        {
            isneg = -1;
            i++;
        }
        while (num1[i] != '+')
        {
            real1 = real1 * 10 + (num1[i++] - '0');
        }
        real1 *= isneg;
        i++;

        isneg = 1;
        if (num1[i] == '+' || num1[i] == '-')
        {
            if (num1[i] == '-')
                isneg = -1;
            i++;
        }
        while (num1[i] != 'i')
        {
            complex1 = complex1 * 10 + (num1[i] - '0');
            i++;
        }
        complex1 *= isneg;

        i = 0;
        isneg = 1;
        if (num2[i] == '-')
        {
            isneg = -1;
            i++;
        }
        while (num2[i] != '+')
        {
            real2 = real2 * 10 + (num2[i++] - '0');
        }
        real2 *= isneg;
        i++;

        isneg = 1;
        if (num2[i] == '+' || num2[i] == '-')
        {
            if (num2[i] == '-')
                isneg = -1;
            i++;
        }
        while (num2[i] != 'i')
        {
            complex2 = complex2 * 10 + (num2[i] - '0');
            i++;
        }
        complex2 *= isneg;
        string ans = to_string(real1 * real2 - complex1 * complex2) + "+" + to_string(real1 * complex2 + complex1 * real2) + "i";
        return ans;
    }
};