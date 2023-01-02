/*

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

*/


class Solution {
public:
    void possibleCombos(vector<vector<int>> &ans, vector<int> &current, int k, int start, int number){
        if(current.size() == k && number == 0){
            ans.push_back(current);
            return;
        }
        for(int i = start; i <= 9; i++){
            current.push_back(i);
            possibleCombos(ans, current, k, i + 1, number - i);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans ;
        vector<int> temp;
        possibleCombos(ans, temp, k, 1, n);
        return ans;
    }
};
