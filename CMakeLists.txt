cmake_minimum_required(VERSION 2.6)

project(enum-map)

# Adds header files to global HEADER_LIST property
get_property(VAR_HEADER_LIST GLOBAL PROPERTY HEADER_LIST)
set_property(GLOBAL PROPERTY HEADER_LIST
	${VAR_HEADER_LIST}
	enum-map/EnumMap.h
	enum-map/EnumMap-inl.h)

install(FILES EnumMap.h EnumMap-inl.h DESTINATION include/sadehghan)
