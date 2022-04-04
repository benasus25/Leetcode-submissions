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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head, *fast = head;
        int count=1;
        while(fast->next){
            fast = fast->next;
            count++;
        }
        if(k>count/2){
            k= count-k+1;
        }
        fast = head;
        count = count-k;
        k-=1;
        while(fast->next&&k--){
            fast= fast->next;
        }
        while(slow->next && count--){
            slow = slow->next;
        }
        int temp2= slow->val;
        slow->val= fast->val;
        fast->val = temp2;
        return head;
    }
};