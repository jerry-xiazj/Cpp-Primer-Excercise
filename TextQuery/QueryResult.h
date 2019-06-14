#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include "TextQuery.h"

class QueryResult
{
friend std::ostream& print(std::ostream&, const QueryResult&);

public:
QueryResult
(
    std::string s,
    std::shared_ptr<std::set<TextQuery::line_no>> p,
    std::shared_ptr<std::vector<std::string>> f
): sought(s), lines(p), file(f) { }

private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

#endif