class Solution {
    public static long minSum(int[] nums1, int[] nums2) {
        int zero1 = 0;
        int zero2 = 0;
        int sum1  = 0;
        int sum2  = 0;

        int i = 0;
        boolean ended1 = false;
        boolean ended2 = false;

        while (!ended1 && !ended2) {
            if (i < nums1.length) {
                sum1 += nums1[i];
                if (nums1[i] == 0)
                    zero1++;
            }
            else
                ended1 = true;

            if (i < nums2.length) {
                sum2 += nums2[i];
                if (nums2[i] == 0)
                    zero2++;
            }
            else
                ended2 = true;
            i++;
        }

        int total1 = sum1 + zero1;
        int total2 = sum2 + zero2;

        if (zero1 == 0 && total2 > sum1)
            return -1;
        else if (zero2 == 0 && total1 > sum2)
            return -1;
        else if (total2 > total1)
            return total2;
        else
            return total1;
    }
}
