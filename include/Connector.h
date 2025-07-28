#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <Poco/Data/Session.h>
#include <string>
#include <vector>

class Connector {
public:
    Connector(const std::string& connStr);
    bool connect();
    void disconnect();
    bool isConnected() const;
    std::vector<std::vector<std::string>> executeSelect(const std::string& query);
    bool executeNonQuery(const std::string& query);

private:
    std::string _connectionString;
    Poco::Data::Session _session;
    bool _connected;
};

#endif // CONNECTOR_H
