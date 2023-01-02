/*

You are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
Return the maximum value of F(0), F(1), ..., F(n-1).

The test cases are generated so that the answer fits in a 32-bit integer.

*/


class Solution {
public:
    //next iteration has all element frequency increment by 1 but size times less frequency of last element as it comes to front
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        for(auto n : nums) sum += n;
        int currsum = 0;
        for(int i = 0; i < nums.size(); i++){
            currsum += i * nums[i];
        }
        int ans = currsum;
        for(int i = 1 ;i < nums.size(); i++){
            currsum = currsum + sum - nums.size()*nums[nums.size() - i];
            ans = max(ans, currsum);
        }     
        return ans;
    }
};
