#include <mysql.h>
#include <stdio.h>
#include <string.h>
//DELETE table_name WHERE id = 1105;

MYSQL* conn;
MYSQL_RES* res;
MYSQL_ROW row;

bool insert_new_student(char *id, char *name, char *dept , int credits){

    char *temp_query = "insert into student values ('%s', '%s', '%s', '%d');";
    char *query = (char *) malloc(strlen(temp_query)+20);
    sprintf(query,temp_query,id, name,dept,credits);
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
    // 데이터 추가
    insert_new_student("11111","jaeuk","History",4);
    insert_new_student("11112","haeseong","History",2);
    insert_new_student("11113","hyunjin","History",3);
    insert_new_student("11114","hyojun","History",1);

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