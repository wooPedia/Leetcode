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