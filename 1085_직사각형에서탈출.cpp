/*
1085 - 직사각형에서 탈출(https://www.acmicpc.net/problem/1085)

정의
   - 단순 계산 문제

*/

#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	cout << min( min(x, y), min(w - x, h - y) );
	
	return 0;
}