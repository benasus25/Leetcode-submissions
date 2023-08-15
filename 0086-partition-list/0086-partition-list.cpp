class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(-1), *great = new ListNode(-1), *ptr = head;
        ListNode* less_head = less, *great_head = great;
        
        while(ptr){
            if(ptr->val<x){
                less->next = ptr, less = less->next;
            }
            else{
                great->next = ptr, great = great ->next;
            }
            ptr = ptr->next;
        }
        great->next = NULL;
        less->next = great_head->next;
        return less_head->next;
    }
};