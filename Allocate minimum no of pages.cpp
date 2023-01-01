class Solution 
{
    private:
    int helper(int nums[] , int n , int givenSum) {
        int reqStudent = 1;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(sum > givenSum ) {
                reqStudent++;
                sum = nums[i];
            }
        }
        return reqStudent;
    }
    public:
    int findPages(int nums[], int n, int m) {
        
        if(m > n) return -1;
        
        int upperBound = accumulate(nums , nums + n , 0);
        int lowerBound = *max_element(nums, nums + n);
        
        int low = lowerBound;
        int high = upperBound;
        int ans = 1e9;
        while(low <= high) {
            int currSum = (low + high) >> 1;
            int reqStudent = helper(nums ,  n , currSum);
            
            if(reqStudent <= m) {
                ans = min(ans , currSum);
                high = currSum - 1;
            }
            else 
                low = currSum + 1;
            
        }
        return ans;
    }
};





// Findig peak element in a array
// can be used in a biotonic array

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return 0;
        }
        int low = 0 , high = n - 1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(mid == 0 or mid == n - 1) {
                if(mid == 0 and nums[mid] > nums[mid + 1]) {
                    return mid;
                }
                if(mid == n - 1 and nums[mid] > nums[mid - 1]) {
                    return mid;
                }
            }
            if(nums[mid] > nums[mid + 1] and nums[mid] > nums[mid - 1]) {
                return mid;
            }
            else {
               if(mid == 0 or mid == n - 1) {
                    if(mid == 0)
                     low = mid + 1;
                    else
                    high = mid - 1;
               }
               else {
                   if(nums[mid + 1] > nums[mid])
                   low = mid + 1;
                   else
                   high = mid - 1;
               }
            }
        }
        return -1;
    }
};


/*Search in a row and column wise sorted matrix*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0 , high = m - 1;
        int col = 0;
        int row = -1;
        while(low <= high) {
            int mid = (low + high) >> 1;

            if(matrix[mid][col] == target) {
                return true;
            }
            else if(matrix[mid][col] > target) {
                high = mid - 1;
            }
            else {
                row = mid;
                low = mid + 1;
            }
     
        }
        if(row == -1) return false;

        low = 0 , high = n - 1;
        
        while(low <= high) {
            int mid = (low + high) >> 1;

            if(matrix[row][mid] == target) return true;

            else if(matrix[row][mid] > target) {
                high = mid - 1;
            }
            else
            low = mid + 1;
        }
        return false;
    }
};
