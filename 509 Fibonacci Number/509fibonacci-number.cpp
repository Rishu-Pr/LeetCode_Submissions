class Solution {
public:
    int fib(int n) {

        if (n == 1)
            return 1;

        int next = 0, x = 0, y = 1;

        for (int i = 1; i < n; i++) {
            next = x + y;
            x = y;
            y = next;
        }

        return next;
    }
};