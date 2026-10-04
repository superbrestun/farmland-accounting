#include "liveStockPen.h"
#include "idGenerator.h"
#include "farmAnimal.h"

#include <stdexcept>
#include <algorithm>
#include <vector>
#include <memory>
#include <string>

namespace animalsData {
	
	LiveStockPen::LiveStockPen(uniqueData::AnimalType type, unsigned int maxSize) {
		
		if (maxSize == 0) {
			throw std::invalid_argument("Max size must be greater than 0.");
		}
		_maxSize = maxSize;
		_animalType = type;
		_id = uniqueData::idGenerator::generateUniquePenId();
		
	};

	void LiveStockPen::addAnimal(std::unique_ptr<FarmAnimal> animal) {
		
		if (isFull()) {
			throw std::runtime_error("Pen is full. Cannot add more animals.");
		}

		if (animal->getType() != _animalType) {

			throw std::invalid_argument("Wrong animal type for this pen");
		}

		_animals.push_back(std::move(animal));
	};

	void LiveStockPen::removeAnimal(const std::string& id) {
		
		auto it = std::find_if(_animals.begin(), _animals.end(),
			[&id](const std::unique_ptr<FarmAnimal>& animal) {
				return animal->getId() == id;
			});

		if (it != _animals.end()) {
			_animals.erase(it);
		}
	};

	unsigned int LiveStockPen::getAnimalCount() const {
		return _animals.size();
	}

	uniqueData::AnimalType LiveStockPen::getAnimalType() const {

		return _animalType;
	}

	unsigned int LiveStockPen::getMaxSize() const {
		return _maxSize;
	}

	const std::vector<std::unique_ptr<FarmAnimal>>& LiveStockPen::getAnimals() const {
		return _animals;
	}

	std::string LiveStockPen::getId() const {

		return _id;
	}

	bool LiveStockPen::isFull() const {

		return _animals.size() >= _maxSize;
	}

	FarmAnimal* LiveStockPen::findAnimalById(const std::string& id) const{
		
		for (const auto& animal : _animals) {

			if (animal->getId() == id) {

				return animal.get();
			}
		}
		return nullptr;
	};

	void LiveStockPen::sortByAge() {

		if (_animals.empty()) {
			return;
		}

		std::sort(_animals.begin(), _animals.end(),
			[](const std::unique_ptr<FarmAnimal>& a, const std::unique_ptr<FarmAnimal>& b) {
				return a->getAgeInMonths() < b->getAgeInMonths();
			});
	};

};
