/*
5430 - AC(https://www.acmicpc.net/problem/5430)
정의
- 덱 자료 구조를 이용하여 R(reverse), D(delete) 기능을 구현.
풀이
- Reverse : 덱의 Top위치를 front->back 또는 back->front로 변경
- Delete : Top위치에서 back을 수행.
*/

#include<iostream>
#include<deque>
#include<string>
#include<sstream>
#include<regex>

using namespace std;

class AC
{
public:
	void R()
	{
		top = !top;
	}

	void D()
	{
		if (deq.empty())
		{
			err = true;
			return;
		}
		if (top == FRONT)
			deq.pop_front();
		else
			deq.pop_back();
	}

	void input(string str, int num)
	{
		int len = str.length();
		for (int idx = 0; idx < len; ++idx)
			if (str[idx] == ',' || str[idx] == '[' || str[idx] == ']')
				str[idx] = ' ';

		stringstream ss(str);

		for (int idx = 0; idx < num; ++idx)
		{
			int num;
			ss >> num;
			deq.push_back(num);
		}

		/* 시관 초과로 주석 처리
		regex rex("\\d+");
		smatch m;

		while (regex_search(str, m, rex))
		{
			int num = stoi(m[0]);
			deq.push_back(num);
			str = m.suffix();
		}
		*/
	}

	void print()
	{
		if (err)
		{
			printf("error\n");
			return;
		}
		
		printf("[");
				
		if (top == FRONT)
		{
			for (auto it = deq.begin(); it != deq.end(); it++)
			{
				if (it != deq.begin())
					printf(",");

				printf("%d", *it);
			}
		}
		else
		{
			for (auto it = deq.rbegin(); it != deq.rend(); it++)
			{
				if (it != deq.rbegin())
					printf(",");

				printf("%d", *it);
			}
		}
		
		printf("]\n");
	}

private:
	enum { FRONT, BACK };
	int top = FRONT;
	bool err = false;
	deque<int> deq;
};

int main()
{
	ios::sync_with_stdio(false);

	int tc = 0;
	cin >> tc;
	while (tc--)
	{
		string opStr;
		cin >> opStr;

		int dataNum;
		string dataStr;
		cin >> dataNum >> dataStr;

		AC ac;
		ac.input(dataStr, dataNum);

		for (int idx = 0; idx < opStr.length(); idx++)
		{
			if (opStr[idx] == 'R')
				ac.R();
			else if (opStr[idx] == 'D')
				ac.D();
		}

		ac.print();

	}

	return 0;
}
