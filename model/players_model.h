#ifndef PANDEMIC_PLAYERS_MODEL_H
#define PANDEMIC_PLAYERS_MODEL_H

#include "../handle.h"
#include <unordered_map>

class players_model {
	struct player {
		handle color;
		handle role;
		handle city;
	};

	using players_t = std::unordered_map<handle, player>;

	players_t players;
	handle current_turn;
	int actions_remaining;

public:
	// TODO remove internal iterator leak
	using const_iterator = players_t::const_iterator;

	static const int actions_per_turn = 4;

	inline auto begin() const -> const_iterator {
		return players.begin();
	}

	inline auto end() const -> const_iterator {
		return players.end();
	}

	inline auto add_player(handle color) -> void {
		players.emplace(color, player{color});
	}

	inline auto get_role(handle player) const -> handle {
		return players.at(player).role;
	}

	inline auto set_role(handle player, handle role) -> void {
		players.at(player).role = role;
	}

	inline auto get_city(handle player) const -> handle {
		return players.at(player).city;
	}

	inline auto set_city(handle player, handle city) -> void {
		players.at(player).city = city;
	}

	inline auto get_actions_remaining() const -> int {
		return actions_remaining;
	}

	inline auto decrement_actions_remaining() -> void {
		actions_remaining--;
	}

	inline auto get_current_turn() const -> handle {
		return current_turn;
	}

	inline auto start_turn(handle player) -> void {
		current_turn = player;
		actions_remaining = actions_per_turn;
	}
};

#endif //PANDEMIC_PLAYERS_MODEL_H
