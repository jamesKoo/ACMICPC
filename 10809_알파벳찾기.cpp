/*
10809 - 알파벳 찾기(https://www.acmicpc.net/problem/10809)

정의 : 첫 시작하는 알파벳 위치 찾기
  
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<int> cnts(26, -1);

	// Input
	string str;
	cin >> str;
	
	// Count
	int len = str.length();
	for(int idx = 0; idx < str.length(); idx++)
	{
		int pos = str[idx] - 'a';
		if (cnts[pos] == -1)
			cnts[pos] = idx;
	}

	// Print
	for (auto cnt : cnts)
		cout << cnt << " ";

	return 0;
}