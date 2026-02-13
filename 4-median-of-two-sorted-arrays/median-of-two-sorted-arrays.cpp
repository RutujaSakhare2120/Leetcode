class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int l=m+n;
        vector<int>v(l);
        for(int i=0;i<n;i++){
            v[i]=nums1[i];
        }
        for(int i=0;i<m;i++){
            v[i+n]=nums2[i];
        }

        sort(v.begin() , v.end());

        if(l%2!=0) return v[l/2]/1.00;

        return (v[l/2]+v[(l/2)-1])/2.00;

        
        
    }
};