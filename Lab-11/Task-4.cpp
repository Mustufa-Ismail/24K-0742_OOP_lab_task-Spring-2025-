#include <iostream>
#include <exception>

using namespace std;

class DatabaseException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "A Database error occurred";
    }
};

class ConnectionFailedException : public DatabaseException
{
};

class QueryTimeoutException : public DatabaseException
{
};

template <typename T>
class Database
{
public:
    void connect()
    {
        throw ConnectionFailedException();
    }
    void Query()
    {
        throw QueryTimeoutException();
    }
};

int main()
{
    Database<int> db;
    try
    {
        db.connect();
        db.Query();
    }
    catch (const ConnectionFailedException &e)
    {
        cout << "Caught ConnectionFailedException -what()" << e.what() << endl;
    }
    catch (const QueryTimeoutException &e)
    {
        cout << "Caught QueryTimeoutException -what() " << e.what() << endl;
    }

    return 0;
}