#include "TreeTemp.h"
#include "Node.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <limits>
#include <ctime>
#include <cmath>

using namespace std;

TreeTemp::TreeTemp(vector<string> text)
{
	string name;
	int level;
	string yORn;
	bool finish;
	auto begin = text.begin();

	istringstream is(*begin++);
	is >> type;

	is.clear();
	is.str(*begin++);
	is >> donePart >> entirePart;

	is.clear();
	is.str(*begin++);
	is >> adate;

	is.clear();
	is.str(*begin++);
	is >> level >> name >> yORn;
	if (yORn == "y") finish = true;
	else if (yORn == "n") finish = false;
	//根据读取的level、name和finish创建动态Node对象，并将指针存入当前tempTree中
	task = new Node(level, name, finish);

	while (begin != text.end())
	{
		record.push_back(*begin++);
	}

	daily_task();
}

void TreeTemp::print() const
{
	cout << "| --------------------------------------" << endl;
	if (donePart == entirePart)
	{
		cout << "|" << "▲ " << task->name << endl;
	}
	else
	{
		cout << "|" << "△ " << task->name << endl;
	}
	cout << "|  " << donePart << "/" << entirePart << endl;
	int nStar = 20;
	int ratio = nStar * donePart / entirePart;
	cout << "|  [";
	for (int i = 0; i != ratio; ++i)
	{
		cout << "*";
	}
	for (int j = 0; j != nStar - ratio; ++j)
	{
		cout << "-";
	}
	cout << "]" << endl;
	cout << "|  预计完成日期：" << adate << endl;
	cout << "|  剩余天数：" << day_left() << endl;
	cout << "|  每日所需完成量：" << dtask << endl;
	cout << "| --------------------------------------" << endl;
}

void TreeTemp::print_ini(ofstream & outf) const
{
	//顺序式输出
	outf << type << endl;
	outf << donePart << " " << entirePart << endl;
	outf << adate << endl;
	task->print_ini(outf);
	for (auto &s : record)
	{
		outf << s << endl;
	}
	outf << endl;
}

bool TreeTemp::check_finish()
{
	finishTree = false;
	if (donePart == entirePart)
	{
		finishTree = true;
		task->set_state(true);
	}
	return finishTree;
}

TreeTemp::~TreeTemp()
{
	delete task;
}

bool TreeTemp::check_date(int date) const
{
	if (date > 99999999)
	{
		return false;
	}
	else
	{
		int year = date/10000;
		int mon = (date-10000*year)/100;
		int day = date-10000*year-100*mon;

		vector<int> dayRange{ 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (year % 4 == 0) dayRange[1] = 29;

		if ((mon < 1) || (mon > 12) || (day < 1) || (day > dayRange[mon - 1]))
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

void TreeTemp::daily_task()
{
	dtask = ceil((entirePart - donePart) / double(day_left()));
}

int TreeTemp::day_left() const
{
	time_t t = time(0);
	tm atime;
	localtime_r(&t, &atime);
	int ayear = adate/10000;
	int amonth = (adate-ayear*10000)/100;
	int aday = adate-ayear*10000-amonth*100;
	atime.tm_year = ayear-1900;
	atime.tm_mon = amonth-1;
	atime.tm_mday = aday;
	time_t atime_t = mktime(&atime);
	int dayDiff = round(difftime(atime_t, t) / 24 / 3600 + 1);
	return dayDiff;
}

void TreeTemp::set_date()
{
	while (1)
	{
		print();
		cout << "输入预期完成日期：" << endl;
		cout << "今日为 " << get_date(0) << endl;
		int num1;
		
        if (!(cin >> num1))
        {            
            cout << "输入错误，重新输入！" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
        }
		if (!check_date(num1))
		{
            cout << "输入错误，重新输入！" << endl;
			continue;
		}
		if (num1 <= get_date(0))
		{
            cout << "输入错误，重新输入！" << endl;
			continue;
		}
		adate = num1;
		daily_task();
		break;
	}
}

void TreeTemp::set_finish()
{
	while (1)
	{
		print();
		cout << "输入今日完成量：" << endl;
		int amount;
		
        if (!(cin >> amount))
        {            
            cout << "输入错误，重新输入！" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
        }
		if ((amount < 0) || (amount > (entirePart - donePart)))
		{
			cout << "完成量输入错误，重新输入！" << endl;
			continue;
		}
		donePart += amount;
		string rec = to_string(get_date(0)) + " 完成量：\t" + to_string(amount)
			+ "\t" + to_string(donePart-amount) + "-" + to_string(donePart);
		record.push_back(rec);
		daily_task();
		break;
	}
}

void TreeTemp::manipulate()
{
	while (1)
	{
		print();
		string num;
		cout << "****************************************" << endl;
		cout << "* 1. 显示记录                          *" << endl;
		cout << "* 2. 修改预期完成日期                  *" << endl;
		cout << "* 3. 输入今日完成量                    *" << endl;
		cout << "* c. 返回上一层                        *" << endl;
		cout << "****************************************" << endl;
		cin >> num;

		if (num == "1")
		{
			display_record();
			continue;
		}
		if (num == "2")
		{
			set_date();
			continue;
		}
		else if (num == "3")
		{
			set_finish();
			continue;
		}
		else if (num == "c")
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

string TreeTemp::get_title() const
{
	return task->name;
}