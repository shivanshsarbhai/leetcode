class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int elementsInFirstHalf = (n1+n2+1)/2;
        int beg = 0;
        int end = n1;
        while(beg<=end){
            int elementsFromN1 = (beg) + (end-beg)/2;                       //cut1
            int elementsFromN2 = elementsInFirstHalf - elementsFromN1;      //cut2

            int maxElementInLeftHalf1 = elementsFromN1 > 0 ? nums1[elementsFromN1-1] : INT_MIN;
            int maxElementInLeftHalf2 = elementsFromN2 > 0 ? nums2[elementsFromN2-1] : INT_MIN;
            int minElementInRightHalf1 = elementsFromN1 < n1 ? nums1[elementsFromN1] : INT_MAX;
            int minElementInRightHalf2 = elementsFromN2 <n2 ? nums2[elementsFromN2] : INT_MAX;

            if(maxElementInLeftHalf1 <= minElementInRightHalf2 
            && maxElementInLeftHalf2 <= minElementInRightHalf1){
                if((n1+n2)%2 == 0){
                    return (max(maxElementInLeftHalf1, maxElementInLeftHalf2) + min(minElementInRightHalf1,minElementInRightHalf2))/2.0;
                } else {
                    return max(maxElementInLeftHalf1, maxElementInLeftHalf2);
                }
            }

            else if(maxElementInLeftHalf1 > minElementInRightHalf2)
                end = elementsFromN1-1;
            
            else
                beg = elementsFromN1+1;
        }

        return 0.0;
    }
};