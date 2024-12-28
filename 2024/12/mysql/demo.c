// gcc -o mysql_demo demo.c -lmysqlclient

#include <stdio.h>
#include <assert.h>
#include <mysql/mysql.h>

const char *host = "82.156.207.47";
const char *user = "hk416hasu";
const char *passwd = "12345678hhh";
const char *db = "test_db";

int main(void) {
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;

  // 初始化 MySQL 连接
  conn = mysql_init(NULL);
  assert(conn != NULL);

  // 连接到数据库
  mysql_real_connect(conn, host, user, passwd, db, 0, NULL, 0);

  // 执行查询
  mysql_query(conn, "SHOW TABLES");

  // 获取查询结果
  res = mysql_store_result(conn);
  assert(res != NULL);

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

