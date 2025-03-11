class Solution {
public:
    string removeKdigits(string num, int k) {
     stack<char>st;
     for(int i=0;i<num.size();i++){
        while(!st.empty()&&k>0 &&st.top()-'0' > num[i]-'0'){
           st.pop();
           k=k-1;
        }
        st.push(num[i]);
     }
        while(k--) st.pop();
        if(st.empty()) return "0";
        string s;
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        while(s.size()!=0 && s.back()=='0') s.pop_back();
        reverse(s.begin(),s.end());
        if(s.empty()) return "0";
        else 
        return s;
    }
};