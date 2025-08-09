#pragma once
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"

#include <map>

class ASpell;
class ATarget;

class Warlock {
	private:
		std::string _name;
		std::string _title;

		std::map<std::string, ASpell *> _SpellBook;

	public:
		Warlock(const std::string name, const std::string title);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(const std::string &title);
		void introduce() const;

		void learnSpell(ASpell *);
		void forgetSpell(std::string name);
		void launchSpell(std::string name,  const ATarget &);
};
