#include "Node.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void Node::set_level(int l)
{
    level = l;
}

void Node::set_name(const string s)
{
    name = s;
}

void Node::set_state(bool b)
{
    finish = b;
}

void Node::set_sub(Node *p)
{
    pn.push_back(p);
}

void Node::print() const
{
    for (int ii = level; ii != 0; --ii) cout << "  ";
    if(finish) cout << "☑ ";
    else cout << "☐ ";
    cout << " " << name << endl;
}

void Node::print_ini(ofstream & outf) const
{
    outf << level << " " << name << " ";
    if(finish) outf << "y" << endl;
    else outf << "n" << endl;
}

bool Node::check_finish()
{
    if (!pn.empty())
    {
        if (finish == true)
        {
            for (auto itr : pn)
            {
                itr->set_state(true);
                itr->check_finish();
            }
        }
        else
        {
            finish = true;
            for (auto itr : pn)
            {
                if ((itr->check_finish()) == false)
                {
                    finish = false;
                }
            }
        }
    }
    return finish;
}