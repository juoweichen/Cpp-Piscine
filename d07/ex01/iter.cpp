#include <iostream>

template <typename T>
void print_array(T & data)
{
	std::cout << data << std::endl;
}

template <typename T>
void	iter(T *addr, size_t length, void (*func)(T &))
{
	for (size_t i = 0; i < length; i++)
		(*func)(addr[i]);
}

int	main(void)
{
	std::string	test1[] = {"ABC", "BCD", "CDE", "EFG", "GHI"};
	char		test2[] = {'a', 'b', 'c', 'd', 'e'};
	int			test3[] = {1, 20, 300, 4000, 50000};
	double		test4[] = {1.00, 2.00, 3.00, 4.00, 5.00};

	std::cout << "test1: std::string array iter" << std::endl;
	iter(test1, 5, print_array);
	std::cout << "test2: char array iter" << std::endl;
	iter(test2, 5, print_array);
	std::cout << "test3: int array iter" << std::endl;
	iter(test3, 5, print_array);
	std::cout << "test4: double array iter" << std::endl;
	iter(test4, 5, print_array);
	return 0;
}