class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.length()<=k){
            string temp="";
            for(auto c:s){
                if(c=='z') temp.push_back('a');
                temp.push_back(c+1);
            }
            s+=temp;
        }
        return s[k-1];
    }
};