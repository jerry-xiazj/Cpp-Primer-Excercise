#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

class Tree;

class Node
{
friend class Tree;
friend class TreeTemp;
friend class TreeShort;
friend class TreePeriod;

public:
    Node() = default;
    Node(const std::string s): name(s) { }
    Node(const std::string s, bool b): name(s), finish(b) { }
    Node(int l, const std::string s): level(l), name(s) { }
    Node(int l, const std::string s, bool b): level(l), name(s), finish(b) { }
    Node(const Node &) = delete;
    Node & operator=(const Node &) = delete;

    void set_level(int l);
    void set_name(const std::string s);
    void set_state(bool b);
    void set_sub(Node *);
    void print() const;
    void print_ini(std::ofstream &) const;
    bool check_finish();

private:
    int level = 0;
    std::string name = "";
    bool finish = false;
    std::vector<Node *> pn;
};

#endif