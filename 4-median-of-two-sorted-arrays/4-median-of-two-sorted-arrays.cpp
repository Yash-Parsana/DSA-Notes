class Solution {
public:
    
    
    double median(vector<int> v1,vector<int> v2)
    {
        if(v1.size()>v2.size())
            return median(v2, v1);

        int n = v1.size(), m = v2.size();
        int nm = (n + m + 1)/2;

        int i = 0, j = n;

        while(i<=j)
        {
            int mid1 = (i + j) / 2;
            int mid2 = nm - mid1;

            int left1 = mid1 == 0 ? INT_MIN : v1[mid1 - 1];
            int left2 = mid2 == 0 ? INT_MIN : v2[mid2 - 1];

            int right1 = mid1 == n ? INT_MAX : v1[mid1];
            int right2 = mid2 == m ? INT_MAX : v2[mid2];

            if(left1<=right2&&left2<=right1)
            {
                if((m+n)%2==0)
                {
                    return (max(left1,left2) + min(right1,right2)) / 2.0;
                }
                else
                    return max(left1, left2);
            }
            else if(left1>right2)
            {
                j = mid1 - 1;
            }
            else
                i = mid1 + 1;
        }
        return 0.0;
    }
    
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
     
        return median(nums1,nums2);
        
    }
};