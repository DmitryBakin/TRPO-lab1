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
    FileManager(const FileManager& manager) = delete;
    FileManager& operator=(const FileManager& manager) = delete;
    ~FileManager();

public:

    QVector<QFileInfo> getFileVector();

    void setOutputMethod(IFileLogs* outputMethod);

    void addFiles(QStringList paths);
    void removeFiles(QStringList paths);
    void clear();

    bool contains(const QString& path) const;

public slots:
    void onTimeout();

signals:
    void onFileCreated(const QFileInfo& file);
    void onFileRemoved(const QFileInfo& file);
    void onFileChanged(const QFileInfo& file);

private:
    QVector<QFileInfo> m_fileVector;

    QVector<QPair<int, bool>> m_vectorOldStates;
    
    QTimer *m_timer;

    IFileLogs *m_outputMethod;
};
