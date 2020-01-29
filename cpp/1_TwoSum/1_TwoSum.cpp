/*
	----------------------------------------------------------------------------------------------------------------
	Given an array of integers, return indices of the two numbers such that they add up to a specific target.

	You may assume that each input would have exactly one solution, and you may not use the same element twice.

	Example:

	Given nums = [2, 7, 11, 15], target = 9,

	Because nums[0] + nums[1] = 2 + 7 = 9,
	return [0, 1].
	----------------------------------------------------------------------------------------------------------------

	- 해쉬 맵을 이용한 풀이
	- 시간 복잡도: O(n)
	- 공간 복잡도: O(1)

	1. 루프를 돌면서 맵에 (nums[i], i) 즉 (nums 요소, 인덱스)를 쌍으로 저장
	2. target-nums[i]이 map에 존재하는지 확인
	3. 존재한다면 그 값과 nums[i]와의 합이 target이므로 각 인덱스를 저장 후 반환

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