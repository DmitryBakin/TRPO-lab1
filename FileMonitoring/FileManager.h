#include "File.h"

class FileManager : public QObject
{
public:
    static FileManager& Instance()
    {
        static FileManager s;
        return s;
    }

    FileManager();
    FileManager(FileManager const& manager);

    void addFiles(QStringList paths);
    void removeFiles(QStringList paths);

    bool containts(QString path);

private:
    QVector<File> m_fileVector;
};

