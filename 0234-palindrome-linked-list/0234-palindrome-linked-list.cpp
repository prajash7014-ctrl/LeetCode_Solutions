class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        reverse(arr.begin(), arr.end());
        temp =head;
        bool ans = true;
        for(int i=0;i<arr.size();i++){
            if(temp->val==arr[i]) {
                temp = temp->next;
            }
            else{
                ans = false;
                break;
            }
        }        
       return ans;
    }
};