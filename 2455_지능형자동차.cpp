/*
2455 - 지능형 자동차(https://www.acmicpc.net/problem/2455)

정의 - 단순 계산 문제
   
*/

#include <iostream>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	
	
	const int STATION_NUM = 4;
	int in, out, max = 0, cur = 0;
	
	for (int s = 0; s < STATION_NUM; s++)
	{
		cin >> out >> in;
		cur = cur + in - out;
		if (max < cur)
			max = cur;
	}
	
	cout << max;
		
	return 0;
}