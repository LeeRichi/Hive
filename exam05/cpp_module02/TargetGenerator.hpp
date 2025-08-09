#pragma once
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		std::map<std::string, ATarget *> _TargetBook;
	public:
		TargetGenerator();
		~TargetGenerator();
		
		void learnTargetType(ATarget *);
		void forgetTargetType(const std::string &);
		ATarget *createTarget(const std::string &);
};
