#pragma once
#include "ASpell.hpp"
#include <map>

class SpellBook
{
	private:
		std::map<std::string, ASpell *> _SpellBook;
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *);
		void forgetSpell(const std::string &);
		ASpell *createSpell(const std::string &);
};
