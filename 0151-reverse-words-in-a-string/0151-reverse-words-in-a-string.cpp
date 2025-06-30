class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word,result;
        while(ss>>word){
            result=word+" "+result;
        }
        while(!result.empty()&& result.back()==' ') result.pop_back();
        return result;
    }
};