#include <cmath>

class Solution {
public:
    int reverse(int x) {
        long long rev = 0;  // long long prevents overflow during rev * 10
        int digit = 0;

        while (x != 0) {
            digit = x % 10;
            rev = rev * 10 + digit;
            x = x / 10;
        }

        // Check if rev fits in the signed 32-bit integer range
        if (rev < -pow(2, 31) || rev > pow(2, 31) - 1) {
            return 0;
        }

        return rev;
    }
};