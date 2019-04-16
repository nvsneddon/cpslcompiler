cmake_minimum_required(VERSION 2.8)
project(cpsl)

find_package(BISON)
find_package(FLEX)

bison_target(Parser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(Scanner scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
add_flex_bison_dependency(Scanner Parser)

set(EXTRA_COMPILE_FLAGS "-g3 -std=c++14")
set(CMAKE_BUILD_TYPE Debug)
#[[set(CMAKE_BUILD_TYPE RelWithDebInfo)]]

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EXTRA_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

set(cpsl_srcs
	Tables/symbol_table.hpp
	Tables/symbol_table.cpp
	Tables/reg_table.hpp
	Tables/reg_table.cpp
	main.cpp
	Statements/write.hpp
	Statements/write.cpp
	Statements/statement.hpp
	Statements/statementlist.hpp
	Lists/idlist.cpp
	Lists/idlist.hpp
	Lists/stringlist.hpp
	Lists/stringlist.cpp
	Labels/looplabels.hpp
	Labels/looplabels.cpp
	Expressions/expression.hpp
	Expressions/expression.cpp
	Expressions/constexpression.hpp
	Expressions/constexpression.cpp
	Expressions/memexpression.hpp
	Expressions/memexpression.cpp
	Expressions/tempmemexpression.hpp
	Expressions/tempmemexpression.cpp
	Expressions/regexpression.hpp
	Expressions/regexpression.cpp
	Expressions/expressionslist.hpp
	Expressions/expressionslist.cpp
	Types/simpletype.hpp
	Types/type.hpp
	Types/array.hpp
	Types/array.cpp
	Types/record.hpp
	Types/record.cpp
	includes.hpp
	${BISON_Parser_OUTPUTS}
	${FLEX_Scanner_OUTPUTS}
)
source_group("Calc" FILES ${cpsl_srcs})

add_executable(cpsl ${cpsl_srcs})
target_link_libraries(cpsl ${FLEX_LIBRARIES} ${BISON_LIBRARIES})
target_include_directories(cpsl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

