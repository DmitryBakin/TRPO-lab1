#include <QTimer>

#include "IFileLogs.h"

class FileManager : public QObject
{
    Q_OBJECT

public:

    static FileManager& Instance()
    {
        static FileManager s;
        return s;
    }

private:

    FileManager();
    FileManager(FileManager const& manager);
    ~FileManager();

public:

    QVector<QFileInfo> getFileVector();

    void setOutputMethod(IFileLogs* outputMethod);

    void addFiles(QStringList paths);
    void removeFiles(QStringList paths);

    bool contains(QString path) const;

    void startTimer();
    void stopTimer();

public slots:
    void onTimeout();

private:
    QVector<QFileInfo> m_fileVector;
    
    QTimer *m_timer;

    IFileLogs *m_outputMethod = new PrintInfoToConsole();
};
