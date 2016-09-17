/*
1002 - 터렛(https://www.acmicpc.net/problem/1002)

정의 : 두 원의 교차 점의 개수(두원의 관계 참고 : http://mathbang.net/101)
방법 : 두 원의 중심과 반지름을 이용하여 각각의 Case별로 구별
       Case 1 :  0, 두 원이 접하지 않는 경우
	   Case 2 :  1, 두 원이 한 점에서 접하는 경우
	   Case 3 :  2, 두 원이 두 점에서 접하는 경우(일 부분 원이 겹침)
	   Case 4 : -1, 두 원의 중심이 같고 반지름도 같은 경우.
  
*/

#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		int r1_m_r2 = (r1 - r2) * (r1 - r2);
		int r1_p_r2 = (r1 + r2) * (r1 + r2);
		int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

		if (r1_m_r2 < dist && dist < r1_p_r2)		 // Case 3
			printf("2\n");
		else if (dist == 0 && r1_m_r2 == 0)			 // Case 4
			printf("-1\n");							 
		else if (r1_m_r2 == dist || r1_p_r2 == dist) // Case 2
			printf("1\n");
		else										 // Case 1
			printf("0\n");

	}

	return 0;
}