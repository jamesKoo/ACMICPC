/*
10845 - 큐(https://www.acmicpc.net/problem/10845)

정의 : 큐 자료구조 연습

*/

#include<iostream>
#include<queue>
#include<string>

using namespace std;

class Queue
{
public:
	string command(string cmd)
	{
		string rst = "";
		if (cmd.find("push") != string::npos)
		{
			data.push(cmd.substr(5));
		}
		else if (cmd.find("pop") != string::npos)
		{
			if (data.size())
			{
				rst = data.front() + "\n";
				data.pop();
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
	queue<string> data;
};


int main()
{
	// Input
	int n;
	cin >> n;
	cin.ignore();

	// Operate
	Queue queue;
	string cmd;

	while (n--)
	{
		getline(cin, cmd);
		cout << queue.command(cmd);
	}

	return 0;
}