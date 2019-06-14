#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <vector>
#include <string>
#include <memory>
#include "StrBlob.h"

class StrBlobPtr
{
  public:
    //构造函数
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob& a, size_t sz = 0): wptr(a.data), curr(sz) {}

    //解引用
    std::string &deref() const;

    //类似于递增迭代器
    StrBlobPtr &incr();

  private:
    std::shared_ptr<std::vector<std::string>>
      check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

#endif