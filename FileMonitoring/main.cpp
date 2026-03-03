#include "FileManager.h"

#include <iostream>

int main()
{
    //File file("C:/GItHub/TRPO-lab1/FileMonitoring/text.txt");

    //std::cout << file.exists() << "\n" << file.size() << " byte\n";

    QString fileNames = "C:/GItHub/TRPO-lab1/FileMonitoring/text.txt,C:/GItHub/TRPO-lab1/FileMonitoring/tex.txt";

    QStringList list = fileNames.split(',');

    FileManager& instance = FileManager::Instance();

    instance.addFiles(list);

    return 0;
}
