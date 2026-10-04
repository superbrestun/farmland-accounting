#pragma once
#include "farm.h"
#include "liveStockPen.h"
#include "animalTypes.h"

#include <string>
#include <vector>
#include <memory>

using namespace animalsData;

namespace controllers {

	class FarmController {

		Farm _farm;
	public:

        void addPen(uniqueData::AnimalType type, unsigned int maxSize);

        void addAnimalToPen(const std::string& penId, std::unique_ptr<FarmAnimal> animal);

        void removeAnimal(const std::string& animalId);

        void deletePen(const std::string& penId);

        void showFarmStatus() const;

        std::vector<FarmAnimal*> filterSickAnimals() const;

        void sortByAge(const std::string& penId);

        double calculateAverageWeight(const std::string& penId) ;

        std::vector<LiveStockPen*> findPenUnderCriticalLimit() const;

		std::string getPensId() const;
	};
};