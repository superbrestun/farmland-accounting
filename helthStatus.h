#pragma once
#include <string>

namespace animalsData {

	enum class HealthStatus {

		Excellent,
		Good,
		Fair,
		Poor
	};

	const HealthStatus getHealthStatus(int statusValue);

	const std::string healthStatusToString(HealthStatus status);
}