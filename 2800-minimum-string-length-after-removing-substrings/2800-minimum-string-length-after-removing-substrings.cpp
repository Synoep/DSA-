class Solution {
public:
    int minLength(string s) {
        int pos1 = s.find("AB"), pos2 = s.find("CD");

        while ((pos1 != string::npos) || (pos2 != string::npos)) {
            if (pos1 != string::npos) {
                s.erase(pos1, 2);
            } else if (pos2 != string::npos) {
                s.erase(pos2, 2);
            }
            pos1 = s.find("AB");
            pos2 = s.find("CD");
        }

        return s.length();
    }
};