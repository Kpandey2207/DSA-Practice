class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            size++;
        }
        int pos=size-n;
        if(pos==0)
            return head->next;

        temp=head;
        while(pos-1){
            temp=temp->next;
            pos--;
        }
        temp->next=temp->next->next;
        return head;
    }
};