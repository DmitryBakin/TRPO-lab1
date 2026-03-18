#include <QDateTime>
#include <QFile>
#include <QTextStream>


#include "File.h"

class IFileLogs
{
public:
    virtual ~IFileLogs() = default;

    virtual void print(QVector<File> files) = 0;
};

class PrintInfoToConsole : public IFileLogs
{
    virtual ~PrintInfoToConsole() override = default;

    void print(QVector<File> files) override;
};

class PrintInfoToOtherFile : public IFileLogs
{
    virtual ~PrintInfoToOtherFile() override = default;

    void print(QVector<File> files) override;

};

