class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) {
        int l = 0, r = 0, n = ans.size();
        int tr = 0, fal = 0, len = 1;
        while(r<n){
            if(ans[r]=='T')tr++;
            else fal++;
            while(fal>k and tr>k){
                if(ans[l]=='T')tr--;
                else fal--;
                l++;
            }
            len = max(len,r-l+1);
            r++;
        }
        return len;
    }
};