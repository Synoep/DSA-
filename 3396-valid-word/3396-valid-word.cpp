class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        if (n<3) return false;

        int v=0; 
        int cons=0;
        string vo = "aeiouAEIOU";
        for (char ch : s) {
            if (!isalnum(ch)) return false; 
            if (isalpha(ch)) {
                if (vo.find(ch) != string::npos)
                    v++; 
                else cons++; 
            }
        }

        return v>=1&&cons>=1;
    }
};
