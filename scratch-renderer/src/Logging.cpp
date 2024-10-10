#include "Logging.h"

#include <format>
#include <iostream>

void ScratchRenderer::Info(const char* time, const char* functionName, const char* message) {
    std::print(std::cout, "\033[0m[{0}]({1}) {2}\n", time, functionName, message);
}

void ScratchRenderer::Warn(const char* time, const char* functionName, const char* message) {
    std::print(std::cout, "\033[91m[{0}]({1}) {2}\033[0m\n", time, functionName, message);
}

void ScratchRenderer::Error(const char* time, const char* functionName, const char* message) {
    std::print(std::cout, "\033[91;107m[{0}]({1}) {2}\033[0m\n", time, functionName, message);
}