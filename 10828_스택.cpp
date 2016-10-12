/*
10828 - 스택(https://www.acmicpc.net/problem/10828)

정의 : 스택 자료 구조 연습

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Stack
{
public:
	string command(string cmd)
	{
		string rst = "";
		if (cmd.find("push") != string::npos)
		{
			data.push_back(cmd.substr(5));
		}
		else if (cmd.find("pop") != string::npos)
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
		else if (cmd.find("top") != string::npos)
		{
			if (data.size())
				rst = data.back() + "\n";
			else
				rst = "-1\n";
		}

		return rst;
	}

private:
	vector<string> data;
};


int main()
{
	// Input
	int n;
	cin >> n;
	cin.ignore();

	// Operate
	Stack stack;
	string cmd;

	while (n--)
	{
		getline(cin, cmd);
		cout << stack.command(cmd);
	}

	return 0;
}