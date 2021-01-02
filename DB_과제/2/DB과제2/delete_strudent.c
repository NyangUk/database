#include <mysql.h>
#include <stdio.h>
#include <string.h>
//DELETE table_name WHERE id = 1105;

MYSQL* conn;
MYSQL_RES* res;
MYSQL_ROW row;

bool delete_student(char *id){

    char *temp_query = "delete from student where id = %s;";
    char *query = (char *) malloc(strlen(temp_query)+20);
    sprintf(query,temp_query,id);
        if (mysql_query(conn, query))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_use_result(conn);
    free(query);
}
int main() {
    char* server = "localhost";
    char* user = "group11";
    char* password = "2020";
    char* database = "group11_university_db";

    conn = mysql_init(NULL);
    // 계정 연결 하기
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    delete_student("11111");
    delete_student("11112");
    delete_student("11113");
    delete_student("11114");

    // 결과를 확인하기 위해 student 테이블 조회
    if(mysql_query(conn, "select * from student ;")){
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    res=mysql_use_result(conn);

    /* output table student */
    printf("\n\n* * * * Result of query * * * *\n\n");
    puts("_______________________________________________________________________");
    puts("");

    printf("%10s | %30s | %20s | %10s\n\n", "ID", "Name", "Dept. Name", "Credits");
    while ((row = mysql_fetch_row(res)) != NULL)
        printf("%10s | %30s | %20s | %10s\n", row[0], row[1], row[2], row[3]);
    puts("_______________________________________________________________________");

    /* close connection */
    mysql_free_result(res);
    mysql_close(conn);
}