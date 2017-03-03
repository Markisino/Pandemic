cmake_minimum_required(VERSION 3.2)
project(pandemic)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp model/players_model.h handle.h application.cpp application.h controller/controller.h controller/reference_card.cpp controller/reference_card.h context.h controller/setup.cpp controller/setup.h controller/view/status.cpp controller/view/status.h model/decks_model.h model/cities_model.h controller/view/cities.cpp controller/view/cities.h controller/place_pawn.cpp controller/place_pawn.h model/game_model.h controller/editor/add_city.cpp controller/editor/add_city.h controller/view/show_deck.cpp controller/view/show_deck.h controller/view/players.cpp controller/view/players.h controller/begin_play.cpp controller/begin_play.h controller/end_turn.cpp controller/end_turn.h controller/editor/add_player.cpp controller/editor/add_player.h controller/editor/create_deck.cpp controller/editor/create_deck.h controller/infect_turn.cpp controller/infect_turn.h)
add_executable(pandemic ${SOURCE_FILES})

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT pandemic)
