#ifndef GENERATORLOSOWY_H
#define GENERATORLOSOWY_H

#include <random>

class GeneratorLosowy
{
    private:
        static std::random_device device;
        GeneratorLosowy(){}

    public:

        static unsigned short losujPomiedzy(unsigned short min, unsigned short max);
        static long losujPomiedzy(long min, long max);
        static int losujOdZeraDo(int max);

};

#endif // GENERATORLOSOWY_H
