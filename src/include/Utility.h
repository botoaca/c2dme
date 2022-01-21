#pragma once
#include <string>
#include <vector>
#include <iostream>

class Logger
{
    public:
        void AddLog(std::string);
        void AddWarning(std::string);
        void AddError(std::string);
        void Clear();
        void Print();

    private:
        std::vector<std::string> logs;
};

void clear_screen();