#ifndef TREE_H
#define TREE_H

#include <string>
#include <vector>
#include <fstream>

class Node;
class Base;

class Tree
{
friend class Base;

public:
    Tree() = default;
    virtual void print() const = 0;
    virtual void print_ini(std::ofstream &) const = 0;
	virtual void manipulate() = 0;
	virtual std::string get_title() const = 0;

	std::string getType();
	int current_date();
    void display_record();
	int get_date(int) const;	//获得某天后的日期，格式：20181225

    Tree(const Tree &) = delete;
    Tree & operator=(const Tree &) = delete;
	virtual ~Tree() {}

protected:
	bool finishTree = false;
    std::string type = "temp";
    std::vector<std::string> record;
};

#endif