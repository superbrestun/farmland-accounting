#pragma once
#include <string>
#include "farmAnimal.h"
#include "helthStatus.h"
#include "animalTypes.h"

namespace animalsData {

	class Cow : public FarmAnimal {

	public:

		Cow(double weight, unsigned int ageInMonths, HealthStatus healthStatus);

		void setWeight(double weight) override;

		void setAgeInMonths(unsigned int ageInMonths) override;

		uniqueData::AnimalType getType() override;

	private:

		static double validateSetWeight(double weight);

		static int validateSetAgeInMonths(unsigned int ageInMonths);
	};
};