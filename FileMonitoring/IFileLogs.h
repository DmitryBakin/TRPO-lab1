#include <QObject>
#include <QDir>
#include <qDebug>
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
    virtual void print(const QFileInfo& file) = 0;

};

class PrintInfoToConsole : public IFileLogs
{
    Q_OBJECT
public:
    virtual ~PrintInfoToConsole() override = default;

public slots:
    void print(const QFileInfo& file) override;
};

class PrintInfoToOtherFile : public IFileLogs
{
    Q_OBJECT
public:
    virtual ~PrintInfoToOtherFile() override = default;

public slots:
    void print(const QFileInfo& file) override;

};

