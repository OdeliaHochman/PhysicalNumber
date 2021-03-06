
/**
 *
 * @author Carmel & Efrat & Odelia
 * @since 2019-04
 */

#include <iostream>
#include <sstream>
#include "PhysicalNumber.h"
#include "Unit.h"

using namespace std;
using namespace ariel;

PhysicalNumber::PhysicalNumber(double _num, Unit _unit)
{
    num = _num;
    unit = _unit;
}

PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &other) const
{

    double res = convert(*this, other); // if not able to convert - throw exception

    return PhysicalNumber(this->num + res, this->unit);
}
PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &other) const
{
    double res = convert(*this, other); // if not able to convert - throw exception

    return PhysicalNumber(this->num - res, this->unit);
}

PhysicalNumber PhysicalNumber::operator-()
{
    return PhysicalNumber(-1 * num, unit);
}
PhysicalNumber PhysicalNumber::operator+() const
{
    return PhysicalNumber(num, unit);
}

PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &other)
{

    double res = convert(*this, other); // if not able to convert - throw exception

    this->num = this->num + res;
    return *this;
}
PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &other)
{
    double res = convert(*this, other); // if not able to convert - throw exception

    this->num = this->num - res;
    return *this;
}

PhysicalNumber &PhysicalNumber::operator++()
{
    num++;
    return *this;
}
PhysicalNumber &PhysicalNumber::operator--()
{
    num--;
    return *this;
}

PhysicalNumber PhysicalNumber::operator++(int)
{
    PhysicalNumber temp(*this);
    num++;
    return temp;
}
PhysicalNumber PhysicalNumber::operator--(int)
{
    PhysicalNumber temp(*this);
    num--;
    return temp;
}

bool PhysicalNumber::operator==(const PhysicalNumber &a) const
{

    double number = 0;

    number = convert(*this, a); // if not able to convert - throw exception

    if ((this->num) == number)
        return true;

    return false;
}
bool PhysicalNumber::operator!=(const PhysicalNumber &a) const
{
    double number = 0;

    number = convert(*this, a); // if not able to convert - throw exception

    return this->num != number;
}

bool PhysicalNumber::operator<=(const PhysicalNumber &a) const
{
    double number = 0;

    number = convert(*this, a); // if not able to convert - throw exception

    return this->num <= number;
}
bool PhysicalNumber::operator>=(const PhysicalNumber &a) const
{
    double number = 0;

    number = convert(*this, a); // if not able to convert - throw exception

    return this->num >= number;
}
bool PhysicalNumber::operator<(const PhysicalNumber &a) const
{
    double number = 0;

    number = convert(*this, a); // if not able to convert - throw exception

    return this->num < number;
}
bool PhysicalNumber::operator>(const PhysicalNumber &a) const
{
    double number = 0;

    number = convert(*this, a); // if not able to convert - throw exception

    return this->num > number;
}

