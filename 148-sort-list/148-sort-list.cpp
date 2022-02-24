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
    ListNode* sortList(ListNode* head) {
    map<int,int>mp;
    while(head){
        mp[head->val]++;
        head= head->next;
    }
    ListNode* temp = new ListNode();
    ListNode* ans = temp;
    for(auto u:mp){
        while(u.second--){
            ListNode* temp1 = new ListNode(u.first);
            temp->next = temp1;
            temp= temp->next;
        }
    }
    return ans->next;
    }
};