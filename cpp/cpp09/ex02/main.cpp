#include "MutantStack.hpp"
#include <iostream>
#include <exception>

void push_many_randoms(MutantStack<int>& mstack, int rounds)
{
    for (int i = 0; i < rounds; i++)
    {
        if (i == 3)
        {
            mstack.push(000);
        }
        mstack.push(rand() / 10000);
    }
}

int main()
{
MutantStack<int> mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// //[...]
// mstack.push(1);

push_many_randoms(mstack, 10);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
return 0;
}

// #include "MutantStack.hpp"
// #include <iostream>

// int main()
// {
//     MutantStack<int> mstack;

//     if (mstack.empty()) {
//         std::cout << "Stack is empty, cannot access top value.\n";
//     } else {
//         try {
//             int topValue = mstack.top();
//             std::cout << "Top value: " << topValue << std::endl;
//         }
//         catch (const std::out_of_range& e) {
//             std::cout << "Caught exception: " << e.what() << std::endl;
//         }
//     }

//     for (int i = 1; i <= 5; ++i)
//         mstack.push(i * 10); // 10, 20, 30, 40, 50

//     std::cout << "\n== Regular iterator ==\n";
//     for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
//         std::cout << *it << ' ';

//     std::cout << "\n== Const iterator ==\n";
//     const MutantStack<int>& const_mstack = mstack;
//     for (MutantStack<int>::const_iterator cit = const_mstack.begin(); cit != const_mstack.end(); ++cit)
//         std::cout << *cit << ' ';

//     std::cout << "\n== Reverse iterator ==\n";
//     for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
//         std::cout << *rit << ' ';

//     std::cout << "\n== Const reverse iterator ==\n";
//     for (MutantStack<int>::const_reverse_iterator crit = const_mstack.rbegin(); crit != const_mstack.rend(); ++crit)
//         std::cout << *crit << ' ';

//     //try to mutate the const iter
//     // for (MutantStack<int>::iterator it = const_mstack.begin(); it != const_mstack.end(); ++it)
//     //     *it += 1; // Mutate the const contents //should not work

//     std::cout << "\n\n== Mutation via iterator (adds 1) ==\n";
//     for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
//         *it += 1; // Mutate the contents

//     for (MutantStack<int>::const_iterator cit = const_mstack.begin(); cit != const_mstack.end(); ++cit)
//         std::cout << *cit << ' '; // Should reflect updated values

//     std::cout << '\n';

//     return 0;
// }
