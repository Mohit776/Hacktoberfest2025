class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
   int ans = 0;
    stack<int> s;
    int n = heights.size();
    vector<int> r(n, 0);
    vector<int> l(n, 0);

    // Next Smaller to Right
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        r[i] = s.empty() ? n : s.top();  // ✅ correct placement
        s.push(i);
    }

    // Clear the stack
    while (!s.empty()) s.pop();

    // Next Smaller to Left
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        l[i] = s.empty() ? -1 : s.top();  // ✅ correct placement
        s.push(i);
    }

    // Calculate max area
    for (int i = 0; i < n; i++) {
        int width = r[i] - l[i] - 1;
        int currArea = heights[i] * width;
        ans = max(ans, currArea);
    }

    return ans;
    }
};
