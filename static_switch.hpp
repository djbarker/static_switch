#include <type_traits>

/*
 * Select a type based on the value of a compile-time constant such as a
 * constexpr or #define using static_switch.
 */

template<int I,class T>
struct static_case {
	static constexpr int value = I;
	using type = T;
};

template<int I, class DefaultType, class Case1, class... OtherCases>
struct static_switch{
	using type = typename std::conditional< I==Case1::value , 
					typename Case1::type,
					typename static_switch<I,DefaultType,OtherCases...>::type
				     >::type;
};

template<int I, class DefaultType, class LastCase>
struct static_switch<I,DefaultType,LastCase> {
	using type = typename std::conditional< I==LastCase::value , 
					typename LastCase::type,
					DefaultType
				     >::type;
};
