#pragma once

namespace algebra 
{
    class Generator
    {
    public:
        Generator() {}
        virtual ~Generator() {}
        virtual int generate() = 0;
    };
}