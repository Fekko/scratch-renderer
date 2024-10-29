#include "Logging.h"

#include <format>
#include <iostream>
#include <chrono> 

using namespace std::chrono;

void ScratchRenderer::Info(const char* functionName, const char* message) {
    auto now = time_point_cast<seconds>(system_clock::now());
    std::print(std::cout, "\033[0m[{0:%H:%M:%S}]({1}) {2}\n", now, functionName, message);
}

void ScratchRenderer::Warn(const char* functionName, const char* message) {
    auto now = time_point_cast<seconds>(system_clock::now());
    std::print(std::cout, "\033[91m[{0:%H:%M:%S}]({1}) {2}\033[0m\n", now, functionName, message);
}

void ScratchRenderer::Error(const char* functionName, const char* message) {
    auto now = time_point_cast<seconds>(system_clock::now());
    std::print(std::cout, "\033[91;107m[{0:%H:%M:%S}]({1}) {2}\033[0m\n", now, functionName, message);
}