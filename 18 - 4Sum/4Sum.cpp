class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> temp;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[k] + nums[l];

                    if (sum == target) {
                        vector<int> ans = {nums[i], nums[j], nums[k], nums[l]};
                        temp.push_back(ans);

                        k++;
                        l--;

                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
                    else if (sum < target) k++;
                    else l--;
                }
            }
        }
        return temp;
    }


    /**
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     * Solution 2 for 4 sum
     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
     */

    vector <vector<int>> fourSum(vector<int> &nums, int targetSum) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map < int, vector < vector < int>>> ap;
        vector <vector<int>> qd;
        int n = nums.size();

        for (int i = 1; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = nums[i] + nums[j];
                int diff = targetSum - sum;
                if (ap.find(diff) != ap.end()) {
                    for (vector<int> it: ap[diff]) {
                        it.push_back(nums[i]);
                        it.push_back(nums[j]);
                        qd.push_back(it);
                    }
                }
            }

            for (int k = 0; k < i; ++k) {
                int sum = nums[i] + nums[k];
                if (ap.find(sum) == ap.end()) ap[sum] = vector < vector < int >> {{nums[k], nums[i]}};
                else ap[sum].push_back(vector < int > {nums[k], nums[i]});
            }
        }
        return qd;
    }
};