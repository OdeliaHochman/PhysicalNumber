
/**
 *
 * @author Carmel & Efrat & Odelia
 * @since 2019-04
 */

 # include <iostream>
 # include "PhysicalNumber.h"
 # include "Unit.h"



 using namespace std;
 using namespace ariel;

 PhysicalNumber::PhysicalNumber(double _num,Unit _unit)
 {
     num=_num;
     unit=_unit;
 }
 PhysicalNumber::~PhysicalNumber()
 {

 }
    double PhysicalNumber::getNum()
    {
        return num;
    }
    Unit PhysicalNumber::getUnit()
    {
        return unit;
    } 

       PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& other) const 
       {
           return other;
       }
       PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& other) const 
       {
           return other;
       }

       
       PhysicalNumber PhysicalNumber::operator-() const
       {
           return *this;
       }
       PhysicalNumber PhysicalNumber::operator+() const
       {
           return *this;
       }

    //    const PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& other) 
    //    {
    //        //add delete to .cpp
    //        return other;
    //    }
       const PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other)
       {
           return other;
       }
       const PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other)
       {
           return other;
       }

       const PhysicalNumber& PhysicalNumber::operator++()
       {
           num++;
           return *this;
       }
       const PhysicalNumber& PhysicalNumber::operator--()
       {
           num--;
           return *this;
       }

      PhysicalNumber PhysicalNumber::operator++(int)
      {
        //    PhysicalNumber temp(*this);
        //   num++;
        //   return temp;
          return *this;
      }
      PhysicalNumber PhysicalNumber::operator--(int)
      {
        //   PhysicalNumber temp(*this);
        //   num--;
        //   return temp;
        return *this;
      }

     

       bool PhysicalNumber::operator ==(const  PhysicalNumber&  a)const 
       {
           return true;
       }
       bool PhysicalNumber::operator !=(const  PhysicalNumber&  a)const
       {
           return true;
       }
       bool PhysicalNumber::operator <=(const  PhysicalNumber&  a)const 
       {
           return true;
       }
       bool PhysicalNumber::operator >=(const  PhysicalNumber&  a)const
       {
           return true;
       }
       bool PhysicalNumber::operator <(const  PhysicalNumber&  a)const 
       {
           return true;
       }
       bool PhysicalNumber::operator >(const  PhysicalNumber&  a)const
       {
           return true;
       }



     ostream& ariel::operator<<(ostream& os, const PhysicalNumber& p)
       {
           return os;
       }
        istream& ariel::operator>>(istream& is, PhysicalNumber& p)
       {
           return is;
       }

       
