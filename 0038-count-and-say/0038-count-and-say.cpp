class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1"; 
        string res = "1";
        for (int k =2;k<=n; k++) {
            string temp = "";
            int cnt =1;
            for (int i=0; i<res.size();i++) {
                if (i<res.size()-1&& res[i] == res[i+1]) cnt++;
                else {
                    temp +=to_string(cnt); 
                    temp +=res[i];         
                    cnt=1;               
                }
            }
            res=temp; 
        }
        return res;
    }
};