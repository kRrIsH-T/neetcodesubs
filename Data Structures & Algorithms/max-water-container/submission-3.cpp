class Solution {
public:
    int maxArea(vector<int>& heights) {
        if(heights.size() <= 1)return 0;
        int left = 0;
        int right = heights.size() -1;
        int ans = 0;
        int lmax = left;
        int rmax = right;
        while(left<=right)
        {
            if(heights[left]>heights[lmax])lmax = left;
            if(heights[right]>heights[rmax])rmax = right;
            int area = (rmax-lmax)*min(heights[lmax], heights[rmax]);
            if(area > ans) ans = area; 
            // cout << lmax << rmax << '\n';
            if(heights[right] > heights[left])left++;
            else right--;
        } 
        return ans;
    }
};
