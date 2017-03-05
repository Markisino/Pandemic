#include "application.h"
#include "controller/reference_card.h"
#include "controller/setup.h"
#include "controller/begin_play.h"
#include "controller/view/status.h"
#include "controller/view/cities.h"
#include "controller/place_pawn.h"
#include "controller/editor/add_city.h"
#include "controller/view/show_deck.h"
#include "controller/view/players.h"
#include "controller/end_turn.h"
#include "controller/editor/add_player.h"
#include "controller/editor/create_deck.h"
#include "controller/editor/shuffle_deck.h"
#include <iomanip>
#include <sstream>
#include <fstream>
#include <ostream>
#include <streambuf>

application::application(std::istream &in, std::ostream &out) :
		in{in},
		out{out},
		ctx{},
		controllers{},
		command_history{} {
	insert_controller<reference_card>();
	insert_controller<setup>();
	insert_controller<status>();
	insert_controller<cities>();
	insert_controller<place_pawn>();
	insert_controller<add_city>();
    insert_controller<show_deck>();
	insert_controller<players>();
    insert_controller<begin_play>();
    insert_controller<end_turn>();
    insert_controller<add_player>();
    insert_controller<create_deck>();
};

auto application::help() -> void {
	static constexpr auto col1 = 16;
	static constexpr auto fill = ' ';
	for (auto const &i : controllers) {
		out << std::left << std::setw(col1) << std::setfill(fill) << i.second->name();
		out << i.second->description();
		out << std::endl;
	}
}

auto application::invalid_command(std::string const &command) -> void {
	out << "'" << command << "'" << " is not a valid command" << std::endl;
}

auto application::prompt() -> void {
    auto const &player = ctx.players.get_current_turn();
    if (player == ""_h) {
        out << "$ ";
        return;
    }
    out << player << "$ ";
}

auto application::intro() -> void {
	static constexpr auto banner = R"(
                        _                _
  _ __   __ _ _ __   __| | ___ _ __ ___ (_) ___
 | '_ \ / _` | '_ \ / _` |/ _ \ '_ ` _ \| |/ __|
 | |_) | (_| | | | | (_| |  __/ | | | | | | (__
 | .__/ \__,_|_| |_|\__,_|\___|_| |_| |_|_|\___|
 |_|                                            )";
	out << banner << std::endl << std::endl;
}

auto application::run() -> void {
	intro();
	prompt();
	std::string line;
	while (std::getline(in, line)) {
		std::string name;
		auto code = call_controller(line, name, out);
		if (code == return_code::blank_input) {
			prompt();
			continue;
		}
		if (code == return_code::not_found) {
			invalid_command(name);
			prompt();
			continue;
		}
		if (code == return_code::exit) {
			break;
		}
		prompt();
	}
}

auto application::call_controller(std::string const &command, std::string &name, std::ostream &out) -> return_code {
	std::istringstream iss{command};
	if (!(iss >> name)) {
		return return_code::blank_input;
	}
	std::vector<std::string> args;
	std::string arg;
	while (iss >> arg) {
		args.emplace_back(arg);
	}
	if (name == "#") {
		// comment
		return return_code::ok;
	}
	if (name == "exit") {
		return return_code::exit;
	}
	if (name == "help") {
		help();
	} else if (name == "save") {
		if (args.empty()) {
			out << "usage: save <filename>" << std::endl;
			return return_code::ok;
		}
		auto const &filename = args.at(0);
		save(filename);
	} else if (name == "load") {
		std::string filename{"setup"};
		if (!args.empty()) {
			filename = args.at(0);
		}
		load(filename);
	} else {
		try {
			controllers.at(name)->run(ctx, args, out);
			command_history.push_back(command);
		} catch (std::out_of_range const &) {
			return return_code::not_found;
		}
	}
	return return_code::ok;
}

auto application::save(std::string const &filename) -> void {
	auto path = "../script/" + filename + ".pandemic.txt";
	std::ofstream out;
	out.open(path);
	for (auto const &line : command_history) {
		out << line << std::endl;
	}
}

struct null_buffer : std::streambuf {
	inline auto overflow(int c) -> int {
		return c;
	}
};

auto application::load(std::string const &filename) -> void {
	auto path = "../script/" + filename + ".pandemic.txt";
	std::ifstream in{path};
	if (!in.is_open()) {
		out << "could not open file '" << path << "'" << std::endl;
		return;
	}
	null_buffer nb;
	std::ostream null_stream{&nb};
	std::string line;
	while (std::getline(in, line)) {
		std::string name;
		auto code = call_controller(line, name, null_stream);
		if (code == return_code::blank_input) {
			continue;
		}
		if (code == return_code::not_found) {
			invalid_command(name);
			continue;
		}
	}
}
