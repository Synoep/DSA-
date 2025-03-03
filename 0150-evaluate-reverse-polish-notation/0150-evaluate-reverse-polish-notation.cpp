class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        string operators = "+-*/";
        for (auto ch : tokens) {

            if (ch == "+") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a + b);
            } else if (ch == "-") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a - b);
            } else if (ch == "*") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a * b);
            } else if (ch == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(a / b);
            } else {
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};