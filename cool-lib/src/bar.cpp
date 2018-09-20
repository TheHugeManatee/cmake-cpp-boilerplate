
#include "coolLib/bar.h"
#include "coolHeader/niftystuff.h"

#include <iostream>

namespace cool_lib {

int foo(bool branch)
{
    if(branch)
    {
        std::cout << "This line will be untested, so that coverage is not 100%\n";
    }
    else
    {
        std::cout << "This is the default behaviour and will be tested\n";
    }
    return 0;
}

}