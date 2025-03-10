class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        vector<int> pre(n);
        vector<int> suf(n);
        pre[0]=height[0];
        suf[n-1]=height[n-1];
        for(int i=1;i<n;i++){
           pre[i]=max(pre[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1],height[i]);
        }
        int leftmax ,rightmax;
        int total=0;
        for(int i=0;i<n;i++){
           leftmax=pre[i],rightmax=suf[i];
           if(height[i]<leftmax && height[i]<rightmax) total+= min(leftmax,rightmax) -height[i] ;
        }
       return total;
    }
};