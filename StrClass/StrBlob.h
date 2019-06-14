#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
//#include "StrBlobPtr.h" 
//如果加上此语句，会出错。原因在于此时编译器还不认识StrBlob类，而StrBlobPtr.h用到了StrBlob

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;

    public:
    //类型别名
    typedef std::vector<std::string>::size_type size_type;

    //构造函数
    StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il): 
        data(std::make_shared<std::vector<std::string>>(il)) {}

    //大小、插入、删除
    size_type size() const {return data->size(); }
    bool empty() const {return data->empty(); }
    void push_back(const std::string &t) {data->push_back(t);}
    void pop_back();

    //读取首尾
    std::string& front();
    const std::string& front() const;
    std::string& back();

    //返回首尾StrBlobPtr指针
    StrBlobPtr begin();
    StrBlobPtr end();

    private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

#endif