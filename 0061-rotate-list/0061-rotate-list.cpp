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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head ||!head->next||k==0) return head;
        ListNode *temp=head;
        int length = 0;
        while (temp) {
            length++;
            temp = temp->next;
        }
        k = k%length;
        if (k == 0) return head;

        int count=0;
        while(k>count){
            ListNode* curr=head;
            ListNode* prev=NULL;
            while(curr->next){
                prev=curr;
                curr=curr->next;
            }
            curr->next=head;
            prev->next=NULL;
            head=curr;
            count++;           
        }
        return head;
    }
};