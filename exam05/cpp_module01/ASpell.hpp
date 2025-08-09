#pragma once
#include <iostream>
#include "ATarget.hpp"

class ASpell
{
	private:
		std::string _name;
		std::string _effects;

	public:
		ASpell(const std::string name, const std::string effects);
		virtual ~ASpell();

		const std::string &getName() const;
		const std::string &getEffects() const;

		virtual ASpell *clone() const = 0;

		void launch(const ATarget &src) const;
};
