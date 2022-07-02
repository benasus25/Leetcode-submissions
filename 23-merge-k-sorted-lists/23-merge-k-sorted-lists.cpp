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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        if(lists.size()==1)return lists[0];
        ListNode* head = lists[0];
        
        for(int i=1;i<lists.size();i++){
            head = merge(head,lists[i]);
        }
        return head;
    }
    
    ListNode* merge(ListNode* node1, ListNode* node2){
        if(!node1)return node2;
        if(!node2)return node1;
        
        if(node1->val<=node2->val){
            node1->next = merge(node1->next, node2);
            return node1;
        }
        else {
            node2->next = merge(node1, node2->next);
            return node2;
        }
    }
};