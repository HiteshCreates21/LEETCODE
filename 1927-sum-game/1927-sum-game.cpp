#include <string>

class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.length();
        int mid = n / 2;
        
        int sumDiff = 0; // sum(left) - sum(right)
        int qmDiff = 0;  // count_?(left) - count_?(right)
        
        // Process left half
        for (int i = 0; i < mid; ++i) {
            if (num[i] == '?') {
                qmDiff++;
            } else {
                sumDiff += (num[i] - '0');
            }
        }
        
        // Process right half
        for (int i = mid; i < n; ++i) {
            if (num[i] == '?') {
                qmDiff--;
            } else {
                sumDiff -= (num[i] - '0');
            }
        }
        
        // Bob wins (returns false) only if he can exactly balance the sum with ? pairs
        return (2 * sumDiff + 9 * qmDiff) != 0;
    }
};