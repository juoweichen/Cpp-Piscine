#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>

struct Data
{
	std::string		s1;
	int				n;
	std::string		s2;
};

void * serialize( void )
{
	char	*newdata = new char[20];
	char	c;
	int		i;
	int		n;

	static char ran[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::cout << "serialized data info:" << std::endl;
	std::cout << "[";
	for (i = 0; i < 8; i++)
	{
		c = ran[rand() % static_cast<int>(sizeof(ran) -1)];
		newdata[i] = c;
		std::cout << c;
	}
	std::cout << "][";
	for (i = 8; i < 12; i++)
	{
		c = ran[rand() % 10];
		newdata[i] = c;
		n = c - '0';
		std::cout << n;
	}
	std::cout << "][";
	for (i = 12; i < 20; i++)
	{
		c = ran[rand() % static_cast<int>(sizeof(ran) -1)];
		newdata[i] = c;
		std::cout << c;
	}
	std::cout << "]" << std::endl;
	return reinterpret_cast<void *>(newdata);
}

Data * deserialize( void * raw )
{
	Data		*data = new Data;
	char 		*input = reinterpret_cast<char *>(raw);
	int i;

	for (i = 0; i < 8; i++)
	{
		data->s1 = data->s1 + input[i];
	}
	for (i = 8; i < 12; i++)
	{
		data->n = data->n * 10 + input[i] - '0';
	}
	for (i = 12; i < 20; i++)
	{
		data->s2 = data->s2 + input[i];
	}
	delete input;
	return (data);
}

void	print_info(Data *data)
{
	std::cout << "size alloc info:" << std::endl;
	std::cout << "sizeof data: " << sizeof(data) << std::endl;
	std::cout << "sizeof Data: " <<sizeof(Data) << std::endl;
	std::cout << "sizeof std::string: " << sizeof(std::string) << std::endl;
	std::cout << "sizeof data->s1: " << data->s1.length() << std::endl;
	std::cout << "length data->s1: " << sizeof(data->s1) << std::endl;
	std::cout << "sizeof data->n: " << sizeof(data->n) << std::endl;
	std::cout << "length data->s2: " << data->s2.length() << std::endl;
	std::cout << "sizeof data->s1: " << sizeof(data->s2) << std::endl;
}

int		main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	void *ser = serialize();
	Data *data = deserialize(ser);

	std::cout << "deserialize data info:" << std::endl;
	std::cout << data->s1 << std::endl << data->n << std::endl
	          << data->s2 << std::endl;
	// print_info(data);
	delete data;
	return 0;
}
