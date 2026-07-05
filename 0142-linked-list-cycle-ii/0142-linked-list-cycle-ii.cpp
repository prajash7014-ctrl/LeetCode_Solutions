class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        bool flag = false;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow= slow->next;
            if(fast==slow){
                flag = true;
                break;
            }
        }
        if(!flag) return NULL;
        else{
            while(temp!=slow){
                temp = temp->next;
                slow = slow->next;
            }
            return slow;
        }
    }
};