#include <QDateTime>
#include <QFileInfo>
#include <QTextStream>

class IFileLogs
{
public:
    virtual ~IFileLogs() = default;

    virtual void print(QVector<QFileInfo> files) = 0;
};

class PrintInfoToConsole : public IFileLogs
{
    virtual ~PrintInfoToConsole() override = default;

    void print(QVector<QFileInfo> files) override;
};

class PrintInfoToOtherFile : public IFileLogs
{
    virtual ~PrintInfoToOtherFile() override = default;

    void print(QVector<QFileInfo> files) override;

};

