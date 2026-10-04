#include "animalTypes.h"
#include <stdexcept>

namespace uniqueData {
	
	const AnimalType stringToAnimalType(std::string& type) {

		if (type == "Cow") {
			return AnimalType::Cow;
		}
		else if (type == "Pig") {
			return AnimalType::Pig;
		}
		else if (type == "Chicken") {
			return AnimalType::Chicken;
		}
		else if (type == "Sheep") {
			return AnimalType::Sheep;
		}
		else if (type == "Goat") {
			return AnimalType::Goat;
		}
		else {
			throw std::invalid_argument("Invalid animal type");
		}
	};

	const std::string animalTypeToString(AnimalType type) {
		switch (type) {

		case AnimalType::Cow:
			return "Cow";

		case AnimalType::Pig:
			return "Pig";

		case AnimalType::Chicken:
			return "Chicken";

		case AnimalType::Sheep:
			return "Sheep";

		case AnimalType::Goat:
			return "Goat";

		default:
			return "Unknown";
		}
	};
};