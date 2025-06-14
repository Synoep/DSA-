class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int total=0;
        int m=nums1.size(),n=nums2.size();
        for (int i=0;i<m;i++){
            if (n%2==0) total^=0;
            else total^=nums1[i];
        }
        for (int j=0;j<n;j++){
            if (m%2==0) total^=0;
            else total^=nums2[j];
        }
        return total;
    }
};