#ifndef PANDEMIC_CITIES_MODEL_H
#define PANDEMIC_CITIES_MODEL_H

#include "../handle.h"
#include "../observer/subject.h"
#include <set>
#include <map>

// map represents a PANDEMIC map.
class cities_model : public subject {
	using connected_cities_type = std::set<handle>;

	struct city {
		handle color;
		handle name;
		connected_cities_type connected_cities;
		bool has_research_station;
		std::map<handle, int> cube_count;
	};

	using cities_type = std::map<handle, city>;

	cities_type cities;

public:
	// TODO remove internal iterator leak
	using cities_const_iterator = cities_type::const_iterator;
	using connected_cities_const_iterator = connected_cities_type::const_iterator;

	inline auto add_city(handle color, handle name) -> void {
		cities.emplace(name, city{color, name, {}, false, {
				{"black"_h, 0},
				{"yellow"_h, 0},
				{"blue"_h, 0},
				{"red"_h, 0},
		}});
		notify();
	}

	inline auto connect_city(handle name, handle connection) -> void {
		cities.at(name).connected_cities.insert(connection);
		notify();
	}

	inline auto get_color(handle name) const -> handle {
		return cities.at(name).color;
	}

	inline auto has_research_station(handle name) const -> bool {
		return cities.at(name).has_research_station;
	}

	inline auto place_research_station(handle name) -> void {
		cities.at(name).has_research_station = true;
		notify();
	}

	inline auto remove_research_station(handle name) -> void {
		cities.at(name).has_research_station = false;
		notify();
	}

	inline auto get_cube_count(handle name, handle color) const -> int {
		return cities.at(name).cube_count.at(color);
	}

	inline auto add_cube(handle name, handle color, int count = 1) -> void {
		cities.at(name).cube_count.at(color) += count;
		notify();
	}

	inline auto remove_cube(handle name, handle color, int count = 1) -> void {
		cities.at(name).cube_count.at(color) -= count;
		notify();
	}

	inline auto begin() const -> cities_const_iterator {
		return cities.begin();
	}

	inline auto end() const -> cities_const_iterator {
		return cities.end();
	}

	inline auto begin(handle city) const -> connected_cities_const_iterator {
		return cities.at(city).connected_cities.begin();
	}

	inline auto end(handle city) const -> connected_cities_const_iterator {
		return cities.at(city).connected_cities.end();
	}
};

#endif //PANDEMIC_CITIES_MODEL_H
