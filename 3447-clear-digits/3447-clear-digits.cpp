class Solution {
public:
    string clearDigits(string s){
       stack<char> st;
       string a;
       for(int i=0;i<s.size();i++){
        if(!isdigit(s[i]))
          st.push(s[i]);
        else  st.pop();
       }
       while(!st.empty()){
        a+=st.top();
        st.pop();
       }
       reverse(a.begin(),a.end());
       return a;
    }
};