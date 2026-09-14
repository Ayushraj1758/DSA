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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)return head;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp){
            ListNode* x=temp->next;
            temp->next=prev;
            prev=temp;
            temp=x;

        }
        temp=prev;
        if(n==1)prev=prev->next;
        int cnt=0;
        while(temp){
            cnt++;
            if(cnt==n-1){
                temp->next=temp->next->next;
            }
            temp=temp->next;
        }
        temp=prev;
        ListNode* prev2=NULL;
        while(temp){
            ListNode* x=temp->next;
            temp->next=prev2;
            prev2=temp;
            temp=x;

        }
        return prev2;
        
    }
};