class Solution {
public:
    int countOdds(int low, int high) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int cnt = 0;
        for(int i =low; i<=high; i++) {
            if(i%2 != 0) cnt++;
        }
        return cnt;
    }
};