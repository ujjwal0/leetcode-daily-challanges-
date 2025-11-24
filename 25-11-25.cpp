class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
       long long val=0;
       vector<bool>ans;
       for(int i=0;i<nums.size();i++){
        val = (val * 2 + nums[i]) % 5;
        ans.push_back(val == 0);
       }
       
       return ans;
    }
};