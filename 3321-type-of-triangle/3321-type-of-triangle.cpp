class Solution {
public:
    string triangleType(vector<int>& nums) {
        int count=0,a=nums[0];
        int e=nums[1],d=nums[2];
        string s="";
        if(e==a && e==d) s+="equilateral";
        else if(e==a ||e==d||a==d){
           if(e+a>d && e+d>a && d+a>e) s+="isosceles";
           else s+="none";
        } 
        else {
            if(e+a>d && e+d>a && d+a>e) s+="scalene";
            else s+="none";
        }
        return s; 
    }
};