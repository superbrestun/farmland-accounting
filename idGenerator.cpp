#include "idGenerator.h"

namespace uniqueData {

    std::string idGenerator::generateUniqueId(AnimalType type) {

        return animalTypeToString(type) + "_" + std::to_string(addAnimal(type));
    };

    int idGenerator::addAnimal(AnimalType type) {

        switch (type) {
        case AnimalType::Cow:
            return ++cowCounter;

        case AnimalType::Pig:
            return ++pigCounter;

        case AnimalType::Chicken:
            return ++chickenCounter;

        case AnimalType::Sheep:
            return ++sheepCounter;

        case AnimalType::Goat:
            return ++goatCounter;

        default:
            throw std::invalid_argument("Invalid animal type");
        }
    }

    std::string idGenerator::generateUniquePenId() {
        return "Pen_" + std::to_string(addPen());
    }

    int idGenerator::addPen() {
        return ++PenCounter;
    }

    int idGenerator::getAnimalsCount(AnimalType type) {
        switch (type) {
        case AnimalType::Cow:
            return cowCounter;
        case AnimalType::Pig:
            return pigCounter;
        case AnimalType::Chicken:
            return chickenCounter;
        case AnimalType::Sheep:
            return sheepCounter;
        case AnimalType::Goat:
            return goatCounter;
        default:
            throw std::invalid_argument("Invalid animal type");
        }
    }

    int idGenerator::getPenCount() {
        return PenCounter;
    }

    int idGenerator::cowCounter = 0;
    int idGenerator::pigCounter = 0;
    int idGenerator::chickenCounter = 0;
    int idGenerator::sheepCounter = 0;
    int idGenerator::goatCounter = 0;

    int idGenerator::PenCounter = 0;
}