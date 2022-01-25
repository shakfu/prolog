#ifndef PROLOG_MODEL_CUSTOMER_H
#define PROLOG_MODEL_CUSTOMER_H

#include <model/common.hpp>
#include <model/rental.hpp>

#include <string>
#include <vector>

namespace model
{

class Customer
{
  public:
    string name;
    string company;
    Date dob;
    Date license_expiry;
    bool is_premium;
    float discount;
    bool is_blacklisted;

    std::vector<Rental> rentals;

    int rent(Rental r);
    int returns(Rental r);
    int cancel(Rental r);

    string to_string();
};

} // namespace model

#endif // PROLOG_MODEL_CUSTOMER_H
