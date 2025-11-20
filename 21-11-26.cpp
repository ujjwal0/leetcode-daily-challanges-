class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end(),
     [](const vector<int>& a, const vector<int>& b) {
         if (a[1] == b[1])
             return a[0] > b[0];   // start descending
         return a[1] < b[1];       // end ascending
});


int ans = 0;
int p1 = -1, p2 = -1;

for (int i = 0; i < intervals.size(); i++) {

    if (i == 0) {
        p1 = intervals[0][1] - 1;
        p2 = intervals[0][1];
        ans = 2;
    }
    else if (intervals[i][0] <= p1) {
        // intentionally do nothing
    }
    else if (intervals[i][0] <= p2) {
        ans++;
        p1 = p2;
        p2 = intervals[i][1];
    }
    else {
        ans += 2;
        p1 = intervals[i][1] - 1;
        p2 = intervals[i][1];
    }
}

return ans;

        
    }
};