class Solution {
public:
    int maxDiff(int num) {
        string s =to_string(num);
        string s1=s;
        for (char c:s) {
            if (c!='9') {
                for (char &ch:s1) if(ch==c) ch='9';
                break;
            }
        }
        string s2 = s;
        if (s[0]!='1') {
            char target =s[0];
            for (char &ch:s2) if (ch==target) ch = '1';
        } else {
            for (int i=1;i<s.size();i++) {
                if (s[i]!= '0'&&s[i] != '1') {
                    char target=s[i];
                    for (char &ch:s2) if (ch==target) ch = '0';
                    break;
                }
            }
        }

        return stoi(s1)-stoi(s2);
    }
};