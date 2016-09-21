/*
2750 - 수 정렬하기(https://www.acmicpc.net/problem/2750)

정의 : N <= 1,000으로 단순한 정렬 알고리즘 연습.
풀이 
  - 버블정렬 알고리즘 사용.

*/

#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	// Input
	int n;
	scanf("%d", &n);

	vector<int> arr(n);
	for (int idx = 0; idx < n; idx++)
		scanf("%d", &arr[idx]);

	// Bubble sort
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);

	// Output
	for (auto& num : arr)
		printf("%d\n", num);

	return 0;
}