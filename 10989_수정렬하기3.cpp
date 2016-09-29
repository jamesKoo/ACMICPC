/*
10989 - 수 정렬하기3(https://www.acmicpc.net/problem/10989)

정의 : 최대 10,000,000개의 자연수를 정렬.
풀이 
  - Radix sort 이용, O(n).
  - 메모리 초과(8M 제한)로 기수 정렬대신 Count만 이용.

*/

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int BASE = 10;

void countSort(vector<int>& nums, int exp)
{

	vector<int> cnts(BASE + 1, 0);

	// Count.
	for (auto num : nums)
		cnts[(num / exp) % BASE]++;
	
	// Accumulate.
	for (int idx = 1; idx <= BASE; idx++)
		cnts[idx] += cnts[idx - 1];

	// Arrange.
	vector<int> sortNum(nums.size());
	for (int idx = nums.size() - 1; idx >= 0; idx--)
		sortNum[--cnts[(nums[idx] / exp) % BASE]] = nums[idx];

	nums = sortNum;
}

void radixSort(vector<int>& nums)
{
	int max = *max_element(nums.begin(), nums.end());
	for (int exp = 1; max / exp > 0; exp *= BASE)
		countSort(nums, exp);
}

int main()
{
	// Init
	const int MAX_VAL = 10001;
	vector<int> cnts(MAX_VAL, 0);

	// Input
	int n;
	scanf("%d", &n);
	
	// Count
	int num;
	while (n--)
	{
		scanf("%d", &num);
		cnts[num]++;
	}
	
	// Output
	for (int num = 1; num < MAX_VAL; num++)
	{
		if (cnts[num])
		{
			for (int idx = 0; idx < cnts[num]; idx++)
				printf("%d\n", num);
		}
	}
	
	
	return 0;
}