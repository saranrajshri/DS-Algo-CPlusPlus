class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if(m > n) {
            return findMedianSortedArrays(nums2, nums2);
        }
        
        int start = 0;
        int end = m - 1;
        
        while(start <= end) {
            int partitionX = (start + end) / 2;
            int partitionY = ((m + n + 1) / 2 ) - partitionX;
            
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int maxLeftY = (partitionX == m) ? INT_MAX : nums1[partitionX];
            int minRightX = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];
            
            if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if((m + n) % 2 == 0) {
                    return double(max(maxLeftX, maxLeftY) + min(minRightX, minRightY) / 2.0);   
                }else if(maxLeftX > minRightY) {
                    end = partitionX - 1;
                }else {
                    start = partitionX + 1;
                }
            } 
        }
        return -1.0;
    }
};