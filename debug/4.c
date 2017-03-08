double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m, n = 0;
    int* A, B = NULL;
    //A <- m, B <- n
    if(nums1Size <= nums2Size){
        m = nums1Size;
        A = nums1;
        n = nums2Size;
        B = nums2;
    }else{
        m = nums2Size;
        A = nums2;
        n = nums1Size;
        B = nums1;
    }
    int imax = m;
    int imin = 0;
    int min_right, max_left = 0;
    
    while (imax >= imin){
        int i = (imax + imin) / 2;
        int j = (m + n + 1) / 2 - i;
        if(B[j-1] > A[i] && i < m){
            imin = i + 1;
        }else if (A[i-1] > B[j] && i > 0){
            imax = i - 1;
        }else {
            if(i == m) min_right = B[j];
            else if(j == n) min_right = A[i];
            else min_right = min(A[i], B[j]);
            
            if(i == 0) max_left = B[j-1];
            else if(j == 0) max_left = A[i-1];
            else max_left = max(B[j-1], A[i-1]);
            
            if((m + n) % 2 == 1) return double(max_left);
            return (max_left + min_right) / 2.0;
        }
    }
}
