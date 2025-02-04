#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    vector<int> ans(2);
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (map.find(complement) != map.end()) {
            ans[0] = map[complement];
            ans[1] = i;
            return ans;
        }
        map[nums[i]] = i;
    }
    
    return {};
}

int main() {
    vector<vector<int>> testCases = {
        {2, 7, 11, 15}, 
        {3, 2, 4},      
        {3, 3},         
        {1, 5, 7, 3, 9},
    };
    
    vector<int> targets = {9, 6, 6, 10};
    
    for (int i = 0; i < testCases.size(); i++) {
        vector<int> nums = testCases[i];
        int target = targets[i];
        
        vector<int> result = twoSum(nums, target);
        
        cout << "Test Case " << i + 1 << ": ";
        if (!result.empty()) {
            cout << "Indices: [" << result[0] << ", " << result[1] << "]";
        } else {
            cout << "No solution found!";
        }
        cout << endl;
    }
    
    return 0;
}
