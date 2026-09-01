class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if (n==1) return 1;
        int maxlen=INT_MIN;
        int prev=0;
        int curr=1;

        for (int i=1; i<n; i++){
            int cmp=0;
            if (arr[i]>arr[i-1]) cmp=1;
            else if (arr[i]<arr[i-1]) cmp=-1;
            if (cmp==0) curr=1;
            else if (cmp==-prev) curr++;
            else curr=2;
            maxlen=max(maxlen, curr);
            prev=cmp;
        }
        return maxlen;
    }
};