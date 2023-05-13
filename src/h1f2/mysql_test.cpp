/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <mysql/mysql.h>
#include <iostream>

using namespace std;

int main() {
    // code start

    const char *server = "localhost";
    const char *user = "larry";
    const char *database = "test";

    cout << "Please enter password:";
    string passwd;
    cin >> passwd;

    const char *password = passwd.c_str();
    auto conn = mysql_init(nullptr);
    if (!mysql_real_connect(conn, server, user, password,
                            database, 0, nullptr, 0)) {
        cout << mysql_error(conn);
        return -1;
    }

    if (mysql_query(conn, "show tables")) {
        cout << mysql_error(conn);
        return -2;
    }

    auto res = mysql_use_result(conn);

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res)) != nullptr) {
        cout << row[0] << endl;
    }

    mysql_free_result(res);
    mysql_close(conn);

    // code end

    return 0;
}