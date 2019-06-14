#ifndef TREE_PERIOD_H
#define TREE_PERIOD_H

#include "Tree.h"
#include <vector>
#include <string>

class Node;

class TreePeriod : public Tree
{
public:
	TreePeriod(std::vector<std::string>);
	void print() const override;
	void print_ini(std::ofstream &) const override;
	void manipulate() override;
	std::string get_title() const override;
	~TreePeriod() override;

private:
	int period = 1;
	int nPeriod = 1;
	int whichPeriod = 1;
	int nextTime;
	bool active = true;
	Node* task;
	
	bool check_print() const;	//判断是否是任务日
	bool check_date(int) const;	//判断输入的日期是否正确，在change_next中用到

	void set_finish();
	void set_change();
	void change_period();
	void change_next();
};

#endif
