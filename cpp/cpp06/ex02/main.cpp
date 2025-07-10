#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//random generator
Base * generate(void)
{
		int random = rand() % 3;
		if (random == 0)
				return new A();
		else if (random == 1)
				return new B();
		else
				return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer type: C" << std::endl;
	else
		std::cout << "Unknown pointer type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a; // To avoid unused variable warning
		std::cout << "Reference type: A" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception (" << e.what() << ") while trying to dynamically cast to A\n";
	}

	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Reference type: B" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception (" << e.what() << ") while trying to dynamically cast to B\n";
	}

	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Reference type: C" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception (" << e.what() << ") while trying to dynamically cast to C\n";
	}

	std::cout << "Unknown reference type" << std::endl;
}

int main()
{
	Base *instance;
	srand(time(0));
	try
	{
		instance = generate();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Mem allocation failed.\n";
	};

	identify(instance);

	Base &ref = *instance;

	// Identify the type of the instance using references
	identify(ref);

	if (instance)
		delete instance;
	return 0;
}
