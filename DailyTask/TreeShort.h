#ifndef TREE_SHORT_H
#define TREE_SHORT_H

#include "Tree.h"
#include <vector>
#include <string>

class Node;

class TreeShort : public Tree
{
public:
	typedef std::vector<std::string>::size_type size_type;

	TreeShort(std::vector<std::string>);
	void print() const override;
	void print_ini(std::ofstream &) const override;
	void manipulate() override;
	std::string get_title() const override;
	~TreeShort() override;

	bool check_finish();

private:
	int btime = 0;
	int etime = 0;
	int ntask;
	std::vector<Node *> task;

	void set_state();
};

#endif