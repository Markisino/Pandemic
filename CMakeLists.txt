cmake_minimum_required(VERSION 3.2)
project(pandemic)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
		main.cpp
		model/players_model.h
		handle.h
		application.cpp
		application.h
		command.h
		controller/reference_card.cpp
		controller/reference_card.h context.h
        view/status.cpp
        view/status.h
		model/decks_model.h
		model/cities_model.h
        view/cities.cpp
        view/cities.h
		controller/place_pawn.cpp
		controller/place_pawn.h
		model/game_model.h
		controller/editor/add_city.cpp
		controller/editor/add_city.h
        view/show_deck.cpp
        view/show_deck.h
        view/players.cpp
        view/players.h
		controller/begin_play.cpp
		controller/begin_play.h
		controller/end_turn.cpp
		controller/end_turn.h
		controller/editor/add_player.cpp
		controller/editor/add_player.h
		controller/editor/create_deck.cpp
		controller/editor/create_deck.h
		controller/editor/shuffle_deck.cpp
		controller/editor/add_to_deck.h
		controller/editor/add_to_deck.cpp
		controller/editor/shuffle_deck.h
		controller/editor/move_top_card.h
		controller/editor/move_top_card.cpp
		controller/editor/give_role.h
		controller/editor/give_role.cpp
		controller/draw_turn.h
		controller/draw_turn.cpp
		controller/editor/add_cities_to_deck.h
		controller/editor/add_cities_to_deck.cpp
		controller/editor/place_research_station.h
		controller/editor/place_research_station.cpp
		controller/editor/set_research_station_supply.h
		controller/editor/set_research_station_supply.cpp
		controller/editor/set_disease_cube_supply.h
		controller/editor/set_disease_cube_supply.cpp
		controller/editor/infect.h
		controller/editor/infect.cpp
		controller/action/direct_flight_to.h
		controller/action/direct_flight_to.cpp
		controller/infect_turn.h
		controller/infect_turn.cpp
		controller/action/drive_to.h
		controller/action/drive_to.cpp
		controller/action/shuttle_flight_to.h
		controller/action/shuttle_flight_to.cpp
		controller/action/charter_flight_to.h
		controller/action/charter_flight_to.cpp
		controller/action/treat_disease.h
		controller/action/treat_disease.cpp
		controller/action/share_knowledge_to.h
		controller/action/share_knowledge_to.cpp
		controller/action/share_knowledge_from.h
		controller/action/share_knowledge_from.cpp
		controller/action/discover_cure.h
		controller/action/discover_cure.cpp
		controller/editor/validate_city_connections.cpp
		controller/editor/validate_city_connections.h observer/observer.h observer/subject.h observer/map_view.h)
add_executable(pandemic ${SOURCE_FILES})

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT pandemic)
