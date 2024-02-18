class Solution {
public:
    int countOdds(int low, int high) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        return((high+1)/2 - low/2);
    }
};