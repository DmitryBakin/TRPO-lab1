#include <iostream>

#include "IFileLogs.h"

void PrintInfoToConsole::print(const QFileInfo& file)
{
    qDebug()
    << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss")
    << " Path:" << file.filePath()
    << " Exists:" << file.exists()
    << " Size:" << file.size();
}

void PrintInfoToOtherFile::print(const QFileInfo& fileInfo)
{
    QString appDir = QCoreApplication::applicationDirPath();

    QDir projectDir(appDir);
    projectDir.cdUp();
    projectDir.cdUp();
    projectDir.cdUp();

    QString filePath = projectDir.absolutePath() + "/output.txt";

    QFile file(filePath);
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
