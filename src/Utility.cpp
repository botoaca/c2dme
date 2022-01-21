#include "include/Utility.h"

void Logger::AddLog(std::string log)
{
    logs.push_back("\033[1;32m" + log + "\033[0m");
}

void Logger::AddWarning(std::string warning)
{
    logs.push_back("\033[1;33m" + warning + "\033[0m");
}

void Logger::AddError(std::string error)
{
    logs.push_back("\033[1;31m" + error + "\033[0m");
}

void Logger::Clear()
{
    logs.clear();
}

void Logger::Print()
{
    for (const std::string& log : logs)
        std::cout << log << "\n";
}

void clear_screen() {  std::cout << "\033[2J\033[0;0H"; }