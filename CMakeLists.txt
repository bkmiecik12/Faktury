cmake_minimum_required(VERSION 3.7)
project(Faktury)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CKalendarz.cpp CKalendarz.h CFaktura.cpp CFaktura.h CPodmiot.cpp CPodmiot.h CNabywca.cpp CNabywca.h CSprzedawca.cpp CSprzedawca.h CTowar.cpp CTowar.h CScheduler.cpp CScheduler.h)
add_executable(Faktury ${SOURCE_FILES})