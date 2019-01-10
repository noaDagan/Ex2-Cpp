cmake_minimum_required(VERSION 3.12)
project(projectNum2)

set(CMAKE_CXX_FLAGS "-std=c++14 -pthread")
#set(CMAKE_CXX_STANDARD 14)

add_executable(projectNum2 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.h Solver.h CacheManager.h FileCacheManager.h StringReverse.cpp StringReverse.h State.h Searchable.h Searcher.h BFS.h MatrixSolver.h Matrix.h DFS.h BestFirsrtSearche.h AStar.h MyClientHandler.cpp MyClientHandler.h)