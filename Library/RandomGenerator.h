#pragma once
#include "Generator.h"

namespace algebra {

class RandomGenerator : public Generator
{
private:
    int min_val;
    int max_val;
public:
    RandomGenerator(int min, int max);
    int generate() override;
};

}