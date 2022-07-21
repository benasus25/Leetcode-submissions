/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int run = 1;
        ListNode* temp = NULL, *curr = head;
        while(run<left){
            temp = curr;
            curr = curr->next;
            run++;
        }
        ListNode*temp1 = curr, *prev = NULL, *next = curr->next;
        while(run<=right){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            run++;
        }
        //cout<<curr->val<<"  "<<prev->val<<endl;
        if(left!=1)temp->next= prev;
        else head = prev;
        temp1->next = curr;
        return head;
    }
};