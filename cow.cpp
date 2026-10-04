#include "cow.h"
#include <string>
#include "helthStatus.h"
#include "constants.h"
#include "idGenerator.h"

namespace animalsData {

	Cow::Cow(double weight, unsigned int ageInMonths, HealthStatus healthStatus) 
		:FarmAnimal(uniqueData::idGenerator::generateUniqueId(uniqueData::AnimalType::Cow),
			validateSetWeight(weight),
			validateSetAgeInMonths(ageInMonths),
			healthStatus)
	{};

	void Cow::setWeight(double weight) {
		
		if (weight < 0 || weight > utils::COW_MAX_WEIGHT_IN_KG) {
			throw std::out_of_range("Invalid weight value. Must be between 0 and 800 kg.");
		}

		FarmAnimal::setWeight(weight);
	};

	void Cow::setAgeInMonths(unsigned int ageInMonths) {
		
		if (ageInMonths < 0 || ageInMonths > utils::COW_MAX_AGE_IN_MONTHS) {
			throw std::out_of_range("Invalid age value. Must be between 0 and 240 months.");
		}

		FarmAnimal::setAgeInMonths(ageInMonths);
	}

	uniqueData::AnimalType Cow::getType() {

		return uniqueData::AnimalType::Cow;
	};

	double Cow::validateSetWeight(double weight) {
		
		if (weight < 0 || weight > utils::COW_MAX_WEIGHT_IN_KG) {
			throw std::out_of_range("Invalid weight value. Must be between 0 and 800 kg.");
		}

		return weight;
	};

	int Cow::validateSetAgeInMonths(unsigned int ageInMonths) {

		if (ageInMonths > utils::COW_MAX_AGE_IN_MONTHS) {
			throw std::out_of_range("Invalid age value. Must be between 0 and 240 months.");
		}

		return ageInMonths;
	};
};