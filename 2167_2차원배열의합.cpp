/*
2167 - 2차원 배열의 합(https://www.acmicpc.net/problem/2167)

정의
   - Integral Image 이용
   - S(x,y) = I(x,y) + I(x-1, y) + I(x,y-1) - I(x-1,y-1)
   - I'(x,y) = S(ex,ey) - S(ex, sy) - S(sx, ey) + S(sx, xy)          
   - Ref : https://computersciencesource.wordpress.com/2010/09/03/computer-vision-the-integral-image/
*/

#include <iostream>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	
	// Input the matrix.
	int n, m;
	cin >> n >> m;
	
	vector<vector<int> > mat(n + 1, vector<int>(m + 1, 0));
	for (int r = 1; r <= n; r++)
		for (int c = 1; c <= m; c++)
			cin >> mat[r][c];

	// Calculate a integral image
	vector<vector<int> > s(n, vector<int>(m));
	for (int c = 2; c <= m; c++)
		mat[1][c] += mat[1][c - 1];

	for (int r = 2; r <= n; r++)
		mat[r][1] += mat[r - 1][1];

	for (int r = 2; r <= n; r++)
		for (int c = 2; c <= m; c++)
			mat[r][c] = mat[r][c] + mat[r - 1][c] + mat[r][c - 1] - mat[r - 1][c - 1];
	
	// Sum elements of sub-matrix
	int k;
	cin >> k;
	while (k--)
	{
		int sy, sx, ey, ex;
		cin >> sy >> sx >> ey >> ex;
		
		cout << mat[ey][ex] + mat[sy - 1][sx - 1] - mat[sy - 1][ex] - mat[ey][sx - 1] << '\n';
	}

		
	return 0;
}