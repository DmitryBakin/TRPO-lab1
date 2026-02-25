#include "File.h"

class FileManager : public QObject
{
public:
    FileManager();
    FileManager(std::vector<QString> fileNames);
    FileManager(QVector<QString> fileNames);

private:
    std::vector<File> m_fileVector;
};

