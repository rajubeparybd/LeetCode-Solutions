class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int m = matrix.size();
        int n = matrix[0].size();

        vector<pair<int, int>> mn;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0)
                    mn.push_back({i, j});
            }
        }
        for (auto i : mn) {
            int row = i.first;
            int col = i.second;

            for (int k = 0; k < n; k++)
                matrix[row][k] = 0;

            for (int k = 0; k < m; k++)
                matrix[k][col] = 0;
        }
    }
};