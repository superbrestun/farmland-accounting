#pragma once
#include <string>
#include <vector>
#include <memory>

#include "farmAnimal.h"
#include "liveStockPen.h"

namespace animalsData {
	
	class Farm {
		
		std::vector<std::unique_ptr<LiveStockPen>> _pens;

	public:

		void addPen(std::unique_ptr<LiveStockPen> pen);

		void removePen(const std::string& id);

		LiveStockPen* findPenById(const std::string& id);

		const std::vector<std::unique_ptr<LiveStockPen>>& getPens() const;
	};
};