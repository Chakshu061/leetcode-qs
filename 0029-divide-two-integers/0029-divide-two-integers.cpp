class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0, sign = dividend > 0 == divisor > 0 ? 1 : -1;
        if (divisor == -2147483648) return dividend == divisor;
        if (dividend == -2147483648)
            if (divisor == 1) return -2147483648;
            else if (divisor == -1) return 2147483647;
            else dividend += abs(divisor), ans++;
        dividend = abs(dividend), divisor = abs(divisor);
        for (int i = 0; dividend >= divisor; i = 0) {
            while (dividend >> i >= divisor) i++;
            dividend -= divisor << i - 1, ans += 1 << i - 1;
        }
        return sign < 0 ? -ans : ans;
    }
};