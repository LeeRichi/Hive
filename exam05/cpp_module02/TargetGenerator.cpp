#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

// TargetGenerator::TargetGenerator(const TargetGenerator &cp)
// {
// 	// Copy constructor implementation
// 	// Assuming _TargetBook is a member variable of type std::map<std::string, ATarget *>
// 	_TargetBook = cp._TargetBook;
// }

// TargetGenerator::TargetGenerator &operator=(const TargetGenerator &cp)
// {
// 	if (this != &cp) // Check for self-assignment
// 	{
// 		// Copy assignment operator implementation
// 		_TargetBook = cp._TargetBook;
// 	}
// 	return *this;
// }

TargetGenerator::~TargetGenerator()
{
	_TargetBook.clear();
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target != nullptr)
	{
		std::map<std::string, ATarget *>::iterator it = _TargetBook.find(target->getType());
		if (it == _TargetBook.end())
			_TargetBook[target->getType()] = target->clone();
	}
}

void TargetGenerator::forgetTargetType(const std::string &target)
{
	std::map<std::string, ATarget *>::iterator it = _TargetBook.find(target);
	if (it != _TargetBook.end())
	{
		delete it->second;
		_TargetBook.erase(it);
	}
}

ATarget *TargetGenerator::createTarget(const std::string &target)
{
	std::map<std::string, ATarget *>::iterator it = _TargetBook.find(target);
	if (it != _TargetBook.end())
		return it->second->clone();
	return nullptr;
}

