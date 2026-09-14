class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maximumArea = 0;
        int area = 0;
        while(l < r){
            area = (r - l) * min(heights[l], heights[r]);
            maximumArea = max(maximumArea, area);
            if(heights[l] < heights[r]){
                l++;
            }
            else if(heights[l] > heights[r])
            {
                r--;
            }
            else{
                r--;
            }
        }
        return maximumArea;
    }
};