double PhysicalNumber::convert(const PhysicalNumber &p1, const PhysicalNumber &p2) const
{
    double res = 0;
    double left_value = p1.num;
    double right_value = p2.num;

    Unit left_unit = p1.unit;
    Unit right_unit = p2.unit;

    switch (right_unit)
    {
    case Unit::KM:

        if (left_unit == Unit::M) // km to m
        {
            res = right_value * 1000;
        }
        else if (left_unit == Unit::CM) //km to cm
        {
            res = right_value * 100000;
        }
        else if (left_unit == Unit::KM)
        { // kg to kg

            res = right_value * 1;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;
    case Unit::M:

        if (left_unit == Unit::CM) //m to cm
        {
            res = right_value * 100;
        }
        else if (left_unit == Unit::KM) //m to km
        {
            res = right_value / 1000;
        }
        else if (left_unit == Unit::M)
        { // m to m

            res = right_value * 1;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;
    case Unit::CM:

        if (left_unit == Unit::M) // cm to m
        {
            res = right_value / 100;
        }
        else if (left_unit == Unit::KM) // cm to km
        {
            res = right_value / 100000;
        }
        else if (left_unit == Unit::CM)
        { // cm to cm

            res = right_value * 1;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;
    case Unit::HOUR:

        if (left_unit == Unit::MIN) // hour to min
        {
            res = right_value * 60;
        }
        else if (left_unit == Unit::SEC) // hour to sec
        {
            res = right_value * 3600;
        }
        else if (left_unit == Unit::HOUR)
        { // hour to hour

            res = right_value * 1;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;
    case Unit::MIN:

        if (left_unit == Unit::HOUR) // min to hour
        {
            res = right_value / 60;
        }
        else if (left_unit == Unit::SEC) //min to sec
        {
            res = right_value * 60;
        }
        else if (left_unit == Unit::MIN)
        {
            // min to min

            res = right_value * 1;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;
    case Unit::SEC:

        if (left_unit == Unit::MIN) // sec to min
        {
            res = right_value / 60;
        }
        else if (left_unit == Unit::HOUR) // sec to hour
        {
            res = right_value / 3600;
        }
        else if (left_unit == Unit::SEC)
        { // sec to sec

            res = right_value * 1;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;
    case Unit::TON:

        if (left_unit == Unit::KG) //ton to kg
        {
            res = right_value * 1000;
        }
        else if (left_unit == Unit::G) //ton to g
        {
            res = right_value * 1000000;
        }
        else if (left_unit == Unit::TON)
        { // ton to tom

            res = right_value * 1;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;
    case Unit::KG:

        if (left_unit == Unit::G) // kg to g
        {
            res = right_value * 1000;
        }
        else if (left_unit == Unit::TON) //kg to ton
        {
            res = right_value / 1000;
        }
        else if (left_unit == Unit::KG)
        { // kg to kg

            res = right_value * 1;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;
    case Unit::G:

        if (left_unit == Unit::TON) // g to ton
        {
            res = right_value / 1000000;
        }
        else if (left_unit == Unit::KG) // g to kg
        {
            res = right_value / 1000;
        }
        else if (left_unit == Unit::G)
        { // g to g

            res = right_value * 1;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;

    default:

        throw std::invalid_argument("can't convert");
    }

    return res;
}

ostream &ariel::operator<<(ostream &os, const PhysicalNumber &p)
{
    switch (p.unit)
    {
    case Unit::KM:
    {
        os << p.num << "[km]";
        break;
    }

    case Unit::M:
    {
        os << p.num << "[m]";
        break;
    }

    case Unit::CM:
    {
        os << p.num << "[cm]";
        break;
    }

    case Unit::MIN:
    {
        os << p.num << "[min]";
        break;
    }
    case Unit::HOUR:
    {
        os << p.num << "[hour]";
        break;
    }
    case Unit::SEC:
    {
        os << p.num << "[sec]";
        break;
    }
    case Unit::TON:
    {
        os << p.num << "[ton]";
        break;
    }
    case Unit::G:
    {
        os << p.num << "[g]";
        break;
    }
    case Unit::KG:
    {
        os << p.num << "[kg]";
        break;
    }
    }
    return os;
}
istream &ariel::operator>>(istream &is, PhysicalNumber &p)
{

    string s;
    is >> s;
    int pos1 = 0;
    int pos2 = 0;

    string unit_s;
    int check_num;
    double value;
    string typeUnit[9] = {"km", "m", "cm", "hour", "min", "sec", "ton", "kg", "g"};

    pos1 = s.find('[');
    pos2 = s.find(']');
    if ((pos1 != string::npos) && (pos2 != string::npos)) // if there is [ ]

    {

        unit_s = s.substr(pos1 + 1, pos2 - pos1 - 1);
        bool flag = true;
        for (int i = 0; i < 9; i++)
        {
            if ((typeUnit[i] == unit_s) && flag)
            {
                check_num = i;
                flag = false;
            }
        }

        string value_s = s.substr(0, pos1);

        if (!flag)
        {

            try
            {
                value = stod(value_s);
            }

            catch (exception &e)
            {
                auto errorState = is.rdstate(); // remember error state
                return is;
            }

            p.num = value;
            p.unit = (Unit)check_num;
        }
        else
        {
            auto errorState = is.rdstate(); // remember error state
        }
    }

    else
    {
        auto errorState = is.rdstate(); // remember error state
    }

    return is;
}