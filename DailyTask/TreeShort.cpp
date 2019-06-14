#include "TreeShort.h"
#include "Node.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <limits>

using namespace std;

TreeShort::TreeShort(vector<string> text)
{
	string name;
	int level;
	string yORn;
	bool finish;
	vector<Node *> tempNode(3);
	auto begin = text.begin();

	istringstream is(*begin++);
	is >> type;
	
	is.clear();
	is.str(*begin++);
	is >> btime >> etime >> ntask;

	//读取内容
	for (int index = 0; index != ntask; ++index)
	{
		//读取level、name和finish
		is.clear();
		is.str(*begin++);
		is >> level >> name >> yORn;

		if (yORn == "y") finish = true;
		else if (yORn == "n") finish = false;
		//根据读取的level、name和finish创建动态Node对象，并将指针存入当前shortTree中
		task.push_back(new Node(level, name, finish));
		//tempNode中存储了每一个level最新的Node对象的指针
		tempNode[level] = *(--task.end());
		//如果nowRead不是顶层对象，将nowRead挂到上一个level的对象下
		if (level != 0)
		{
			(tempNode[level - 1]->pn).push_back(*(--task.end()));
		}
	}
	check_finish();
	while (begin != text.end())
	{
		record.push_back(*begin++);
	}
}

void TreeShort::print() const
{
	auto iter = task.cbegin();
	cout << "| --------------------------------------" << endl;
	if (finishTree)
	{
		cout << "|" << "■ " << (*iter)->name << endl;
	}
	else
	{
		cout << "|" << "□ " << (*iter)->name << endl;
	}
	cout << "|  " << "开始时间: " << btime << endl;
	cout << "|  " << "完成期限: " << etime << endl;
	for (auto iter = task.cbegin(); iter != task.cend(); ++iter)
	{
		int index = 0;
		cout << "|  " << index << ". ";
		++index;
		(*iter)->print();
	}
	cout << "| --------------------------------------" << endl;
}

void TreeShort::print_ini(ofstream & outf) const
{
	outf << type << endl;
	outf << btime << " " << etime << " " << ntask << endl;
	for (auto iter = task.cbegin(); iter != task.cend(); ++iter)
	{
		(*iter)->print_ini(outf);
	}	
	for (auto &s : record)
	{
		outf << s << endl;
	}
	outf << endl;
}

bool TreeShort::check_finish()
{
	auto itr = task.begin();
	finishTree = (*itr)->check_finish();
	return finishTree;
}

TreeShort::~TreeShort()
{
	for (auto ptr : task)
	{
		delete ptr;
	}
}

void TreeShort::set_state()
{
	while (1)
	{
		print();
		size_type num;
		cout << "输入任务序号：" << endl;
		
        if (!(cin >> num))
        {            
            cout << "输入错误，重新输入！" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
        }
		if (!((num >= 0) && (num <= task.size())))
		{
			cout << "输入错误，重新输入！" << endl;
			continue;
		}
		task[num]->set_state(true);
		string rec = to_string(get_date(0)) + "\t" + task[num]->name + " 已完成";
		record.push_back(rec);
		check_finish();
		cout << "修改成功！" << endl;
		break;
	}
}

void TreeShort::manipulate()
{
	while (1)
	{
		print();
		string num;
		cout << "****************************************" << endl;
		cout << "* 1. 显示记录                          *" << endl;
		cout << "* 2. 完成一项任务                      *" << endl;
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
			set_state();
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

string TreeShort::get_title() const
{
	return task[0]->name;
}