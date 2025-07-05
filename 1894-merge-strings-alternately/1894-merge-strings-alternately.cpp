class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int l1=0,l2=0;
        int n=word1.size(),m=word2.size();
        for(int i=0;i<n+m;i++){
            if(i%2==0){
                 if(l1!=n) s+=word1[l1],l1++;
                 else s+=word2[l2],l2++;
            }
            else {
                 if(l2!=m)s+=word2[l2],l2++;
                 else s+=word1[l1],l1++;
            }
        }
        return s;
    }
};