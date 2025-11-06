#include "IStreamGenerator.h"

namespace algebra {

int IStreamGenerator::generate()
{
    int value;
    std::cin >> value;
    return value;
}

}