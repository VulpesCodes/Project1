cmake_minimum_required(VERSION 3.16)
project(Project1_Starter_Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project1_Starter_Code
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        CommaAutomaton.cpp
        CommaAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h PeriodAutomaton.cpp PeriodAutomaton.h QMarkAutomaton.cpp QMarkAutomaton.h LeftParenAutomaton.cpp LeftParenAutomaton.h)
