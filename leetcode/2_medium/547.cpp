class Solution {
public:

    void dfsOnGraph(vector<int>& visited, vector<vector<int>>& isConnected, int node){
        visited[node]=1;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i]==1 && !visited[i])
            dfsOnGraph(visited, isConnected, i);
        }

        /*
        Logic for Adj List
        for(auto& it: isConnected[node]){
            if(!visited[it]){
                dfsOnGraph(visited, isConnected, it);
            }
        }
        */
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                count++;
                dfsOnGraph(visited, isConnected,i);
            }
        }
        return count;
    }
};