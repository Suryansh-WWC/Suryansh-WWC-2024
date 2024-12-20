#include <iostream>
#include <vector>
using namespace std;

// Function to remove duplicates in-place and return the count of unique elements
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0; // Handle empty array case

    int uniqueCount = 1; // Start with the first element being unique

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[uniqueCount - 1]) {
            nums[uniqueCount] = nums[i]; // Place the next unique element
            uniqueCount++;              // Increment the count of unique elements
        }
    }

    return uniqueCount;
}

int main() {
    // Input: Sorted integer array
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};

    // Remove duplicates and get the count of unique elements
    int uniqueCount = removeDuplicates(nums);

    // Output the result
    cout << "Number of unique elements: " << uniqueCount << endl;
    cout << "Modified array with unique elements: ";
    for (int i = 0; i < uniqueCount; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

