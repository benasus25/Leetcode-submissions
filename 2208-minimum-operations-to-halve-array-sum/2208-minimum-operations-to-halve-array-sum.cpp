class Solution {
public:
    int halveArray(vector<int>& nums) {
        double n= nums.size(),count=0,sum =0;;
        priority_queue<double>pq;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pq.push(nums[i]);
        }
        double res = sum/2;
        while(res<sum){
            double num = pq.top();
            pq.pop();
            sum-=num/2;
            pq.push(num/2);
            count++;
        }
    return count;
    }
};