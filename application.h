#ifndef PANDEMIC_APPLICATION_H
#define PANDEMIC_APPLICATION_H

#include <istream>
#include <ostream>
#include <string>
#include <memory>
#include <unordered_map>
#include <vector>
#include "command.h"

// application handles user input and output.
struct application {

	application(std::istream &in, std::ostream &out);

	// run starts the game loop. It returns when the user exits the game.
	auto run() -> void;

private:
	auto help() -> void;

	auto invalid_command(std::string const &command) -> void;

	auto prompt() -> void;

	auto intro() -> void;

	template<class T>
	auto insert_command(std::string const &category) -> void {
		auto com = std::make_unique<T>();
		category_commands.insert({category, com->name()});
		commands.insert(std::make_pair(com->name(), std::move(com)));
	}

	enum class return_code {
		ok, not_found, blank_input, exit
	};

	auto call_command(std::string const &command, std::string &name, std::ostream &out) -> return_code;

	auto command_category(std::string const &command) -> std::string;

	auto save(std::string const &filename) -> void;

	auto load(std::string const &filename) -> void;

	std::istream &in;
	std::ostream &out;
	context ctx;
	std::unordered_map<std::string, std::unique_ptr<command>> commands;
	std::unordered_multimap<std::string, std::string> category_commands;
	std::vector<std::string> command_history;
};

#endif //PANDEMIC_APPLICATION_H
