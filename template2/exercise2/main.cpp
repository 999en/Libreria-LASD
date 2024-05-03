
#include "zmytest/test.hpp"

#include "zlasdtest/test.hpp"

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

using namespace std;

int main() {

    std::cout << "Lasd Libraries 2023" << std::endl;
    uint scelta;
    while(true)
    {
        std::cout<<"\n\n\nQuale test vuoi eseguire? Digita:\n"
                   "0. esci\n"
                   "1. lasdtest\n"
                   "2. myTest\n";
        std::cin>>scelta;
        if(scelta == 0)
            exit(1);
        else if(scelta == 1)
            lasdtest();
        else if(scelta == 2)
            myTest();
    }
    return 0;

}