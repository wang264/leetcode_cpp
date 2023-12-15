// Counting Factors of 5

class Solution {
public:
    int trailingZeroes(int n) {
        int zero_count =0;
        for (int i=5; i<=n; i+=5) {
            int current_factor = i;
            while (current_factor % 5 == 0) {
                zero_count++;
                current_factor /=5;
            }
        }
        return zero_count;
    }
};