class Solution {
public:
    int numberOfSubstrings(string s) {
        int left =0,right=0;
        unordered_map<char,int> m;
        int count=0;
        for(int i=0;i<s.size();i++) {
            m[s[i]]++;
          while(m['a']>0 && m['b']>0 && m['c'] >0){
            count+= s.size()-i;
            m[s[left]]--;
            left++;
         }
        }
    return count;
    }
};