#pragma once

#include <string>
#include <vector>
#include <memory>

#include "farmAnimal.h"
#include "idGenerator.h"
#include "animalTypes.h"

namespace animalsData {

	class LiveStockPen {

		std::string _id;
		std::vector<std::unique_ptr<FarmAnimal>> _animals;
		uniqueData::AnimalType _animalType;
		unsigned int _maxSize;

	public:

		LiveStockPen(uniqueData::AnimalType type, unsigned int maxSize);

		virtual ~LiveStockPen() = default;

		void addAnimal(std::unique_ptr<FarmAnimal> animal);

		void removeAnimal(const std::string& id);

		unsigned int getAnimalCount() const;

		uniqueData::AnimalType getAnimalType() const;

		unsigned int getMaxSize() const;

		const std::vector<std::unique_ptr<FarmAnimal>>& getAnimals() const;

		std::string getId() const;

		bool isFull() const;

		FarmAnimal* findAnimalById(const std::string& id) const;

		void sortByAge();
	};
};