#include <iostream>
#include "span.hpp"


int main()
{
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.printContent();
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	//Long test
	Span sp1 = Span(12000);

	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
		sp1.addNumber(rand() % 500);
	
	sp1.printContent();

	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;
}