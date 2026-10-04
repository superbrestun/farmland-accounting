#include "helthStatus.h"
#include <stdexcept>

namespace animalsData {
	
	const HealthStatus getHealthStatus(int statusValue) {
		switch (statusValue) {
		case 0:
			return HealthStatus::Excellent;
		case 1:
			return HealthStatus::Good;
		case 2:
			return HealthStatus::Fair;
		case 3:
			return HealthStatus::Poor;
		default:
			throw std::invalid_argument("Invalid health status value");
		}
	}

	const std::string healthStatusToString(HealthStatus status) {
		switch (status) {
		case HealthStatus::Excellent:
			return "Excellent";
		case HealthStatus::Good:
			return "Good";
		case HealthStatus::Fair:
			return "Fair";
		case HealthStatus::Poor:
			return "Poor";
		default:
			return "Unknown";
		}
	}
}