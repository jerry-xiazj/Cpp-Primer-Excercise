#include "Tree.h"
#include "Node.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <iostream>

using namespace std;

string Tree::getType()
{
	return type;
}

int Tree::current_date()
{
	tm local;
	time_t now = time(0);
	localtime_r(&now, &local);
	int date = local.tm_mday + 100 * local.tm_mon + 10000 * local.tm_year;
	return date;
}

void Tree::display_record()
{
	while(1)
	{
		string num;
		cout << "****************************************" << endl;
		cout << "| " << "记录： " << endl;
		for (auto & s : record)
		{
			cout << "|    " << s << endl;
		}
		cout << "****************************************" << endl;
		cout << "c. 返回上一层" << endl;
		cout << "****************************************" << endl;

		cin >> num;
		if (num == "c")
		{
			break;
		}
		else
		{
			cout << "输入错误，重新输入！" << endl;
			continue;
		}
	}
}

int Tree::get_date(int day) const
{
	time_t now = time(0);
	time_t want = now + day*24*3600;
	tm local;
	localtime_r(&want, &local);
	int date = local.tm_mday + 100 * (local.tm_mon + 1) + 10000 * (local.tm_year + 1900);
	return date;
}