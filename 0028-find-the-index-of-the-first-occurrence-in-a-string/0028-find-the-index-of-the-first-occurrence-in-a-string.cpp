class Solution {
public:
    int strStr(string haystack, string needle) {
        int a=needle.size();
        int b=haystack.size();
        for(int i=0;i<b;i++){
            if(needle==haystack.substr(i,a)){
                return i;
            }
        }
        return -1;
    }

    
};