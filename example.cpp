#include <static_switch.hpp>
#include <typeinfo>
#include <iostream>

using namespace std;

// switch based upon integer value
constexpr int val = 0;
using the_type = static_switch<val,char
			,static_case<0,short>
			,static_case<1,int>
			,static_case<2,long>
			,static_case<3,double>
			>::type;

// switch based upon type
using type = double;
using the_type2 = static_type_switch<type,char
			,static_type_case<int,short>
			,static_type_case<double,int>
			,static_type_case<float,long>
			,static_type_case<long,double>
			>::type;

int main()
{
	cout << typeid(the_type).name() << endl;
	cout << typeid(the_type2).name() << endl;
	return 0;
}
