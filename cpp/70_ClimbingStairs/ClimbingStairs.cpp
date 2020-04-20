/*
    [Easy] 70.Climbing stairs
    ---------------------------------------------------------------------------------------------------------------------------------------------
    You are climbing a stair case. It takes n steps to reach to the top.
    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
    Note: Given n will be a positive integer.
    
    Example 1:

    Input: 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps
    
    Example 2:

    Input: 3
    Output: 3
    Explanation: There are three ways to climb to the top.
    1. 1 step + 1 step + 1 step
    2. 1 step + 2 steps
    3. 2 steps + 1 step
    ---------------------------------------------------------------------------------------------------------------------------------------------
  
    - Detail
    https://woo-dev.tistory.com/129
 */

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 3)
        {
            return n;
        }

        std::vector<int> v;
        int size = n - 1;
        v.reserve(size);

        v.push_back(1);
        v.push_back(2);
        v.push_back(3);

        // v[0]: 1
        // v[1]: 2 
        // v[2]: 3 
        // v[3]: v[2] + v[1]
        // ...
        // v[n]: v[n-1] + v[n-2]

        for (int i = 3; i != size; ++i)
        {
            v.push_back(v[i - 1] + v[i - 2]);
        }

        return v[n - 2] + v[n - 3];
    }
};
