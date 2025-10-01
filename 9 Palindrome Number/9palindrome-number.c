bool isPalindrome(int x) {
    int len = 0;
    double res = 0;

    for (int j = x; j > 0;j/=10)
    {
        len += 1;
    }

    long int num2 = x;
    for (int i = 0; i < len; i++)
    {
        res += (num2 % 10) * pow(10,(len - 1 - i));
        num2 = num2 / 10;
    }

    return (x == res);
}