#include <vector>

class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];

        // Step 1: Calculate sequential prefix sum starting from index 0
        for (int j = 1; j < n; j++) {
            if (nums[j] == nums[j - 1] + 1) {
                sum += nums[j];
            } else {
                break;
            }
        }

        // Step 2: Check for existence using raw loop index comparison
        for (int k = 0; k < n; k++) {
            if (nums[k] == sum) {
                sum = sum + 1; // Increment if sum is found in nums
                k = -1;        // Reset loop to scan from the beginning again (k++ makes it 0)
            }
        }

        return sum;
    }
};