#ifndef PANDEMIC_MAP_VIEW_H
#define PANDEMIC_MAP_VIEW_H

#include <iostream>
#include <iomanip>
#include "observer.h"
#include "../context.h"

class map_view : public observer {
	context &ctx;

public:
	inline explicit map_view(context &ctx) : ctx{ctx} {
		ctx.cities.attach(this);
	}

	inline virtual ~map_view() override {
		ctx.cities.detach(this);
	}

	virtual inline auto update() -> void override {
		auto &out = std::cout;
		static constexpr auto col1 = 14;
		static constexpr auto col2 = 8;
		static constexpr auto col5 = 10;
		static constexpr auto fill = ' ';
		out << std::left << std::setw(col1) << std::setfill(fill) << "CITY";
		out << std::left << std::setw(col2) << std::setfill(fill) << "REGION";
		out << std::left << std::setw(col5) << std::setfill(fill) << "CONNECTIONS";
		out << std::endl;
		for (auto city : ctx.cities) {
			auto name = city.first;
			auto color = ctx.cities.get_color(name);
			out << std::left << std::setw(col1) << std::setfill(fill) << name;
			out << std::left << std::setw(col2) << std::setfill(fill) << color;
			for (auto connection = ctx.cities.begin(name); connection != ctx.cities.end(name); connection++) {
				out << *connection << " ";
			}
			out << std::endl;
		}
	}
};

#endif //PANDEMIC_MAP_VIEW_H
