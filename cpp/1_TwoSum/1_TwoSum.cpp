/*
	----------------------------------------------------------------------------------------------------------------
	Given an array of integers, return indices of the two numbers such that they add up to a specific target.

	You may assume that each input would have exactly one solution, and you may not use the same element twice.

	Example:

	Given nums = [2, 7, 11, 15], target = 9,

	Because nums[0] + nums[1] = 2 + 7 = 9,
	return [0, 1].
	----------------------------------------------------------------------------------------------------------------

	- �ؽ� ���� �̿��� Ǯ��
	- �ð� ���⵵: O(n)
	- ���� ���⵵: O(1)

	1. ������ ���鼭 �ʿ� (nums[i], i) �� (nums ���, �ε���)�� ������ ����
	2. target-nums[i]�� map�� �����ϴ��� Ȯ��
	3. �����Ѵٸ� �� ���� nums[i]���� ���� target�̹Ƿ� �� �ε����� ���� �� ��ȯ

*/

#include <unordered_map>

using namespace std;

class Solution 
{
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		unordered_map<int, int> myMap;
		vector<int> ret;
		ret.reserve(2);

		int i = 0;
		for (;; ++i)
		{
			int val = target - nums[i];
			if (myMap.find(val) != myMap.end())
			{
				ret.push_back(i);
				ret.push_back(myMap[val]);
				return ret;
			}

			myMap[nums[i]] = i;
		}

		return {};
	}
};