#include <random>
#include <algorithm>
#include "shuffle_deck.h"

// Implement the Controller function
auto shuffle_deck::name() const -> std::string {
	return "shuffle-deck";
}

auto shuffle_deck::description() const -> std::string {
	return "shuffle the deck";
}

auto shuffle_deck::run(context &ctx, args_t const &args, ostream_t &out) const -> void {
	try {
		auto name = args.at(0);
		ctx.decks.shuffle(name);
	}
	catch (std::out_of_range const &){
		out << "usage: " << name() << " <deck>" << std::endl;
	}

}