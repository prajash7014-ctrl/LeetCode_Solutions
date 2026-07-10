class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        reverse(arr.begin(), arr.end());
        temp = head;
        for(int i=0;i<arr.size();i++){
            temp->val = arr[i];
            temp = temp->next;
        }        
        return head;
    }
};