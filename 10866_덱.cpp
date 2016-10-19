/*
10866 - 덱(https://www.acmicpc.net/problem/10866)

정의 : 덱 자료구조 연습

*/

#include<iostream>
#include<deque>
#include<string>

using namespace std;

class Deque
{
public:
	string command(string cmd)
	{
		string rst = "";
		if (cmd.find("push_front") != string::npos)
		{
			data.push_front(cmd.substr(11));
		}
		else if (cmd.find("push_back") != string::npos)
		{
			data.push_back(cmd.substr(10));
		}
		else if (cmd.find("pop_front") != string::npos)
		{
			if (data.size())
			{
				rst = data.front() + "\n";
				data.pop_front();
			}
			else
			{
				rst = "-1\n";
			}
		}
		else if (cmd.find("pop_back") != string::npos)
		{
			if (data.size())
			{
				rst = data.back() + "\n";
				data.pop_back();
			}
			else
			{
				rst = "-1\n";
			}
		}
		else if (cmd.find("size") != string::npos)
		{
			rst = to_string(data.size()) + "\n";
		}
		else if (cmd.find("empty") != string::npos)
		{
			rst = data.size() ? "0\n" : "1\n";
		}
		else if (cmd.find("front") != string::npos)
		{
			if (data.size())
				rst = data.front() + "\n";
			else
				rst = "-1\n";
		}
		else if (cmd.find("back") != string::npos)
		{
			if (data.size())
				rst = data.back() + "\n";
			else
				rst = "-1\n";
		}

		return rst;
	}

private:
	deque<string> data;
};


int main()
{
	// Input
	int n;
	cin >> n;
	cin.ignore();

	// Operate
	Deque deq;
	string cmd;

	while (n--)
	{
		getline(cin, cmd);
		cout << deq.command(cmd);
	}

	return 0;
}