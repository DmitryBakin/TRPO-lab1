#include "File.h"

class FileManager : public QObject
{
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

    void addFiles(QStringList paths);
    void removeFiles(QStringList paths);

    bool containts(QString path);
    QVector<File> getFileVector();

public slots:


private:
    QVector<QFileInfo> m_fileVector;
    
    QTimer *m_timer;

    IFileLogs *m_outputMethod = new PrintInfoToConsole();
};

