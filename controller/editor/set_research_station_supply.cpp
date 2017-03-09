#include "set_research_station_supply.h"

auto set_research_station_supply::name() const->std::string {
	return "set-research-station-supply";
}

auto set_research_station_supply::description() const->std::string {
	return "Set the Research Station Supply";
}

auto set_research_station_supply::run(context &ctx,const args_t &args, ostream_t &out) const -> void {
	try {
		auto name = args.at(0);
		ctx.game.research_station_supply_count();
	}
	catch (std::out_of_range const &) {
		out << "usage: " << name() << "<count>" << std::endl;
	}
}