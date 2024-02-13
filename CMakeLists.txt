cmake_minimum_required(VERSION 3.0.0)
project(week4 VERSION 0.1.0 LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 20)

add_executable(matrix_seminars_week4                                   ./seminars/week4/matrix_problem/main.cpp ./seminars//week4/matrix_problem/matrix.h ./seminars//week4/matrix_problem/matrix.cpp)
add_executable(readfile_seminars_week4                                 ./seminars/week4/readFile_problem/main.cpp)
add_executable(problem4_contest2_similar_sound                         ./contests/contest_2/problem4.cpp)



#contest3
add_executable(problem1_contest3_countWords                         ./contests/contest_3/problem1_countWords.cpp)
