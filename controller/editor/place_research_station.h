#ifndef PANDEMIC_PLACE_RESEARCH_STATION_H
#define PANDEMIC_PLACE_RESEARCH_STATION_H
#include "../controller.h"

struct place_research_station : controller {
	
	virtual auto name() const->std::string override;
	virtual auto description() const->std::string override;
	virtual auto run(context &ctx, args_t const &args, ostream_t &out) const -> void override;
};
#endif // !PANDEMIC_PLACE_RESEARCH_STATION_H
