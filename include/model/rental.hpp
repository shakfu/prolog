#ifndef PROLOG_MODEL_RENTAL_H
#define PROLOG_MODEL_RENTAL_H

#include <model/common.hpp>
#include <model/customer.hpp>
#include <model/vehicle.hpp>

#include <string>

namespace model
{

class Rental
{
  public:
    Customer customer;
    Vehicle vehicle;

    Date start_date;
    Date end_date;

    float day_rate;
    Currency currency;

    float total_price();
    string to_string();
};

} // namespace model

#endif // PROLOG_MODEL_RENTAL_H
