#include <iostream>
#include "spdlog/spdlog.h"
#include "passwordvalidator.hpp"

int main()
{
    try
    {
        PasswordValidator::isValid("");
    }
    catch(const std::exception& e)
    {
        const std::string errorText{ e.what() };
        spdlog::critical(errorText);
    }

    return 0;
}