class Solution {
public:
int countHillValley(vector<int>& nums) {
    int count = 0, a = 0, b = 0;
    for (int c : nums) {
        if (c != b) {
            if (a > 0 && (a < b) == (b > c))
                ++count;
            a = b;
            b = c;
        }
    }
    return count;
}
};