class Solution {
public:
    int longestMonotonicSubarray(vector<int>& v) {
       int count =1;
       int e=1;
       int s=1,d=1;
       for(int i=0;i<v.size()-1;i++){
          if(v[i]<v[i+1]){
             count++;
            s=max(s,count);
          }
          else count=1;
          if(v[i]>v[i+1]) {
            e++;
           d=max(d,e);
          }
          else e=1;
       }                     
       return max(s,d);                                                                                                                                                                                                                                                                                                                                                       
    }
};