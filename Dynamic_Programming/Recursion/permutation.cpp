class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(ans, nums, 0);
        return ans;
    }
private:
    void permute(vector<vector<int>>& ans, vector<int> nums, int i) {
        if (i == nums.size()) {
            ans.push_back(nums);
        } else {
            for (int j = i; j < nums.size(); j++) {
                swap(nums[i], nums[j]);
                permute(ans, nums, i + 1);
            }
        }
    }
};
