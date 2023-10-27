#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numIndices; // Map to store (number, index) pairs

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        
        // Check if the complement is in our map
        if (numIndices.find(complement) != numIndices.end()) {
            // Found the complement, return the indices
            return {numIndices[complement], i};
        }

        // Store the current number and its index in the map
        numIndices[nums[i]] = i;
    }

    // If no solution is found, return an empty vector
    return {};
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
        std::cout << "Indices of the two numbers that add up to the target: " << result[0] << " and " << result[1] << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}
