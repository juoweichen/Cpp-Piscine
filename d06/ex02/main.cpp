#include <iostream>
#include <ctime>
#include <cstdlib>

class Base {
	public:
		virtual ~Base() {}
};
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void)
{
	int	rand_nb = rand() % 3;
	switch (rand_nb)
	{
		case 0: std::cout << "generate A" << std::endl; return (new A());
		case 1: std::cout << "generate B" << std::endl; return (new B());
		case 2: std::cout << "generate C" << std::endl; return (new C());
		default: std::cout << "generate failed!" << std::endl; return (NULL);
	}
}

void identify_from_pointer( Base * p )
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "not one of A, B, C" << std::endl;
}

void identify_from_reference( Base & p )
{
	if (dynamic_cast<A *>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(&p))
		std::cout << "C" << std::endl;
	else
		std::cout << "not one of A, B, C" << std::endl;
}

int	main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	Base	*base;

	for (int i = 0; i < 3; i++)
	{
		base = generate();
		identify_from_pointer(base);
		identify_from_reference(*base);
		delete base;
	}
}
