#pragma once

#define LOG_ENABLED 1

namespace ScratchRenderer
{
    void Info(const char* time, const char* functionName, const char* message);
    void Warn(const char* time, const char* functionName, const char* message);
    void Error(const char* time, const char* functionName, const char* message);
}

#if _DEBUG 
#define __INFO__(message) \
        Info(__TIME__, __FUNCTION__, message)
#define __WARN__(message) \
        Warn(__TIME__, __FUNCTION__, message)
#define __ERROR__(message) \
        Error(__TIME__, __FUNCTION__, message)
#else
#define __INFO__(message) // Do nothing in release
#define __WARN__(message) // Do nothing in release
#define __ERROR__(message) // Do nothing in release
#endif

