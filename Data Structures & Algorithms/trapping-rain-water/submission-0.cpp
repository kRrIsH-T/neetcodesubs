class Solution {
   public:
    int trap(vector<int>& height) {
       int lmax = 0; 
       int ans = 0;
       for(int i = 1; i<height.size()-1; i++)
       {
        if(height[i-1]>lmax) lmax = height[i-1];
        int r = *max_element(height.begin()+i+1, height.end());
        if(height[i]<min(lmax,r))ans += min(lmax,r) - height[i];
       }
       return ans;
    }
};
