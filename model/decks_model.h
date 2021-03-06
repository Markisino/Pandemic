#ifndef PANDEMIC_DECKS_MODEL_H
#define PANDEMIC_DECKS_MODEL_H

#include <map>
#include <deque>
#include <algorithm>
#include <random>
#include "../handle.h"

// decks represents a collection of card decks.

class decks_model {
	using cards_type = std::deque<handle>;

	struct deck {
		cards_type cards;
		bool remove_failed;
	};

	using decks_type = std::map<handle, deck>;

	decks_type decks;
	std::minstd_rand rand;
	bool seeded;

public:
	using const_iterator = decks_type::const_iterator;
	using cards_const_iterator = cards_type::const_iterator;

	inline auto create(handle name) -> void {
		decks.emplace(name, deck{});
	}

	inline auto add_to_top(handle name, handle card) -> void {
		decks.at(name).cards.push_front(card);
	}

	inline auto remove_from_top(handle name) -> handle {
		auto &cards = decks.at(name).cards;
		auto result = cards.front();
		try {
			cards.pop_front();
			return result;
		} catch (std::out_of_range const) {
			decks.at(name).remove_failed = true;
			throw;
		}
	}

	inline auto remove_from_bottom(handle name) -> handle {
		auto &cards = decks.at(name).cards;
		auto result = cards.back();
		cards.pop_back();
		return result;
	}

	inline auto remove(handle name, handle card) -> void {
		auto &cards = decks.at(name).cards;
		cards.erase(std::remove(cards.begin(), cards.end(), card), cards.end());
	}

	inline auto begin() const -> const_iterator {
		return decks.begin();
	}

	inline auto end() const -> const_iterator {
		return decks.end();
	}

	inline auto begin(handle name) const -> cards_const_iterator {
		return decks.at(name).cards.begin();
	}

	inline auto end(handle name) const -> cards_const_iterator {
		return decks.at(name).cards.end();
	}

	inline auto size(handle name) const -> cards_type::size_type {
		return decks.at(name).cards.size();
	}

	inline auto set_seed(std::minstd_rand::result_type s) -> bool {
		if (!seeded) {
			seeded = true;
			rand.seed(s);
			return true;
		}
		return false;
	}

	inline auto shuffle(handle name) -> void {
		auto &cards = decks.at(name).cards;
		std::shuffle(cards.begin(), cards.end(), rand);
	}

	inline auto remove_failed(handle name) -> bool {
		try {
			return decks.at(name).remove_failed;
		} catch (std::out_of_range const &) {
			return false;
		}
	}
};

#endif //PANDEMIC_DECKS_MODEL_H
