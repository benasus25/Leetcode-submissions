class Solution {
public:
    int numberOfSteps(int num) {
    int count =0;
        while(num){
            if(num==1){
                count+=1;
                break;
            }
            if(num%2){
                count+=2;;
            }
            else{
                count++;
            }   
            num/=2;
        }
    return count;
    }
};