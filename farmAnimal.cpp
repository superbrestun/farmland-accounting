#include "farmAnimal.h"
#include "helthStatus.h"
#include "constants.h"
#include <stdexcept>
#include <string>

namespace animalsData {
	
	FarmAnimal::FarmAnimal(const std::string& id,
		double weight,
		unsigned int ageInMonths,
		HealthStatus healthStatus) {
		
		_id = id;
		_weight = weight;
		_ageInMonths = ageInMonths;
		_healthStatus = healthStatus;
	};

	std::string FarmAnimal::getId() const {
		return _id;
	};

	double FarmAnimal::getWeight() const {
		return _weight;
	};

	unsigned int FarmAnimal::getAgeInMonths() const {
		return _ageInMonths;
	};

	HealthStatus FarmAnimal::getHealthStatus() const {
		return _healthStatus;
	};

	void FarmAnimal::setHealthStatus(int healthStatus) {
		
		if (healthStatus < 0 || healthStatus > utils::MAX_HELTH_STATUS_COUNT - 1) {
			throw std::out_of_range("Invalid health status value. Must be between 0 and 3.");
		}

		_healthStatus = animalsData::getHealthStatus(healthStatus);
	};

	void FarmAnimal::setWeight(double weight) {
		
		_weight = weight;
	};

	void FarmAnimal::setAgeInMonths(unsigned int ageInMonths) {
		
		_ageInMonths = ageInMonths;
	};

	std::string FarmAnimal::weightToString() const {
		
		return std::to_string(_weight) + " kg";
	};

	std::string FarmAnimal::ageToString() const {
		
		return std::to_string(_ageInMonths) + " months";
	};

	std::string FarmAnimal::healthStatusToString() const {
		
		 return animalsData::healthStatusToString(_healthStatus);
	};
};