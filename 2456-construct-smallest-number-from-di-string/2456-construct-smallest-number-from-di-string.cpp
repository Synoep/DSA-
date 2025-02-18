class Solution {
public:
    string smallestNumber(string p) {
        string s;
        int n=p.size();
        stack<int>st;
        for(int i=0;i<n+1;i++){
            st.push(i+1);
             if(p[i]=='I'||i==n){
                while(!st.empty()){
                    s+=to_string(st.top());
                    st.pop();
                }
             }
        }
        return s;
    }
};