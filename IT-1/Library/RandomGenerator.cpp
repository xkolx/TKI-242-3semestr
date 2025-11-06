#include "RandomGenerator.h"
#include <cstdlib>

namespace algebra {

RandomGenerator::RandomGenerator(int min, int max)
    : min_val(min), max_val(max)
{
}

int RandomGenerator::generate()
{
    return min_val + rand() % (max_val - min_val + 1);
}

}