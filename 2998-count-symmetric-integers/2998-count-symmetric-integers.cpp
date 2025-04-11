class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i=low;i<=high;i++) {
            string s = to_string(i);
            int n = s.size();
            if (n %2!=0) continue; 
            int x =0,y =0;
            for (int j=0;j<n/2; j++) {
                x +=(s[j] -'0');
            }
            for (int j =n/2;j<n;j++) {
                y +=(s[j]-'0');
            }
            if (x==y) count++;
        }
        return count;
    }
};
