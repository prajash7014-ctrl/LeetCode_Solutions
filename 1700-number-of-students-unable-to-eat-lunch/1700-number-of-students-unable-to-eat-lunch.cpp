class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int size = students.size();
        int count=size;;
        int one = 0;
        int zero = 0;
        stack<int> st;
        for(int i=0;i<size;i++){
            if(students[i]==0) zero++;
            else one++;
            st.push(sandwiches[size-i-1]);
            q.push(students[i]);
        }
        while(!students.empty()){
            if(count==0) break;
            if(q.front()==st.top()){
                if(q.front()==0) zero--;
                else one--;
                q.pop();
                st.pop();
                count--;
                
            }
            else {
                if(zero==0 && st.top()==0) break;
                if(one==0 && st.top()==1) break;
                int a = q.front();
                q.pop();
                q.push(a);
            }
        }
        return count;
    }
};