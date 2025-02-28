class Solution {
public:
    int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_water = 0;

    while (left < right) {
        int width = right - left;
        int minHeight = min(height[left], height[right]);
        max_water = max(max_water, width * minHeight);

        // Move the pointer pointing to the shorter height
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_water;
}
};