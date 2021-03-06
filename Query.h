#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <string>
#include <memory>

#include "TextQuery.h"
#include "QueryResult.h"
#include "QueryBase.h"
#include "WordQuery.h"

std::ostream &operator<<(std::ostream&, const Query&);

class Query
{
  friend Query operator~(const Query&);
  friend Query operator|(const Query&, const Query&);
  friend Query operator&(const Query&, const Query&);

  public:
    inline Query(const std::string &s) : q(new WordQuery(s)) {}
    Query(std::shared_ptr<QueryBase> query) : q(query) {}
    QueryResult eval(const TextQuery &t) const
      { return q->eval(t); }
    std::string rep() const { return q->rep(); }
    std::shared_ptr<QueryBase> q;
};


#endif
