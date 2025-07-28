// Task 7: Implementing a Distributed Database Connector with Poco C++ Libraries

#include "Connector.h"
#include <Poco/Data/SessionFactory.h>
#include <Poco/Data/ODBC/Connector.h>
#include <Poco/Data/RecordSet.h>
#include <Poco/Data/Statement.h>
#include <Poco/Exception.h>
#include <iostream>

using namespace Poco::Data;

Connector::Connector(const std::string& connStr)
    : _connectionString(connStr), _connected(false) {
    ODBC::Connector::registerConnector();
}

bool Connector::connect() {
    try {
        _session = SessionFactory::instance().create(ODBC::Connector::KEY, _connectionString);
        _connected = true;
        std::cout << "Connected successfully.\n";
        return true;
    } catch (const Poco::Exception& ex) {
        std::cerr << "Connection failed: " << ex.displayText() << std::endl;
        return false;
    }
}

void Connector::disconnect() {
    if (_connected) {
        _session.close();
        _connected = false;
    }
}

bool Connector::isConnected() const {
    return _connected;
}

std::vector<std::vector<std::string>> Connector::executeSelect(const std::string& query) {
    std::vector<std::vector<std::string>> result;
    try {
        Statement stmt(_session);
        stmt << query, now;

        RecordSet rs(stmt);
        bool more = rs.moveFirst();
        while (more) {
            std::vector<std::string> row;
            for (std::size_t i = 0; i < rs.columnCount(); ++i) {
                row.push_back(rs[i].convert<std::string>());
            }
            result.push_back(row);
            more = rs.moveNext();
        }
    } catch (const Poco::Exception& ex) {
        std::cerr << "Select failed: " << ex.displayText() << std::endl;
    }
    return result;
}

bool Connector::executeNonQuery(const std::string& query) {
    try {
        Statement stmt(_session);
        stmt << query, now;
        return true;
    } catch (const Poco::Exception& ex) {
        std::cerr << "Execution failed: " << ex.displayText() << std::endl;
        return false;
    }
}
