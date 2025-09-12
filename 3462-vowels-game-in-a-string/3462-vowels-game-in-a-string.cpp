class Solution {
public:
    bool doesAliceWin(string s) {
        for(char z:s){
            if(z=='a'||z=='e'||z=='i'||z=='o'||z=='u') return true;
        }
        return false;
    }
};