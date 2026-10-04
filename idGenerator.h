#pragma once
#include <string>
#include <stdexcept>
#include "animalTypes.h"

namespace uniqueData {

    class idGenerator {

    public:

        static std::string generateUniqueId(AnimalType type);

        static int addAnimal(AnimalType type);

        static std::string generateUniquePenId();

		static int addPen();

        static int getAnimalsCount(AnimalType type);

        static int getPenCount();

    private:

        static int cowCounter;
        static int pigCounter;
        static int chickenCounter;
        static int sheepCounter;
        static int goatCounter;

		static int PenCounter;
    };
}