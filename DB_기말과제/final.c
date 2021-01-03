#include <mysql.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>


char storage_Type[10] = "txt";

int space_Range = 11600;
int total_Space = 10240000;
int used_Space = 0;

int temp_Space_Range;
int choice;
int temp = 0;

char temp2;
char temp3[50] = " ";

int UserID;
char UserName[20];

char ID[10];
char PW[10];
char filePath[50];


int main(){
    /* CONNECTION */

    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;
    conn = mysql_init(NULL);

    char* server = "localhost";
    char* user = "root";
    char* password = "wodnr12!@";
    char* database = "group11_final_db";

    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    
    while(1){
        Menu:
            puts("-------------------------");
            printf("1. Admin\n2. User\n3. Logout\n");
            puts("-------------------------");
            printf("> ");
            scanf("%d", &choice);
        
        if(choice == 1){
            SV:  
                if (mysql_query(conn, "SELECT UserID, UserPW, SV FROM users;")) {
                    fprintf(stderr, "%s\n", mysql_error(conn));
                    exit(1);
                }

                res = mysql_use_result(conn);
                
                printf("ID : ");
                scanf("%s", ID);
                printf("PW : ");
                scanf("%s", PW);

                
            while ((row = mysql_fetch_row(res)) != NULL) {
                if (strcmp(ID, row[0]) == 0 && strcmp(PW, row[1]) == 0 && strcmp("1", row[2])==0){
                    printf("Succeeed to Login\n");
                    mysql_free_result(res);

                    /* SV MODE */
                    while(1){
                        puts("-------------------------");
                        printf("1. Change Storage Type\n2. Chnage Space Range\n3. User Status\n4. Space Information\n5. Logout\n");
                        puts("-------------------------");
                        printf("> ");
                        scanf("%d", &choice);

                        switch(choice){
                            case 1:
                                printf("Storage Type as... : ");
                                scanf("%s", storage_Type);
                                puts("-------------------------");
                                printf("Storage Type Has Been changed as %s\n", storage_Type);
                                puts("-------------------------");
                                continue;
                            case 2:
                                temp_Space_Range = space_Range;
                                puts("-------------------------");
                                printf("Current Space Range : %d\n", space_Range);
                                puts("-------------------------");
                                printf("New Space Range? : ");
                                scanf("%d", &space_Range);
                               
                                puts("-------------------------");
                                printf("Space Range Has Been Changed\n");
                                printf("%d ---> %d\n", temp_Space_Range, space_Range);
                                puts("-------------------------");
                                continue;
                            case 3:
                                if (mysql_query(conn, "SELECT * FROM users;")){
                                    fprintf(stderr, "%s\n", mysql_error(conn));
                                    exit(1);
                                }

                                res = mysql_use_result(conn);

                                printf("\n\n **** users Status **** \n\n");
                                puts("_______________________________________________________________________________");
                                puts("");
                                printf("%10s | %10s \n\n", "UserID", "UserName");

                                while ((row = mysql_fetch_row(res)) != NULL)
                                    printf("%10s | %10s \n", row[0], row[1]);
                                    puts("_______________________________________________________________________________");

                                mysql_free_result(res);
                                continue;
                            case 4:
                                if (mysql_query(conn, "SELECT FileSize FROM MetaData;")){
                                    fprintf(stderr, "%s\n", mysql_error(conn));
                                    exit(1);
                                }

                                res = mysql_use_result(conn);

                                while ((row = mysql_fetch_row(res)) != NULL){
                                    temp += atoi(row[0]);
                                    used_Space += temp;
                                }
                            
                                puts("-------------------------");
                                printf("Total Space : %d\n", total_Space);
                                printf("Used  Space : %d\n", used_Space);
                                printf("Free Space  : %d\n", total_Space - used_Space);
                                puts("-------------------------");

                                mysql_free_result(res);
                                temp = 0;
                                continue;
                            case 5:
                                goto Menu;
                                break;
                         }
                    }
                }
            }
            printf("Failed to Login\n");
            printf("Try again\n");
            mysql_free_result(res);
            goto SV;    

                
        }
        else if(choice == 2){
            USER:
                puts("-------------------------");
                printf("1. Sign Up\n2. Sign In\n3.Return\n");
                puts("-------------------------");
                printf("> ");
                scanf("%d", &choice);

               if(choice == 1){
                    create:
                    printf("Name ? > ");
                    scanf("%s", UserName);
                    printf("ID ? > ");
                    scanf("%d", &UserID);
                    printf("PW ? > ");
                    scanf("%s", PW);
                   
                    printf("Name : %s\nID : %d\n PW : %s\nIs This Correct(Only Y/N)? > ", UserName, UserID, PW);
                    scanf("%s", &temp2);
                    if(temp2 == 'Y'){
                    char* temp_query = "INSERT INTO users VALUES('%d','%s','%s', NULL)";
                    char* query = (char*)malloc(strlen(temp_query) + 20);
                        sprintf(query, temp_query, UserID, UserName, PW);

                    if (mysql_query(conn, query)) {
                        fprintf(stderr, "%s\n", mysql_error(conn));
                        exit(1);
                    }
                    mysql_query(conn, query);
                    }
                    else{
                        goto create;
                    }
                }
                else if(choice == 2){   
                    if (mysql_query(conn, "SELECT UserID, UserPW FROM users;")) {
                        fprintf(stderr, "%s\n", mysql_error(conn));
                        exit(1);
                    }

                    res = mysql_use_result(conn);

                    printf("ID : ");
                    scanf("%s", ID);
                    printf("PW : ");
                    scanf("%s", PW);

                
                    while ((row = mysql_fetch_row(res)) != NULL) {
                        if (strcmp(ID, row[0]) == 0 && strcmp(PW, row[1]) == 0){
                            printf("Succeeed to Login\n");
                            UserID = atoi(ID);
                            mysql_free_result(res);
                            while(1){
                                puts("-------------------------");
                                printf("1. Upload\n2. Delete\n3. Update\n4. Table\n5. Find\n6. Filter\n7. Logout\n");
                                puts("-------------------------");
                                printf("> ");
                                scanf("%d", &choice);

                                switch(choice){
                                    case 1:
                                        while(1){
                                            UP:
                                            printf("File path (quit to type exit)? > ");
                                            scanf("%s", filePath);
                                            if(strcmp(filePath, "exit") == 0){
                                                break;
                                            }
                                            char *ptr = strstr(filePath, storage_Type);
                                            if(ptr == NULL){
                                                printf("You can not upload this file check your filename extention!\n");
                                                goto UP;
                                            }
                                            struct stat attr;
                                            stat(filePath, &attr);

                                            char *temp_query = "insert into MetaData values ( NULL , '%s', '%d', NOW(),'%d');";
                                            char *query = (char *) malloc(strlen(temp_query)+20);
                                            
                                            if((int)attr.st_size > total_Space - used_Space || (int)attr.st_size > space_Range){
                                                printf("Space allocated for you isn't enough for this file!\n");
                                                printf("Upload denied going back to the Menu\n");
                                                goto USER;
                                            }
                                            else{
                                                sprintf(query,temp_query, filePath,(int)attr.st_size,UserID);

                                                if (mysql_query(conn, query))
                                                {
                                                    fprintf(stderr, "%s\n", mysql_error(conn));
                                                    printf("Failed to upload\n");
                                                    goto UP;
                                                }
                                                    printf("Succeeded to upload\n");
                                                    printf("File name : %s\tSize : %d\n", filePath, (int)attr.st_size);
                                            }
                                                
                                            free(query);
                                                    
                                        }
                                        continue;
                                    case 2:
                                        DEL:
                                            while(1){
                                                printf("File name you want to delete (quit to type exit)> ");
                                                scanf("%s", filePath);
                                                getchar();
                                                    if(strcmp(filePath, "exit") == 0){
                                                        break;
                                                    }

                                                char *temp_query = "delete from MetaData where FileName = '%s' and UserID = %d;";
                                                char *query = (char *) malloc(strlen(temp_query)+20);

                                                sprintf(query,temp_query, filePath, UserID);

                                                if (mysql_query(conn, query))
                                                {
                                                    fprintf(stderr, "%s\n", mysql_error(conn));
                                                    printf("Failed to delete!\n");
                                                    goto DEL;

                                                }
                                                    printf("Succeed to delete!\n");
                                                    free(query);
                                                }  
                                        continue;
                                    case 3:
                                        while(1){
                                            printf("File name you want to update (quit to type exit)> ");
                                            scanf("%s", filePath);
                                            getchar();
                                            if(strcmp(filePath, "exit") == 0){
                                                break;
                                            }

                                            char *temp_query = "update MetaData set ModifyTime = NOW() where FileName = '%s' and UserID = %d;";
                                            char *query = (char *) malloc(strlen(temp_query)+20);

                                            sprintf(query,temp_query, filePath, UserID);

                                            if (mysql_query(conn, query)){
                                                fprintf(stderr, "%s\n", mysql_error(conn));
                                                printf("Failed to update!\n");
                                                goto DEL;

                                            }
                                            printf("Succeed to update!\n");
                                                // res = mysql_use_result(conn);
                                            free(query);
                                        }  

                                        continue;
                                    case 4:
                                        while(1){
                                            char *temp_query = "select bigFileID, FileID, DataPath, FileSize, ModifyTime, Hot, UpdatedCount from BigFiles natural left outer join MetaData where UserID = %d;";
                                            char *query = (char *) malloc(strlen(temp_query)+20);
                                            sprintf(query, temp_query, UserID);
                                            if(mysql_query(conn, query)){
                                                fprintf(stderr, "%s\n", mysql_error(conn));
                                                printf("Failed to show tables!\n");
                                            }
                                            res = mysql_use_result(conn);

                                            puts("BigFiles");
                                            puts("-----------------------------------------------------------------------------------------");
                                            puts("");
                                            printf("%10s | %10s | %10s | %10s | %25s | %10s | %10s \n\n", "bigFileID", "FileID", "Data", "FileSize", "ModifyTime", "Hot" ,"UpdatedCount");
                                            while ((row = mysql_fetch_row(res)) != NULL)
                                            printf("%10s | %10s | %10s | %10s | %25s | %10s | %10s \n", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                                            puts("-----------------------------------------------------------------------------------------");

                                            free(query);
                                            mysql_free_result(res);

                                            char *temp_query1 = "select smallFileID, FileID, DataPath, FileSize, ModifyTime, Hot, UpdatedCount from SmallFiles natural left outer join MetaData where UserID = %d;";
                                            char *query1 = (char *) malloc(strlen(temp_query1)+20);
                                            sprintf(query1, temp_query1, UserID);
                                            if(mysql_query(conn, query1)){
                                                fprintf(stderr, "%s\n", mysql_error(conn));
                                                printf("Failed to show tables!\n");
                                            }
                                            res = mysql_use_result(conn);

                                            puts("SmallFiles");
                                            puts("-----------------------------------------------------------------------------------------");
                                            puts("");
                                            printf("%10s | %10s | %10s | %10s | %25s | %10s | %10s \n\n", "smallFileID", "FileID", "Data", "FileSize", "ModifyTime", "Hot" ,"UpdatedCount");
                                            while ((row = mysql_fetch_row(res)) != NULL)
                                            printf("%10s | %10s | %10s | %10s | %25s | %10s | %10s \n", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
                                            puts("-----------------------------------------------------------------------------------------");

                                            free(query1);
                                            mysql_free_result(res);

                                            char *temp_query2 = "select count(case when  HOT = 1 then 1 end) as HOT, count(case when HOT = 0 then 1 end) as COLD from BigFiles where UserID = %d;";
                                            char *query2 = (char *) malloc(strlen(temp_query2)+20);
                                            sprintf(query2, temp_query2, UserID);
                                            if(mysql_query(conn, query2)){
                                                fprintf(stderr, "%s\n", mysql_error(conn));
                                                printf("Failed to show tables!\n");
                                            }
                                            res = mysql_use_result(conn);

                                            puts("Hot and Cold");
                                            puts("-----------------------------------------------------------------------------------------");
                                            puts("");
                                            printf("\t\t%10s | %10s  \n\n", "Hot", "Cold");
                                            while ((row = mysql_fetch_row(res)) != NULL)
                                            printf("%10s | %10s | %10s \n", "BigFile", row[0], row[1]);
                                            free(query2);
                                            mysql_free_result(res);
                                        
                                            char *temp_query3 = "select count(case when Hot = 1 then 1 end) as Hot, count(case when Hot = 0 then 1 end) as Cold from SmallFiles where UserID = %d;";
                                            char *query3 = (char *) malloc(strlen(temp_query3)+20);
                                            sprintf(query3, temp_query3, UserID);
                                            if(mysql_query(conn, query3)){
                                                fprintf(stderr, "%s\n", mysql_error(conn));
                                                printf("Failed to show tables!\n");
                                            }

                                            res = mysql_use_result(conn);

                                            while ((row = mysql_fetch_row(res)) != NULL)
                                                printf("%10s | %10s | %10s \n", "SmallFile", row[0], row[1]);
                                                puts("-----------------------------------------------------------------------------------------");

                                            free(query3);
                                            mysql_free_result(res);
                                            break;
                                        }
                                        continue;

                                    case 5:
                                        while(1){
                                            char tempname[20];
                                            printf("Type the file name you are looking for > ");
                                            scanf("%s", tempname);

                                            char* temp_query5 = "SELECT * FROM MetaData WHERE FileName = '%s' and UserID = %d;";
                                            char* query5 = (char*)malloc(strlen(temp_query5) + 20);

	                                        sprintf(query5, temp_query5, tempname, UserID);

                                            if (mysql_query(conn, query5)) {
                                                fprintf(stderr, "%s\n", mysql_error(conn));
                                                printf("File is not found!\n");
                                                goto USER;
                                            }

                                            res = mysql_use_result(conn);

                                            puts("Results");
                                            puts("________________________________________________________________________________________________________________________________________________");
                                            puts("");
                                            printf("%10s | %10s | %10s | %25s  \n\n", "FileID", "FileName", "FileSize", "ModifyTime");
                                            while ((row = mysql_fetch_row(res)) != NULL)
                                            printf("%10s | %10s | %10s | %25s | \n", row[0], row[1], row[2], row[3]);
                                            puts("_________________________________________________________________________________________________________________________________________________");

                                            free(query5);
                                            mysql_free_result(res);
									

                                            break;
                                        }
                                        continue;
                                    case 6:
                                        while(1){
                                            char tempname[20];
                                            printf("Show a Rearranged MetaData table as...(FileID, FileSize, ModifyTime)> ");
                                            scanf("%s", tempname);

                                            char* temp_query6 = "SELECT * FROM MetaData where UserID = %d ORDER BY %s ; ";
                                            char* query6 = (char*)malloc(strlen(temp_query6) + 20);

                                            sprintf(query6, temp_query6, UserID, tempname);

                                            if (mysql_query(conn, query6)) {
                                                fprintf(stderr, "%s\n", mysql_error(conn));
                                                printf("Type only those three suggested!\n");
                                                goto USER;
                                            }

                                            res = mysql_use_result(conn);

                                            puts("Results");
                                            puts("________________________________________________________________________________________________________________________________________________");
                                            puts("");
                                            printf("%10s | %10s | %10s | %25s  \n\n", "FileID", "FileName", "FileSize", "ModifyTime");
                                            while ((row = mysql_fetch_row(res)) != NULL)
                                            printf("%10s | %10s | %10s | %25s | \n", row[0], row[1], row[2], row[3]);
                                            puts("_________________________________________________________________________________________________________________________________________________");

                                            free(query6);
                                            mysql_free_result(res);
									

                                            break;
                                        }
                                        continue;
                                    case 7:
                                        goto Menu;
                                    
                                }
                            }
                        }
                    }



               }else if(choice == 3){

               }else
               {
                   goto USER;
               }
               
        }
        else if(choice == 3){
            break;
        }
   }


  


}