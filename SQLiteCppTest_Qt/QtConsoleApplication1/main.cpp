#define SQLITECPP_COMPILE_DLL
#include <QtCore/QCoreApplication>
#include <string>
#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/VariadicBind.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Hello.";
    static const std::string name("example.db3");
    try {
        SQLite::Database database(name, SQLite::OPEN_CREATE | SQLite::OPEN_READWRITE);
        qInfo() << database.getFilename().c_str();

    }
    catch (std::exception& e) {
        qInfo() << "SQlite exception:" << e.what();
    }
    return a.exec();
}
