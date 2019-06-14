#include "Base.h"
#include "TreeShort.h"
#include "TreeTemp.h"
#include "TreePeriod.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <ctime>

using namespace std;

Base::Base()
{
    ifstream ini("data.ini");
    string temp;
    vector<string> text;
    while (getline(ini, temp))
    {
        if (temp == "end") break;
        if ((temp == "\r") || (temp == ""))
        {
			if ((text[0] == "short") || (text[0] == "short\r"))
			{
				TreeShort * newTree = new TreeShort(text);
				newTree->check_finish();
				forest.push_back(newTree);
			}
			if ((text[0] == "temp") || (text[0] == "temp\r"))
			{
				TreeTemp * newTree = new TreeTemp(text);
				newTree->check_finish();
				forest.push_back(newTree);
			}
			if ((text[0] == "period") || (text[0] == "period\r"))
			{
				TreePeriod * newTree = new TreePeriod(text);
				forest.push_back(newTree);
			}
            text.clear();
        }
        if ((temp != "\r") && (temp != "")) text.push_back(temp);
    }
    ini.close();
}

void Base::add_tree()
{
    while(1)
    {
        string file;
        cout << "输入文件名称:";
        cin >> file;
        ifstream infile(file);
        if (!infile.is_open())
        {
            cout << "文件不存在，重新输入！ " << endl;
            continue;
        }
        string temp;
        vector<string> vs;
        while(getline(infile, temp)) vs.push_back(temp);
        infile.close();
        if (vs[0] == "short")
        {
            TreeShort * newTree = new TreeShort(vs);
            newTree->check_finish();
            forest.push_back(newTree);
        }
        if (vs[0] == "temp")
        {
            TreeTemp * newTree = new TreeTemp(vs);
            newTree->check_finish();
            forest.push_back(newTree);
        }
        if (vs[0] == "period")
        {
            TreePeriod * newTree = new TreePeriod(vs);
            forest.push_back(newTree);
        }
        cout << "输入成功!" << endl;
        break;
    }
}

void Base::delete_tree()
{
	while (1)
	{
		size_type num;
        print_title();
		cout <<"输入任务序号:"<< endl;

        if (!(cin >> num))
        {            
            cout << "输入错误，重新输入！" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

		if (!((num <= forest.size()) && (num >= 1)))
		{
			cout << "输入错误，重新输入!" << endl;
			continue;
		}
		auto delItr = forest.begin() + num - 1;
		delete *delItr;
		forest.erase(delItr);
		cout << "删除成功!" << endl;
		break;
	}

}

void Base::add_or_delete()
{
    while(1)
    {
        string num;
		cout << "****************************************" << endl;
		cout << "* 1. 增加任务                           *" << endl;
		cout << "* 2. 删除任务                           *" << endl;
		cout << "* c. 返回上一层                        *" << endl;
		cout << "****************************************" << endl;
        cin >> num;
    
		if (num == "1")
		{
			add_tree();
			break;
		}
		else if (num == "2")
		{
			delete_tree();
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

void Base::manipulate_tree()
{
	while (1)
	{
		size_type num;
        print_title();
		cout << "输入任务序号:" << endl;
        
        if (!(cin >> num))
        {            
            cout << "输入错误，重新输入！" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

		if ((num >= 1) && (num <= forest.size()))
		{
            forest[num - 1]->manipulate();
            break;
		}
        else
        {
            cout << "输入错误，重新输入！" << endl;
			continue;
        }

	}
}

void Base::print_ini()
{
    ofstream outf("data.ini", ofstream::out);
    for (auto ptr : forest)
    {
        ptr->print_ini(outf);
    }
    outf << "end";
    outf.close();
	cout << "保存成功!" << endl;
}

void Base::interface()
{
    string choice;
    string file;
	print_tree();

    while(1)
    {
        cout<<"******************操作******************"<<endl
            <<"* 1. 操作任务                          *" << endl
            <<"* 2. 增删任务                          *" << endl
            <<"* s. 保存修改                          *" << endl
            <<"* e. 退出                              *" << endl
            <<"****************************************"<<endl;
        cin >> choice;
        if(choice.compare("e") == 0)
        {
            cout<<"****************************************"<<endl
                <<"*有志者 事竟成 破釜沉舟 百二秦关终属楚 *"<<endl
                <<"*苦心人 天不负 卧薪尝胆 三千越甲可吞吴 *"<<endl
                <<"****************************************"<<endl;
            break;
        }
        else if(choice == "1") 
        {
			manipulate_tree();
			print_tree();
        }
        else if(choice == "2") 
        {
            add_or_delete();
			print_tree();
        }
        else if(choice == "s")
        {
            print_ini();
			print_tree();
        }
        else
        {
            cout << "输入错误，重新输入！" << endl;
			print_tree();
        }
    }
}

Base::~Base()
{
    for (auto ptr : forest)
    {
        delete ptr;
    }
}

void Base::print_tree()
{
	cout << "****************************************" << endl
		<< "*               今日任务               *" << endl
		<< "****************************************" << endl;
    int i = 1;
    for (auto ptr : forest)
    {
        cout << "| >>" << i++ << "." << endl;
        ptr->print();
        cout << "|" << endl;
    }
}

void Base::print_title()
{
	cout<< "| --------------------------------------" << endl;
    int i = 1;
    for (auto ptr : forest)
    {
        cout << "| " << i++ << ". " << ptr->get_title() << endl;
    }
	cout<< "| --------------------------------------" << endl;
}
