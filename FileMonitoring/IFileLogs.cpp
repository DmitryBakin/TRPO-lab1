#include <iostream>

#include "IFileLogs.h"

void PrintInfoToConsole::print(QFileInfo file)
{
    std::cout
    << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss").toStdString()
    << " Path: " << file.filePath().toStdString()
    << " exists: " << file.exists()
    << " size: " << file.size() << std::endl;
}

void PrintInfoToOtherFile::print(QFileInfo fileInfo)
{

    QFile file("C:/TRPO-lab1-Development/output.txt");
    if (file.open(QFile::WriteOnly | QFile::Append | QFile::Text))
    {
        QTextStream out(&file);
        out
        << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss")
        << " Path: " << fileInfo.filePath()
        << " exists: " << fileInfo.exists()
        << " size: " << fileInfo.size() << "\n";
    }
    file.close();
}
