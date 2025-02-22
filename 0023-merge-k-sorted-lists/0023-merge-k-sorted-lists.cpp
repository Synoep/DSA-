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
        int n=lists.size();
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<n;i++){
            ListNode* temp=lists[i];
            while(temp!=NULL){
                q.push(temp->val);
                temp=temp->next;
            }
        }
        if(!q.empty()){
        ListNode* ans=new ListNode(q.top());
        q.pop();
        ListNode* tempp=ans;
        while(!q.empty()){
            int temp=q.top();
            q.pop();
            tempp->next=new ListNode(temp);
           if(tempp->next!=NULL) tempp=tempp->next;
            
        }
        return ans;
        }
        else return NULL;
        
    }
};