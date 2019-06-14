#include "TreePeriod.h"
#include "Node.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <limits>
#include <ctime>

using namespace std;

TreePeriod::TreePeriod(vector<string> text)
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
	is >> period >> nPeriod >> whichPeriod;

	is.clear();
	is.str(*begin++);
	is >> nextTime;

	is.clear();
	is.str(*begin++);
	is >> yORn;
	if (yORn == "y") active = true;
	else if (yORn == "n") active = false;

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

	if (whichPeriod < nPeriod)
	{
		task->set_state(false);
		if (nextTime < get_date(0)) active = false;
		else active = true;
	}
	else 
	{
		task->set_state(true);
		active = true;
	}
}

void TreePeriod::print() const
{
	cout << "| --------------------------------------" << endl;
	if (nPeriod == whichPeriod)
	{
		cout << "|" << "◆ " << task->name << " ，每" << period << "天一次" << endl;
		cout << "|  " << "循环已完成。 " << endl;
	}
	else if (active == false)
	{
		cout << "|" << "◇ " << task->name << " ，每" << period << "天一次" << endl;
		cout << "|  " << "已过期，需要激活! " << endl;
		cout << "|  " << "共" << nPeriod << "次" << endl;
		cout << "|  " << "已完成" << whichPeriod << "次" << endl;
		cout << "|  " << "下次时间为" << nextTime << endl;
	}
	else if (check_print())
	{
		cout << "|" << "◇ " << task->name << " ，每" << period << "天一次" << endl;
		cout << "|  ";
		task->print();
		cout << "|  " << "共" << nPeriod << "次" << endl;
		cout << "|  " << "已完成" << whichPeriod << "次" << endl;
		cout << "|  " << "下次时间为" << nextTime << endl;
	}
	else
	{
		cout << "|" << "◇ " << task->name << " ，每" << period << "天一次" << endl;
		cout << "|  " << "今日无任务 " << endl;
		cout << "|  " << "共" << nPeriod << "次" << endl;
		cout << "|  " << "已完成" << whichPeriod << "次" << endl;
		cout << "|  " << "下次时间为" << nextTime << endl;
	}
	cout << "| --------------------------------------" << endl;
}

void TreePeriod::print_ini(ofstream & outf) const
{
	//顺序式输出
	outf << type << endl;
	outf << period << " " << nPeriod << " " << whichPeriod << endl;
	outf << nextTime << endl;
	if (active) outf << "y" << endl;
	else outf << "n" << endl;
	task->print_ini(outf);
	for (auto &s : record)
	{
		outf << s << endl;
	}
	outf << endl;
}

bool TreePeriod::check_print() const
{
	return ((get_date(0) == nextTime) && (whichPeriod != nPeriod));
}

bool TreePeriod::check_date(int date) const
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

TreePeriod::~TreePeriod()
{
	delete task;
}

void TreePeriod::set_finish()
{
	string rec = to_string(nextTime) + " 任务已完成";
	record.push_back(rec);
	if(++whichPeriod >= nPeriod)
	{
		task->set_state(true);
	}
	else
	{
		nextTime = get_date(period);
	}
}

void TreePeriod::set_change()
{
	while (1)
	{
		print();
		string num;
		cout << "****************************************" << endl;
		cout << "* 1. 修改周期、总周期数、已完成周期数  *" << endl;
		cout << "* 2. 修改下一次任务时间                *" << endl;
		cout << "* c. 返回上一层                        *" << endl;
		cout << "****************************************" << endl;
		cin >> num;

		if (num == "1")
		{
			change_period();
			break;
		}
		else if (num == "2")
		{
			change_next();
			break;
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

void TreePeriod::change_period()
{
	while (1)
	{
		print();
		int num1, num2 ,num3;
		cout << "输入：修改周期、总周期数、已完成周期数 " << endl;
		if (!(cin >> num1 >> num2 >> num3))
        {            
            cout << "输入错误，重新输入！" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
        }
		if (num3 > num2)
		{
            cout << "输入错误，重新输入！" << endl;
			continue;
		}
		if ((num1 <= 0) || (num2 <= 0) || (num3 < 0))
		{
            cout << "输入错误，重新输入！" << endl;
			continue;
		}
		period = num1;
		nPeriod = num2;
		whichPeriod = num3;
		break;
	}
}

void TreePeriod::change_next()
{
	while (1)
	{
		print();
		int num1;
		cout << "输入：下一次任务时间 " << endl;
		cout << "今日为 " << get_date(0) << endl;
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
		if (num1 < get_date(0))
		{
            cout << "不能早于今日，重新输入！" << endl;
			continue;
		}
		nextTime = num1;
		active = true;
		break;
	}	
}

void TreePeriod::manipulate()
{
	while (1)
	{
		if (check_print())
		{
			print();
			string num;
			cout << "****************************************" << endl;
			cout << "* 1. 显示记录                          *" << endl;
			cout << "* 2. 今日任务已完成                    *" << endl;
			cout << "* 3. 修改本任务                        *" << endl;
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
				set_finish();
				continue;
			}
			else if (num == "3")
			{
				set_change();
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
		else
		{
			print();
			string num;
			cout << "****************************************" << endl;
			cout << "* 1. 显示记录                          *" << endl;
			cout << "* 2. 修改本任务                        *" << endl;
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
				set_change();
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
}

string TreePeriod::get_title() const
{
	return task->name;
}