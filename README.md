static_switch
=============

*Meta-programmatically select a C++ type at compile-time based upon a compile-time constant or preprocessor #define.*

I recently had the need to select a C++ type based upon the value of a preprocessor `#define` macro. The problem can be solved by using a class which is templated on the macro's value, as follows;

```C++
#define SOME_VALUE 0

template<int I> struct CPP_type{ typedef int type; /* default value */ };
template<> struct CPP_type<0>{ typedef char type; };
template<> struct CPP_type<1>{ typedef short type; };
template<> struct CPP_type<2>{ typedef long type; };

using some_type = CPP_type<SOME_VALUE>::type;
```

where additional cases are provided by specializing the template class `CPP_type`. *But* if one had many cases, or needed to do this more than once, this solution would rapidly become unwieldy. Each C++ type requires a new template class and each case requires a new specialization (including all the syntax which accompanies that) of said class. Further it might not be immediately obvious to another reader what this piece of code does. 

Therefore I wrote a meta-function called `static_switch` which recreates this behaviour but syntactically looks much more like the usual `switch` statement. The use of `static_switch` maintains the readability of the code. Using `static_switch` the example above becomes

```C++
#define SOME_VALUE 0

using some_type = static_switch<SOME_VALUE
				,int // default case
				,static_case<0,char>
				,static_case<1,short>
				,static_case<2,long>
				>::type;
```
