#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructed" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructed" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain copy assigned constructed" << std::endl;
    for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destroyed" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    return (index >= 0 && index < 100) ? ideas[index] : "";
}

