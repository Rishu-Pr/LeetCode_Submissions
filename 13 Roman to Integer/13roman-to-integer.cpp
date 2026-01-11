class Solution {
public:
    int romanToInt(string s) {
        int num = 0, leng = (s.length() - 1);

        for (int i = 0; i < leng; i++)
        {
            int curr, next;
            switch (s[i])
            {
            case 'I':
                curr = 1;
                break;
            case 'V':
                curr = 5;
                break;
            case 'X':
                curr = 10;
                break;
            case 'L':
                curr = 50;
                break;
            case 'C':
                curr = 100;
                break;
            case 'D':
                curr = 500;
                break;
            case 'M':
                curr = 1000;
                break;
            }

            switch (s[i + 1])
            {
            case 'I':
                next = 1;
                break;
            case 'V':
                next = 5;
                break;
            case 'X':
                next = 10;
                break;
            case 'L':
                next = 50;
                break;
            case 'C':
                next = 100;
                break;
            case 'D':
                next = 500;
                break;
            case 'M':
                next = 1000;
                break;
            }

            if (curr < next)
                num -= curr;
            else
                num += curr;
        }

        switch (s[leng])
        {
        case 'I':
            num += 1;
            break;
        case 'V':
            num += 5;
            break;
        case 'X':
            num += 10;
            break;
        case 'L':
            num += 50;
            break;
        case 'C':
            num += 100;
            break;
        case 'D':
            num += 500;
            break;
        case 'M':
            num += 1000;
            break;
        }
        cout << num << endl;
        return num;
    }
};