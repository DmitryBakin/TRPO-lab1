#include "FileManager.h"

#include <iostream>

int main()
{
    File file("C:/GItHub/TRPO-lab1/FileMonitoring/text.txt");

    std::cout << file.exists() << "\n" << file.size() << " byte\n";

    return 0;
}
