class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>result(n);
        stack<int>mono;
        for(int i=0;i<n;i++){
            while(!mono.empty() && temperatures[mono.top()]<temperatures[i]){
                result[mono.top()]=i-mono.top();
                mono.pop();
            }
            mono.push(i);
        }
        return result;
    }
};