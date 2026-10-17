#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_map>

class Solution {
private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::pair<std::pair<int, int>, int>> originalWithCriteria(n);
        for (int i = 0; i < n; ++i) {
            originalWithCriteria[i] = {{getDigitSum(nums[i]), nums[i]}, nums[i]};
        }
        
       
        std::sort(originalWithCriteria.begin(), originalWithCriteria.end());
        
        std::unordered_map<int, int> elementToTargetIndex;
        for (int i = 0; i < n; ++i) {
            elementToTargetIndex[originalWithCriteria[i].second] = i;
        }
        
        
        std::vector<bool> visited(n, false);
        int totalSwaps = 0;
        
        for (int i = 0; i < n; ++i) {
            if (visited[i] || elementToTargetIndex[nums[i]] == i) {
                continue;
            }
            
            int cycleSize = 0;
            int current_idx = i;
            
            while (!visited[current_idx]) {
                visited[current_idx] = true;
                current_idx = elementToTargetIndex[nums[current_idx]];
                cycleSize++;
            }
            
            if (cycleSize > 0) {
                totalSwaps += (cycleSize - 1);
            }
        }
        
        return totalSwaps;
    }
};
