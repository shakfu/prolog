#ifndef PROLOG_MODEL_QUOTE_H
#define PROLOG_MODEL_QUOTE_H

#include <model/common.hpp>
#include <model/vehicle.hpp>

#include <string>

namespace model
{

class Quote
{
  public:
    string name;

    string to_string();
};

} // namespace model

#endif // PROLOG_MODEL_QUOTE_H
