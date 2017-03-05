#ifndef PANDEMIC_SHUFFLE_DECK_H
#define PANDEMIC_SHUFFLE_DECK_H
#include "../controller.h"

struct shuffle_deck : controller {
	
	virtual auto name() const->std::string override;

	virtual auto description() const->std::string override;

	virtual auto run(context &ctx, args_t const &args, ostream_t &out) const -> void override;
};

#endif // PANDEMIC_SHUFFLE_DECK_H
