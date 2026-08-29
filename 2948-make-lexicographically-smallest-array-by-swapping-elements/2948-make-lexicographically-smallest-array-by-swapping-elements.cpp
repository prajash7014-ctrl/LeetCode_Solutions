#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Step 1: Store elements as pairs of {value, original_index}
        vector<pair<int, int>> sorted_pairs;
        for (int i = 0; i < n; i++) {
            sorted_pairs.push_back({nums[i], i});
        }
        
        // Step 2: Sort the pairs primarily by their value
        sort(sorted_pairs.begin(), sorted_pairs.end());
        
        vector<int> result(n);
        int i = 0;
        
        // Step 3 & 4: Find connected components (groups) using a loop
        while (i < n) {
            int j = i + 1;
            // Expand the group as long as the adjacent elements are within the limit
            while (j < n && sorted_pairs[j].first - sorted_pairs[j - 1].first <= limit) {
                j++;
            }
            
            // Collect original indices for this current group
            vector<int> indices;
            for (int k = i; k < j; k++) {
                indices.push_back(sorted_pairs[k].second);
            }
            
            // Sort the indices so we can place values from left to right
            sort(indices.begin(), indices.end());
            
            // Step 5: Place the sorted values into the sorted positions
            for (int k = i; k < j; k++) {
                result[indices[k - i]] = sorted_pairs[k].first;
            }
            
            // Move to the start of the next group
            i = j;
        }
        
        return result;
    }
};
