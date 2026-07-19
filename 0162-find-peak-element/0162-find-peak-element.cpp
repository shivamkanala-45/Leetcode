class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int low = 0, high = v.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (v[mid] > v[mid + 1]) {
                
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};