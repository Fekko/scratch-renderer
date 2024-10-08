#include "Logging.h"

#include <format>
#include <iostream>

using namespace logging;

void logging::Info(const char* time, const char* functionName, const char* message) {
    std::print(std::cout, "\033[0m[{0}]({1}) {2}\n", time, functionName, message);
}

void logging::Warn(const char* time, const char* functionName, const char* message) {
    std::print(std::cout, "\033[91m[{0}]({1}) {2}\033[0m\n", time, functionName, message);
}

void logging::Error(const char* time, const char* functionName, const char* message) {
    std::print(std::cout, "\033[91;107m[{0}]({1}) {2}\033[0m\n", time, functionName, message);
}