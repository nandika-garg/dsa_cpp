class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack <int> st;
        unordered_map <int, int> mp; 
        for (int i=0; i<nums.size(); i++){
            while (!st.empty() && nums[st.top()]<nums[i]){
                mp[st.top()]=nums[i];
                st.pop();
            }
            st.push(i);
        }
        
        for (int i=0; i<nums.size(); i++){
            while (!st.empty() && nums[st.top()]<nums[i]){
                mp[st.top()]=nums[i];
                st.pop();
            }
        }
           
        while (!st.empty()){
        mp[st.top()]=-1;
        st.pop();
       }
       for (int i=0; i<nums.size(); i++){
        nums[i]=mp[i];
       }
       return nums;
        
        
    }
};