/*
Solved Using hashmap and sorting the vector of pairs based on 
the hash values.
NOTE: Other approach includes:-
i) Using Bucket Sort
ii) Using Priority Queue (Heap)
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;

        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        vector<pair<char, int>> vec(map.begin(),map.end());
        sort(vec.begin(),vec.end(), [](const auto&a, const auto&b){
            return a.second>b.second; 
        });
        
        string str="";

        for(auto &p:vec){
            str.append(p.second,p.first);
        }
        return str;
    }
};