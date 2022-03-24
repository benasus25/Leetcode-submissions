class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int j = people.size()-1,i=0;
        //while(people[j]>limit)j--;
        int count = 0;
        while(i<=j){
            if(people[j]+people[i]>limit){
                count++;
                j--;
            }
            else{
                i++;
                j--;
                count++;
            }
        }
        return count;
    }
};