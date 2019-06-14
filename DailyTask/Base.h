#ifndef BASE_H
#define BASE_H

#include <vector>

class Tree;

class Base
{
public:
	typedef std::vector<Tree *>::size_type size_type;

    //读取data.ini创建Base对象
    Base();

	//操作任务树#1
	void manipulate_tree();

    //增加任务树
    void add_tree();

	//删除任务树
	void delete_tree();

    //增删交互界面#2
    void add_or_delete();

    //更新data.ini文件#s
    void print_ini();

    //交互界面
    void interface();
    
    Base(const Base &) = delete;
    Base & operator=(const Base &) = delete;
    ~Base();
	
private:
    std::vector<Tree *> forest;
    //显示内容到屏幕
    void print_tree();
    //显示标题到屏幕
    void print_title();
};

#endif