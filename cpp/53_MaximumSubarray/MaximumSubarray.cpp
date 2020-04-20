/*
    [Easy] 53.Maximum subarray
    ---------------------------------------------------------------------------------------------------------------------------------------------
    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

    Example:

    Input: [-2,1,-3,4,-1,2,1,-5,4],
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.
    ---------------------------------------------------------------------------------------------------------------------------------------------
  
    - Detail
    https://woo-dev.tistory.com/128
 */

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {

        size_t size = nums.size();

        // 각 요소는 i번째 요소를 마지막으로 하는 부분합 중 가장 큰 합
        // each element is a max of sum in subarrays which have a nums[i] as last element.
        // ex) subArrayMaxSum[2]: maximum in nums {[2], [1]+[2], [0]+[1]+[2]}
        std::vector<int> subArrayMaxSum;
        subArrayMaxSum.reserve(size);

        // subArrayMaxSum[0]: [0]
        subArrayMaxSum.push_back(nums[0]);

        // subArrayMaxSum[1]: max([1], [0]+[1])
        // subArrayMaxSum[2]: max([2], [1]+[2], [0]+[1]+[2])
        // ...
        // subArrayMaxSum[i]: max([i], [i-1]+[i], ... , [0]+..+[i])

        for (size_t i = 1; i != size; ++i)
        {
            subArrayMaxSum.push_back(std::max(nums[i], subArrayMaxSum[i - 1] + nums[i]));
        }

        // maximum in subArrayMaxSum
        return *std::max_element(subArrayMaxSum.begin(), subArrayMaxSum.end());
    }
};
