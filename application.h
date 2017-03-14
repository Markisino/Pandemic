#ifndef PANDEMIC_APPLICATION_H
#define PANDEMIC_APPLICATION_H

#include <istream>
#include <ostream>
#include <string>
#include <memory>
#include <unordered_map>
#include <vector>
#include "command.h"
#include "observer/map_view.h"

// application handles user input and output.
struct application {

	// constructs a new application.
	application(std::istream &in, std::ostream &out);

	// run starts the game loop. It returns when the user exits the game.
	auto run() -> void;

private:
	// help prints a list of commands.
	auto help() -> void;

	// invalid_command displays an error to the user.
	auto invalid_command(std::string const &command) -> void;

	// prompt displays the command prompt.
	auto prompt() -> void;

	// intro displays the intro message.
	auto intro() -> void;

	// insert_command inserts a command into the application.
	template<class T>
	auto insert_command(std::string const &category) -> void {
		auto com = std::make_unique<T>();
		category_commands.insert({category, com->name()});
		commands.insert(std::make_pair(com->name(), std::move(com)));
	}

	// return_code specifies the return code of a command.
	enum class return_code {
		ok, not_found, blank_input, exit
	};

	// call_command executes the given command.
	auto call_command(std::string const &command, std::string &name, std::ostream &out) -> return_code;

	// command_category returns the command category.
	auto command_category(std::string const &command) -> std::string;

	// save saves the command history to a file.
	auto save(std::string const &filename) -> void;

	// load loads the command history from a file.
	auto load(std::string const &filename) -> void;

	std::istream &in;
	std::ostream &out;
	context ctx;
	std::unordered_map<std::string, std::unique_ptr<command>> commands;
	std::unordered_multimap<std::string, std::string> category_commands;
	std::vector<std::string> command_history;
	map_view mv;
};

#endif //PANDEMIC_APPLICATION_H
