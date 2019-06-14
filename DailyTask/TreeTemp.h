#ifndef TREE_TEMP_H
#define TREE_TEMP_H

#include "Tree.h"
#include <vector>
#include <string>

class Node;

class TreeTemp : public Tree
{
public:
	TreeTemp(std::vector<std::string>);
	void print() const override;
	void print_ini(std::ofstream &) const override;
	void manipulate() override;
	std::string get_title() const override;
	~TreeTemp() override;

	bool check_finish();

private:
	int donePart = 0;
	int entirePart = 0;
	int adate;
	int dtask;
	Node* task;
	
	bool check_date(int) const;	//判断输入的日期是否正确
	void daily_task();
	int day_left() const;

	void set_date();
	void set_finish();
};

#endif
