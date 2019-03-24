#include "Conversion.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Conversion value(argv[1]);

		std::cout << "char: ";
		try
		{
			char	result = static_cast<char>(value);

			if (result >= 33 && result <= 126)
				std::cout << "'" << result << "'" << std::endl;
			else if (result == 127 || (result >= -128 && result < 33))
				std::cout << "Non displayable" << std::endl;
			else
				std::cout << "conversion error" << std::endl;
		}
		catch (Conversion::ConversionErrorException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Cannot Convert" << std::endl;
		}
		
		std::cout << "int: ";
		try
		{
			std::cout << static_cast<int>(value) << std::endl;
		}
		catch (Conversion::ConversionErrorException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Cannot Convert" << std::endl;
		}

		std::cout << "float: ";
		try
		{
			std::cout << static_cast<float>(value) << "f" << std::endl;
		}
		catch (Conversion::ConversionErrorException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Cannot Convert" << std::endl;
		}

		std::cout << "double: ";
		try
		{
			std::cout << static_cast<double>(value) << std::endl;
		}
		catch (Conversion::ConversionErrorException &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Cannot Convert" << std::endl;
		}
	}
	else
		std::cout << "Only one argument allow" << std::endl;
	return (0);
}