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

    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp){
            ListNode* next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
            // temp=temp->next;
        }
        return prev;
    }

    ListNode* findk(ListNode* head,int k){
        ListNode* temp=head;
        while(temp && k>1){
            k--;
            temp=temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        
        while(temp){
            ListNode* kn=findk(temp,k);
            if(kn==NULL){
                prev->next=temp;
                break;
            }
            ListNode* nextnode=kn->next;
            kn->next=NULL;
            reverse(temp);
            if(temp==head){
                head=kn;
            }
            else{
                prev->next=kn;

            }
            prev=temp;
            temp=nextnode;
        }
        return head;
        
    }
};