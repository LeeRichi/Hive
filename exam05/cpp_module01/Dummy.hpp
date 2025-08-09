#include "ATarget.hpp"

#pragma once

class Dummy : public ATarget
{
	public:
		Dummy();
		~Dummy();

		ATarget *clone() const;
};
