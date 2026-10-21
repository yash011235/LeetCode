#include <string>
#include <algorithm>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.length();
        
        // Case 0: Already sorted
        if (std::is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        // Case -1: Cannot sort a string of length 2 if it's unsorted
        if (n == 2) {
            return -1;
        }
        
        char min_char = *std::min_element(s.begin(), s.end());
        char max_char = *std::max_element(s.begin(), s.end());
        
        // Case 1: An extreme element is already perfectly positioned
        if (s[0] == min_char || s[n - 1] == max_char) {
            return 1;
        }
        
        // Case 3: Worst case (Max is ONLY at the start AND Min is ONLY at the end)
        // We check if min_char exists in s[0...n-2] or max_char exists in s[1...n-1]
        bool min_in_interior = false;
        bool max_in_interior = false;
        
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == min_char) min_in_interior = true;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == max_char) max_in_interior = true;
        }
        
        if (s[0] == max_char && s[n - 1] == min_char && !min_in_interior && !max_in_interior) {
            return 3;
        }
        
        // Case 2: All other combinations (like "jgg")
        return 2;
    }
};
