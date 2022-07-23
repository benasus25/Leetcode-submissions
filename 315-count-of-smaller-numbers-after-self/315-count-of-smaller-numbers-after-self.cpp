#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>set_t;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        set_t s;
        s.insert(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            int num  = s.order_of_key(nums[i]);
            s.insert(nums[i]);
            ans[i] = num;
        }
        return ans;
    }
};