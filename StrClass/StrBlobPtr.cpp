#include "StrBlobPtr.h"
#include <stdexcept>

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbounded StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

std::string& StrBlobPtr::deref() const
{
    auto ret = check(curr, "dereference past end");
    return (*ret)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end");
    ++curr;
    return *this;
}