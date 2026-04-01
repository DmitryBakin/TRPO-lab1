#include <iostream>

#include "IFileLogs.h"

void PrintInfoToConsole::print(QVector<QFileInfo> files)
{
    for(int i = 0; i < files.size(); i++)
    {
        std::cout << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss").toStdString() << " Path: " << files[i].filePath().toStdString() << " exists: " << files[i].exists() << " size: " << files[i].size() << std::endl;
    }
}

void PrintInfoToOtherFile::print(QVector<QFileInfo> files)
{

    QFile file("C:/TRPO-lab1-Development/output.txt");
    if (file.open(QFile::WriteOnly | QFile::Append | QFile::Text))
    {
        QTextStream out(&file);
        for(int i = 0; i < files.size(); i++)
        {
            out << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss") << " Path: " << files[i].filePath() << " exists: " << files[i].exists() << " size: " << files[i].size() << "\n";
        }
    }
    file.close();
}
