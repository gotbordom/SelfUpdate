// Project Includes
// CPP Includes
# include <iostream>

// Relative path includes
# include "include/selfupdate/config.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    std::cout << "Project Name: " << PROJECT_NAME << std::endl;
    std::cout << "Version: " << PROJECT_VERSION << std::endl;
    return 0;
}