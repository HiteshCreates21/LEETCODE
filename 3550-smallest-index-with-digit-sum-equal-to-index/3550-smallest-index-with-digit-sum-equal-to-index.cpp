#include <vector>
using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int temp = nums[i];
            int sum = 0;

            // Extract each digit and calculate digit sum for nums[i]
            while (temp > 0) {
                int digit = temp % 10;
                sum = sum + digit;
                temp = temp / 10;
            }

            // Check if digit sum equals index i
            if (sum == i) {
                return i; // Immediately returns the smallest matching index
            }
        }

        return -1; // Returned if no index satisfies the condition
    }
};