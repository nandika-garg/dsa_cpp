class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;
        int n=height.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        int lmax=0, rmax=0;
        for (int i=0; i<n; i++){
         lmax=max(height[i], lmax);
         leftMax[i]=lmax;
        }
        for (int i=n-1; i>=0; i--){
            rmax=max(height[i], rmax);
            rightMax[i]=rmax;
        }
        for (int i=0; i<n; i++){
            water+=min(leftMax[i], rightMax[i])-height[i];
        }
        return water;

    }
};