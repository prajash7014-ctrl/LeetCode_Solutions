class Solution {
public:
int r=0,u=0;
    void right(vector<vector<int>>& result, int m, int n, ListNode*& head){
       for(int i=u;i<n;i++){
         if(head!=NULL){
            result[r][i]=head->val;
                head = head->next;
            }
        else result[r][i] = -1;
       }
       r++;
    }
     void down(vector<vector<int>>& result, int m, int n, ListNode*& head){
        for(int i=r;i<m;i++){
            if(head!=NULL){
            result[i][n-1]=head->val;
                head = head->next;
            }
        else result[i][n-1] = -1;
        }
        r = m-1;
     }
     void left(vector<vector<int>>& result, int m, int n, ListNode*& head){
        for(int i=n-2; i>=u;i--){
            if(head!=NULL){
            result[r][i]=head->val;
                head = head->next;
            }
        else result[r][i] = -1;
        }
        r--;
     }
     void up(vector<vector<int>>& result, int m, int n, ListNode*& head){
        for(int i=r;i>u;i--){
            if(head!=NULL){
            result[i][u]=head->val;
                head = head->next;
            }
        else result[i][u] = -1;
        }
        u++;
        r = u;
     }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int>(n, -1));
        int row=m, col=n;
        while(head!=NULL && row>0 && col>0){
            right(result,row,col,head);
            if(head ==NULL) break;
            down(result,row,col,head);
             if(head==NULL) break;
            left(result,row,col,head);
             if(head==NULL) break;
            up(result,row,col,head);
             if(head==NULL) break;
             row--;
             col--;
        }
        return result;
    }
};