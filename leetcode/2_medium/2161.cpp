class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans, temp;

        for(int x:nums){
            if(x==pivot)
                temp.push_back(x);
        }

        for(int x:nums){
            if(x<pivot)
                ans.push_back(x);
            else if(x>pivot)
                temp.push_back(x);
        }

        ans.insert(ans.end(), temp.begin(), temp.end());
        return ans;
    }
};