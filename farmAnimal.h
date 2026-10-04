#pragma once

#include "helthStatus.h"
#include "animalTypes.h"

#include <string>

namespace animalsData {

	class FarmAnimal {

	protected:

		std::string _id;
		double _weight;
		unsigned int _ageInMonths;
		HealthStatus _healthStatus;

	public:

		FarmAnimal(const std::string& id, double weight, unsigned int ageInMonths, HealthStatus healthStatus);

		virtual ~FarmAnimal() = default;

		std::string getId() const;

		double getWeight() const;

		unsigned int getAgeInMonths() const;

		HealthStatus getHealthStatus() const;

		void setHealthStatus(int healthStatus);

		virtual void setWeight(double weight);

		virtual void setAgeInMonths(unsigned int ageInMonths);

		virtual uniqueData::AnimalType getType() = 0;

		std::string weightToString() const;

		std::string ageToString() const;

		std::string healthStatusToString() const;
	};
}