#include <stdio.h>
#include <mysql/mysql.h>

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    const char *server = "localhost";
    const char *user = "root";
    const char *password = "your_password"; // 替换为你的 MySQL 密码
    const char *database = "testdb"; // 替换为你的数据库名称

    // 初始化 MySQL 连接
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return 1;
    }

    // 连接到数据库
    if (mysql_real_connect(conn, server, user, password, database, 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        return 1;
    }

    // 执行查询
    if (mysql_query(conn, "SHOW TABLES")) {
        fprintf(stderr, "Query failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    // 获取查询结果
    res = mysql_store_result(conn);
    if (res == NULL) {
        fprintf(stderr, "mysql_store_result() failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    // 输出结果
    printf("Tables in database:\n");
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%s\n", row[0]);
    }

    // 释放资源并关闭连接
    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}

