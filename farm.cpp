#include "farm.h"

#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "farmAnimal.h"
#include "liveStockPen.h"

namespace animalsData {
	
	void Farm::addPen(std::unique_ptr<LiveStockPen> pen) {
		
		_pens.push_back(std::move(pen));
	};

	void Farm::removePen(const std::string& id) {
		
		auto it = std::find_if(_pens.begin(), _pens.end(),
			[&id](const std::unique_ptr<LiveStockPen>& pen) {

				return pen->getId() == id;
			});

		if (it != _pens.end()) {

			_pens.erase(it);
		}
	};

	LiveStockPen* Farm::findPenById(const std::string& id) {

		for (const auto& pen : _pens) {

			if (pen->getId() == id) {

				return pen.get();
			}
		}
		return nullptr;
	};

	const std::vector<std::unique_ptr<LiveStockPen>>& Farm::getPens() const {
		return _pens;
	};
};