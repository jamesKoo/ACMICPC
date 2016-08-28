/*
4673 - 셀프 넘버(https://www.acmicpc.net/problem/4673)
*/

#include<cstdio>
#include<vector>

using namespace std;

int d(int n)
{
	int rst = n;
	while(n)
	{
		rst += n % 10;
		n /= 10;
	} 
	return rst;
}

int main()
{
	// Init
	int N = 10000;
	vector<bool> bSelfNums(N + 1, true);

	// Find self number
	for (int n = 1; n <= N; n++)
	{
		int dn = d(n);
		if (dn <= N)
			bSelfNums[dn] = false;
	}

	// Output
	for (int n = 1; n <= N; n++)
	{
		if (bSelfNums[n])
			printf("%d\n", n);
	}
	
	return 0;
}