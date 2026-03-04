#include <QCoreApplication>
#include <iostream>

#include "FileManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //File file("C:/GItHub/TRPO-lab1/FileMonitoring/text.txt");

    //std::cout << file.exists() << "\n" << file.size() << " byte\n";

    QString fileNames = "C:/GItHub/TRPO-lab1/FileMonitoring/text.txt,C:/GItHub/TRPO-lab1/FileMonitoring/tex.txt";

    QStringList list = fileNames.split(',');

    FileManager& instance = FileManager::Instance();

    instance.addFiles(list);

    std::cout << instance.getFileVector()[0].exists() << std::endl;

    return a.exec();
}
