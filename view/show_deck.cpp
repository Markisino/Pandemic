#include <iomanip>
#include "show_deck.h"

auto show_deck::name() const -> std::string {
	return "show-deck";
}

auto show_deck::description() const -> std::string {
	return "Show deck information";
}

auto show_deck::run(context &ctx, args_type const &args, ostream_type &out) const -> void {
	if (args.empty()) {
		static constexpr auto col1 = 18;
		static constexpr auto col2 = 8;
		static constexpr auto fill = ' ';
		out << std::left << std::setw(col1) << std::setfill(fill) << "DECK";
		out << std::left << std::setw(col2) << std::setfill(fill) << "SIZE";
		out << std::endl;
		for (auto const &deck : ctx.decks) {
			auto name = deck.first;
			auto card_count = ctx.decks.size(name);
			out << std::left << std::setw(col1) << std::setfill(fill) << name;
			out << std::left << std::setw(col2) << std::setfill(fill) << card_count;
			out << std::endl;
		}
		return;
	}
	auto const &deck = args.at(0);
	try {
		if (ctx.decks.size(deck) == 0) {
			out << name() << ": '" << deck << "' is empty" << std::endl;
			return;
		}
		for (auto i = ctx.decks.begin(deck); i != ctx.decks.end(deck); i++) {
			out << *i << " ";
		}
		out << std::endl;
	} catch (std::out_of_range const &) {
		out << name() << ": '" << deck << "' does not exist" << std::endl;
	}
}