class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = min(1LL*nums1[0]*nums2.back() , 1LL*nums1.back()*nums2[0]);
        long long right = max({1LL*nums1[0]*nums2.back() , 1LL*nums1.back()*nums2[0] , 1LL*nums1[0]*nums2[0] , 1LL*nums1.back()*nums2.back()});
        function<bool(long long , long long)> check = [&](long long x , long long k)->bool{
            long long cnt = 0 , n = nums1.size() , m = nums2.size() , div , idx;
            for(int i=0;i<n && cnt<k;i++){
                long long val = nums1[i];
                if(val == 0){
                   if(x >= 0)cnt += m; 
                }else if(val < 0){
                    div = x / val;
                    if(x % val != 0)div += (x<0);
                    idx = lower_bound(nums2.begin() , nums2.end() , div) - nums2.begin();
                    cnt += (m-idx);
                }else{
                    div = x / val;
                    if(x % val != 0)div -= (x<0);
                    idx = upper_bound(nums2.begin() , nums2.end() , div) - nums2.begin();
                    cnt += idx;
                }
            }
            return cnt < k;
        };
        while(left <= right){
            long long mid = left + (right - left) / 2;
            if(check(mid , k)){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return left;
    }
};