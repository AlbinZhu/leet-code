/*
 * @author:      Swing
 * @create:      2019-12-24 14:52
 * @description: 
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n) {
            vector<int> temp;
            temp = nums1;
            nums1 = nums2;
            nums2 = temp;

            int tmp = m;
            m = n;
            n = tmp;
        }

        if (m == 0) {
            int mid = n / 2;
            if (n % 2 == 0) {
                return (nums2[mid] + nums2[mid - 1]) / 2.0;
            } else {
                return nums2[mid];
            }
        }

        int iMin = 0, iMax = m;

        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = (m + n + 1) / 2 - i;

            if (i != 0 && j != n && nums1[i - 1] > nums2[j]) {
                iMax--;
            } else if (j != 0 && i != m && nums1[i] < nums2[j - 1] ) {
                iMin++;
            } else {
                int maxLeft = 0;
                if (i == 0) {maxLeft = nums2[j - 1];}
                else if (j == 0) {maxLeft = nums1[i - 1];}
                else {maxLeft = max(nums1[i - 1], nums2[j - 1]);}
                if ((m + n) % 2 == 1) { return maxLeft;}

                int minRight = 0;
                if (i == m) {minRight = nums2[j];}
                else if (j == n) {minRight = nums1[i];}
                else {minRight = min(nums1[i], nums2[j]);}

                return (maxLeft + minRight) / 2.0;
            }

        }

        return 0.0;
    }

    double medianTest() {

        vector<int> nums1;
        nums1.push_back(1);
//        nums1.push_back(3);

        vector<int> nums2;
        nums2.push_back(2);
        nums2.push_back(3);

        double result = findMedianSortedArrays(nums1, nums2);

        cout << result << endl;

        return result;
    }
};