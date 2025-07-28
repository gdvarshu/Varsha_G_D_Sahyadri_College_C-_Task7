#include "Connector.h"
#include <iostream>

int main() {
    std::string connStr = "DRIVER={PostgreSQL Unicode};Server=127.0.0.1;Port=5433;Database=yugabyte;UID=yugabyte;PWD=yugabyte;";
    Connector db(connStr);

    if (db.connect()) {
        db.executeNonQuery("INSERT INTO users (id, name) VALUES (1, 'Alice')");
        auto rows = db.executeSelect("SELECT * FROM users");

        for (const auto& row : rows) {
            for (const auto& col : row) std::cout << col << " ";
            std::cout << std::endl;
        }
    }

    return 0;
}
