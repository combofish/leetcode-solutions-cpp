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
#include <iostream>
#include <mysql/mysql.h>

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
        cout << "mysql connect error: " << mysql_errno(conn) << endl;
        return -1;
    }

    cout << "connect successful" << endl;

    MYSQL_ROW row;

    const char *sql = "select * from pet";

    if (mysql_real_query(conn, sql, (unsigned int) strlen(sql))) {
        cout << "query fail : " << mysql_errno(conn) << endl;
    } else {
        cout << "query success." << endl;
        auto res = mysql_store_result(conn);
        if (res == nullptr) {
            cout << "load data fail : " << mysql_errno(conn) << endl;
        } else {
            while ((row = mysql_fetch_row(res)) != nullptr) {
                cout << row[0] << " " << row[1] << endl;
            }
        }
        mysql_free_result(res);
    }
    mysql_close(conn);

    // code end

    return 0;
}