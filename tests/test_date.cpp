#include "doctest.h"

#include "date/date.h"

using namespace date;
using namespace std::chrono;

TEST_CASE("testing date equivalence")
{
    std::stringstream ss;
    auto d1 = year{2021}/11/25;
    year_month_day d2 = year{2021} / 11 / 25;
    CHECK(d1 == d2);
    ss << d1;
    CHECK(ss.str() == "2021-11-25");
}

TEST_CASE("testing date to string")
{
    std::stringstream ss;
    auto d1 = year{2021} / 11 / 25;
    ss << d1;
    CHECK(ss.str() == "2021-11-25");
}

TEST_CASE("testing date arithmetic")
{
    std::stringstream ss;
    auto d1 = year{2021} / 11 / 25;
    auto d2 = d1 + years{1};
    ss << d2;
    CHECK(ss.str() == "2022-11-25");
}