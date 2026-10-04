#include <iostream>
#include <vector>
#include "farmAnimal.h"
#include "cow.h"
#include "helthStatus.h"
#include "liveStockPen.h"
#include "farmController.h"
#include "farm.h"
#include "animalTypes.h"
#include <memory>

using namespace animalsData;
using namespace controllers;
using namespace std;

int main() {

	FarmController controller;

	Cow cow(5, 0, HealthStatus::Excellent);
	Cow cow2(690, 27, HealthStatus::Excellent);
	Cow cow3(300, 12, HealthStatus::Good);
	Cow cow4(50, 6, HealthStatus::Excellent);
	Cow cow5(800, 31, HealthStatus::Poor);
	Cow cow6(740, 0, HealthStatus::Good);
	Cow cow7(15, 1, HealthStatus::Fair);

	controller.addPen(uniqueData::AnimalType::Cow, 6);
	controller.addPen(uniqueData::AnimalType::Cow, 6);

	std::cout << "Pens ID: " << controller.getPensId() << std::endl;

	
	controller.addAnimalToPen("Pen_1", std::make_unique<Cow>(cow));
	controller.addAnimalToPen("Pen_1", std::make_unique<Cow>(cow2));
	controller.addAnimalToPen("Pen_1", std::make_unique<Cow>(cow3));
	controller.addAnimalToPen("Pen_1", std::make_unique<Cow>(cow4));
	controller.addAnimalToPen("Pen_1", std::make_unique<Cow>(cow5));
	controller.addAnimalToPen("Pen_1", std::make_unique<Cow>(cow6));

	controller.addAnimalToPen("Pen_2", std::make_unique<Cow>(cow7));
	

	controller.showFarmStatus();
};