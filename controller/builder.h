#ifndef PANDEMIC_BUILDER_H
#define PANDEMIC_BUILDER_H

#include "../command.h"
#include <set>

static context save_file;

using save_builder = context;

struct save_director {
	inline auto set_builder(save_builder * builder) -> void {
		this->builder = builder;
	}

	inline auto construct_save(context const &ctx) -> void {
		static const std::set<handle> cube_colors{"black"_h, "yellow"_h, "blue"_h, "red"_h};
		// (1) Save map state
		auto const &cities = ctx.cities;
		for (auto const &city : cities) {
			auto const &name = city.first;
			auto const &color = cities.get_color(name);
			builder->cities.add_city(color, name);
			for (auto i = cities.begin(name); i != cities.end(name); i++) {
				builder->cities.connect_city(name, *i);
			}
			if (cities.has_research_station(name)) {
				builder->cities.place_research_station(name);
			}
			for (auto const &cube_color : cube_colors) {
				auto count = cities.get_cube_count(name, cube_color);
				builder->cities.add_cube(name, cube_color);
			}
		}
		// (2) Save player state
		auto const &players = ctx.players;
		for (auto const &p : players) {
			auto const &player = p.first;
			builder->players.add_player(player);
			auto const &role = players.get_role(player);
			builder->players.set_role(player, role);
			auto const &city = players.get_city(player);
			builder->players.set_city(player, city);
			// (3) Save current turn
			auto const &current_turn = players.get_current_turn();
			builder->players.start_turn(current_turn);
			auto const &actions_remaining = players.get_actions_remaining();
			auto decrement = players.actions_per_turn - actions_remaining;
			for (auto i = 0; i < decrement; i++) {
				builder->players.decrement_actions_remaining();
			}
		}
		auto const &decks = ctx.decks;
		for (auto const &p : decks) {
			auto const &deck = p.first;
			builder->decks.create(deck);
			for (auto i = decks.begin(deck); i != decks.end(deck); i++) {
				builder->decks.add_to_top(deck, *i);
			}
		}
		// (3) Save game state
		auto const &game = ctx.game;
		for (auto const &cube_color : cube_colors) {
			auto count = game.cube_supply_count(cube_color);
			builder->game.add_cube_to_supply(cube_color, count);
			if (game.discovered_cure(cube_color)) {
				builder->game.discover_cure(cube_color);
			}
		}
		auto research_station_count = game.research_station_supply_count();
		builder->game.set_research_station_supply(research_station_count);
	}

	inline auto get_save() const -> context {
		return *builder;
	}

private:
	save_builder * builder;
};

struct save_command : command {
	virtual inline auto name() const -> std::string override {
		return "save-director";
	}

	virtual inline auto description() const -> std::string override {
		return "Save the game using builder pattern";
	}

	virtual inline auto run(context &ctx, args_type const &args, ostream_type &out) const -> void override {
		save_director director{};
		save_builder builder{};
		director.set_builder(&builder);
		director.construct_save(ctx);
		save_file = director.get_save();
	}
};

struct load_command : command {
	virtual inline auto name() const -> std::string override {
		return "load-director";
	}

	virtual inline auto description() const -> std::string override {
		return "Load the game using builder pattern";
	}

	virtual inline auto run(context &ctx, args_type const &args, ostream_type &out) const -> void override {
		save_director director{};
		director.set_builder(&ctx);
		director.construct_save(save_file);
		director.get_save();
	}
};
#endif //PANDEMIC_BUILDER_H
