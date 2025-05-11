#include <vector>
#include <algorithm>

using namespace std;

struct Element {
    int value;
    int count;
};

bool compareElements(const Element& a, const Element& b) {
    return a.count > b.count; // Sort in descending order of count
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0) return {};
        
        // Step 1: Sort the array to group identical elements
        sort(nums.begin(), nums.end());
        
        // Step 2: Count frequencies manually
        vector<Element> elements;
        int current = nums[0];
        int count = 1;
        
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] == current) {
                count++;
            } else {
                elements.push_back({current, count});
                current = nums[i];
                count = 1;
            }
        }
        elements.push_back({current, count}); // Add the last element
        
        // Step 3: Sort elements by frequency
        sort(elements.begin(), elements.end(), compareElements);
        
        // Step 4: Extract top k elements
        vector<int> result;
        for (int i = 0; i < k && i < elements.size(); i++) {
            result.push_back(elements[i].value);
        }
        
        return result;
    }
};