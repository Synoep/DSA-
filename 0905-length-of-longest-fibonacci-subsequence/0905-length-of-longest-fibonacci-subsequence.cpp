class Solution {
   void p(unordered_set<int>& st,int n) {
    int a = 0, b = 1, next;
    while (a <=n) {
            st.insert(a);
            next =a+b;
            a=b;
            b=next;
     }
}


public:
    int lenLongestFibSubseq(vector<int>& arr) {
         unordered_set<int> numSet(arr.begin(), arr.end());
        int n = arr.size();
        int maxi= 0;
        for (int i=0;i<n;i++) {
            for (int j =i+1;j<n;j++) {
                int a =arr[i],b=arr[j]; 
                int length=2;
                while (numSet.count(a + b)) {
                    int next =a+b;
                    a =b;
                    b =next;
                    length++;
                }
                maxi= max(maxi,length);
            }
        }
       if(maxi>=3) return maxi;
       else return 0;
    }
};