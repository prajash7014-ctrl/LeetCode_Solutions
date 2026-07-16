class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        left--;
        right--;
        if(left==0 && right==0) return head;
        vector<int> res;
        ListNode* temp = head;
        while(temp!=NULL){
            res.push_back(temp->val);
            temp = temp->next;
        }
        reverse(res.begin()+left, res.begin()+right+1);
        temp=head;
        int i=0;
        while(temp!=NULL){
            temp->val=res[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};