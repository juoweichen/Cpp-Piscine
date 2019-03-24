template <typename T>
void swap(T * src1, T * src2)
{
	T tmp;

	tmp = *src1;
	*src1 = *src2;
	*src2 = tmp;
}


template <typename T>
void swapA(T & src1, T & src2)
{
	T tmp;

	tmp = src1;
	src1 = src2;
	src2 = tmp;
}


template <typename T>
T min(T src1, T src2)
{
	if (src1 < src2)
		return (src1);
	else
		return (src2);
}

template <typename T>
T max(T src1, T src2)
{
	if (src1 > src2)
		return (src1);
	else
		return (src2);
}

#include <iostream>

int main(void)
{
	int a = 2;
	int b = 3;
	
	::swap( &a, &b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap( &c, &d );
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}