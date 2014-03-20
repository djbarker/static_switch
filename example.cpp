#include <static_switch.hpp>
#include <typeinfo>
#include <iostream>

using namespace std;

constexpr int val = 0;

using the_type = static_switch<val,char
			,static_case<0,short>
			,static_case<1,int>
			,static_case<2,long>
			,static_case<3,double>
			>::type;

int main()
{
	cout << typeid(the_type).name() << endl;
	return 0;
}
