class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        priority_queue<int> p;
        int diff = 0, i = 0;
        for(; i < h.size() - 1; i++){
            diff  = h[i+1] - h[i];

            if(diff <= 0 ) continue;

            b -= diff;
            p.push(diff);

            if(b < 0) {
                b += p.top();
                p.pop();
                l--;
            }
            if(l < 0) break;
        }
        return i;
    }
};