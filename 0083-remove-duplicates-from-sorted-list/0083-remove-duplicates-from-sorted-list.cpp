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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *curr = head, *forw = curr->next;
        while(forw){
            if(curr->val == forw->val){
                forw = forw->next;
                curr->next = forw;
            }else{
                curr = forw;
                forw = forw->next;
            }
        }
        return head;
    }
};