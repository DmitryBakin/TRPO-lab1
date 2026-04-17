#include <QObject>
#include <QCoreApplication>
#include <QDateTime>
#include <QFileInfo>
#include <QTextStream>

class IFileLogs :public QObject
{
    Q_OBJECT
public:
    virtual ~IFileLogs() = default;

public slots:
    virtual void print(QFileInfo file) = 0;

};

class PrintInfoToConsole : public IFileLogs
{
    Q_OBJECT
    virtual ~PrintInfoToConsole() override = default;

public slots:
    void print(QFileInfo file) override;
};

class PrintInfoToOtherFile : public IFileLogs
{
    Q_OBJECT
    virtual ~PrintInfoToOtherFile() override = default;

public slots:
    void print(QFileInfo file) override;

};

