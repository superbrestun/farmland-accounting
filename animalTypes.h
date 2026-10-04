#pragma once
#include <string>

namespace uniqueData {

	enum class AnimalType {
		Cow,
		Pig,
		Chicken,
		Sheep,
		Goat
	};

	const AnimalType stringToAnimalType(std::string& type);

	const std::string animalTypeToString(AnimalType type);
}