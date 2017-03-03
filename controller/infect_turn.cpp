#include "infect_turn.h"

auto infect_turn::name() const -> std::string {
    return "infect-turn";
}

auto infect_turn::description() const -> std::string {
    return "Infects cities";
}

auto infect_turn::run(context &ctx, args_t const &args, ostream_t &out) const -> void {
    try {
        auto const &infection_deck = args.at(0);
        auto const &discard_deck = args.at(1);
        auto const infection_rate = ctx.game.get_infection_rate();
        for (int i = 0; i < infection_rate; i++) {
            auto const &city = ctx.decks.remove_from_top(infection_deck);
            auto const &color = ctx.cities.get_color(city);
            if (ctx.game.discovered_cure(color)) {
                break;
            }
            ctx.cities.add_cube(city, color, 1);
        }
	} catch (std::out_of_range const &) {
        out << "usage: " << name() << " <infection_deck> <discard_deck>" << std::endl;
    }
}