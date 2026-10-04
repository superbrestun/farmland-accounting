#include "farmController.h"

#include "farm.h"
#include "liveStockPen.h"
#include "animalTypes.h"
#include "farmAnimal.h"

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <iostream>

namespace controllers {
	
    void FarmController::addPen(uniqueData::AnimalType type, unsigned int maxSize) {
        
        auto pen = std::make_unique<LiveStockPen>(type, maxSize);

        _farm.addPen(std::move(pen));
    };

    void FarmController::addAnimalToPen(const std::string& penId, std::unique_ptr<FarmAnimal> animal) {
        
         LiveStockPen* pen = _farm.findPenById(penId);

        if (pen) {

            pen->addAnimal(std::move(animal));
        } 
        else {

            throw std::runtime_error("Pen not found.");
        }
    };

    void FarmController::removeAnimal(const std::string& animalId) {

        for (const auto& pen : _farm.getPens()) {

            if (pen->findAnimalById(animalId)) {

                pen->removeAnimal(animalId);

                return;
            }
        }

        throw std::runtime_error("Animal not found.");
    };

    void FarmController::deletePen(const std::string& penId) {
        
         _farm.removePen(penId);
    };

    void FarmController::showFarmStatus() const {
        
         for (const auto& pen : _farm.getPens()) {
            std::cout 
                << "Pen ID: " << pen->getId() 
                << ", Type: " << static_cast<int>(pen->getAnimalType())
                << ", Animals: " << pen->getAnimalCount() 
                << "/" << pen->getMaxSize() << std::endl;

            for (const auto& animal : pen->getAnimals()) {
                std::cout 
                    << "  - Animal ID: " 
                    << animal->getId() 
                    << ", Weight: " << animal->weightToString()
                    << ", Age: " << animal->ageToString() 
                    << ", Health: " << animal->healthStatusToString() << std::endl;
            }
        }
    };

    std::vector<FarmAnimal*> FarmController::filterSickAnimals() const {
        
         std::vector<FarmAnimal*> sickAnimals;

        for (const auto& pen : _farm.getPens()) {

            for (const auto& animal : pen->getAnimals()) {

                if (animal->getHealthStatus() != HealthStatus::Excellent) {

                    sickAnimals.push_back(animal.get());
                }
            }
        }
        return sickAnimals;
    };

    void FarmController::sortByAge(const std::string& penId) {
     
        for (const auto& pen : _farm.getPens()) {

            if (pen->getId() == penId) {

                pen->sortByAge();
                break;
            };
        };
    };

    double FarmController::calculateAverageWeight(const std::string& penId) {
        
         LiveStockPen* pen = _farm.findPenById(penId);

        if (!pen) {

            throw std::runtime_error("Pen not found.");
        }

        const auto& animals = pen->getAnimals();

        if (animals.empty()) {

            return 0;
        }

        double totalWeight = 0;

        for (const auto& animal : animals) {

            totalWeight += animal->getWeight();
        }

        return totalWeight / animals.size();
    };

    std::vector<LiveStockPen*> FarmController::findPenUnderCriticalLimit() const {
        
         std::vector<LiveStockPen*> criticalPens;
        for (const auto& pen : _farm.getPens()) {
            if (pen->getAnimalCount() < pen->getMaxSize() * 0.2) {
                criticalPens.push_back(pen.get());
            }
        }
        return criticalPens;
    };

    std::string FarmController::getPensId() const {
        std::string ids;
        for (const auto& pen : _farm.getPens()) {
            ids += pen->getId() + ", ";
        }
        return ids;
    }
};