#include <vector>

class Solution {
private:
    int MOD = 1e9 + 7;
    std::vector<std::vector<int>> table;

    int dfs(const std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        int root = nums[0];
        std::vector<int> left, right;
        left.reserve(n);
        right.reserve(n);

        // Partition elements into left and right subtrees
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        // Recursively compute permutations for subtrees
        long long left_ways = dfs(left);
        long long right_ways = dfs(right);

        // Combine subtrees: C(n - 1, left_size) * left_ways * right_ways
        long long total_ways = (table[n - 1][left.size()] * left_ways) % MOD;
        return (total_ways * right_ways) % MOD;
    }

public:
    int numOfWays(std::vector<int>& nums) {
        int n = nums.size();
        
        // Precompute Pascal's Triangle for combination lookup
        table.assign(n, std::vector<int>(n, 1));
        for (int i = 2; i < n; ++i) {
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }

        // Subtract 1 to remove the original arrangement array
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};
