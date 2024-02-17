class Solution {
public:
    bool isRobotBounded(string instructions) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int x = 0, y = 0, i = 0;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (char& it : instructions) {
            if (it == 'L')
                i = (i + 3) % 4;
            else if (it == 'R')
                i = (i + 1) % 4;
            else
                x += dir[i][0], y += dir[i][1];
        }
        return x == 0 && y == 0 || i > 0;
    }
};