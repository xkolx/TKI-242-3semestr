#pragma once
#include "Generator.h"
#include <iostream>

namespace algebra {

class IStreamGenerator : public Generator
{
public:
    IStreamGenerator() {}
    int generate() override;
};

}