// Given an array of strings strs, group the words that are anagrams of each other.

// Input: strs = ["race", "care", "acre", "bake", "beak", "keep"]
//Output: [["race", "care", "acre"], ["bake", "beak"], ["keep"]]

// T.C :- O(NlogN) +  O(N + N)   dor sorting +  where N is the size of the array. 
// S.C :- O(N)                 O(N)   used unordered map data structure

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& nums) {
             
              unordered_map<string, vector<string>> mp;

        for (string& word : nums) {
            string key = word;
            sort(key.begin(), key.end());  
            mp[key].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& pair : mp) {
            result.push_back(pair.second);
        }

        return result;

    }
};
