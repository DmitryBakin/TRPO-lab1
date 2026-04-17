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

signals:
    void onFileCreated(QFileInfo file);
    void onFileRemoved(QFileInfo file);
    void onFileChanged(QFileInfo file);

private:
    QVector<QFileInfo> m_fileVector;

    QVector<QPair<int, bool>> m_vectorOldStates;
    
    QTimer *m_timer;

    IFileLogs *m_outputMethod = new PrintInfoToConsole();
};
