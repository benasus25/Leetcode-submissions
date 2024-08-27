class Solution {
public:
    int countPairs(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int v1 = nums[i];
                int v2 = nums[j];
                
                if (v1 == v2) {
                    cnt++;
                    continue;
                }
                
                int digits1[4], digits2[4];
                int idx = 0, mismatch = 0;
                
                while (v1 != 0 || v2 != 0) {
                    int d1 = v1 % 10;
                    int d2 = v2 % 10;
                    
                    if (d1 != d2) {
                        if (mismatch < 4) {
                            digits1[mismatch] = d1;
                            digits2[mismatch] = d2;
                        }
                        mismatch++;
                        if (mismatch > 4) break;
                    }
                    
                    v1 /= 10;
                    v2 /= 10;
                }
                
                if (mismatch == 2) {
                    if (digits1[0] == digits2[1] && digits1[1] == digits2[0]) {
                        cnt++;
                    }
                } else if (mismatch == 3) {
                    if ((digits1[0] == digits2[1] && digits2[0] == digits1[2] && digits1[1] == digits2[2]) ||
                        (digits1[1] == digits2[0] && digits1[0] == digits2[2] && digits1[2] == digits2[1])) {
                        cnt++;
                    }
                } else if (mismatch == 4) {
                    if ((digits1[0] == digits2[1] && digits1[1] == digits2[0] && 
                         digits1[2] == digits2[3] && digits1[3] == digits2[2]) || 
                        (digits1[0] == digits2[2] && digits1[2] == digits2[0] &&
                         digits1[1] == digits2[3] && digits1[3] == digits2[1]) ||
                         (digits1[0] == digits2[3] && digits1[3] == digits2[0] &&
                         digits1[1] == digits2[2] && digits1[2] == digits2[1])
                        ) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};