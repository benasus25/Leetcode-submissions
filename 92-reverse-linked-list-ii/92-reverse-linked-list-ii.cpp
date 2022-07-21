class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        int cnt = 0;
        
        while(curr != NULL){
            cnt++;
            if(cnt == left){
                
                ListNode* inner_curr = curr;
                ListNode* inner_prev = NULL;
                
                while(cnt <= right){
                    ListNode* nextptr = inner_curr->next;
                    inner_curr->next = inner_prev;
                    inner_prev = inner_curr;
                    inner_curr = nextptr;
                    cnt++;
                }
                
                if(prev != NULL){
                    prev->next = inner_prev;
                }
                else{
                    head = inner_prev;
                }
                curr->next = inner_curr;
                
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};