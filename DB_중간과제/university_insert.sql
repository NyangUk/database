-- professor 추가
-- INSERT into professors(prof_id,prof_name,prof_age) values(1,'송희선',42);
-- INSERT into professors(prof_id,prof_name,prof_age) values(2,'인정환',48);
-- INSERT into professors(prof_id,prof_name,prof_age) values(3,'김지훈',50);
-- INSERT into professors(prof_id,prof_name,prof_age) values(4,'윤지훈',31);
-- INSERT into professors(prof_id,prof_name,prof_age) values(5,'조영선',33);
-- INSERT into professors(prof_id,prof_name,prof_age) values(6,'김보혜',45);
-- INSERT into professors(prof_id,prof_name,prof_age) values(7,'김태훈',51);
-- INSERT into professors(prof_id,prof_name,prof_age) values(8,'김지욱',43);

-- department 추가
-- INSERT into departments(department_number,department_name,main_office,manage_p_id) values(1,'전자공학',808,1);
-- INSERT into departments(department_number,department_name,main_office,manage_p_id) values(2,'화학공학',203,2);
-- INSERT into departments(department_number,department_name,main_office,manage_p_id)  values(3,'기계공학',423,4);

-- graduatestudent 추가
-- INSERT into graduate_students(s_id,s_name,s_age,s_degree_program,s_department_num) values(1,'박아리엘',23,'반도체',1);
-- INSERT into graduate_students(s_id,s_name,s_age,s_degree_program,s_department_num) values(2,'박현빈',26,'역학',2);
-- INSERT into graduate_students(s_id,s_name,s_age,s_degree_program,s_department_num) values(3,'이은성',23,'컴퓨터',3);
-- INSERT into graduate_students(s_id,s_name,s_age,s_degree_program,s_department_num) values(4,'김재욱',22,'컴퓨터',1);
-- INSERT into graduate_students(s_id,s_name,s_age,s_degree_program,s_department_num) values(5,'김수연',22,'통신',1);
-- INSERT into graduate_students(s_id,s_name,s_age,s_degree_program,s_department_num) values(6,'이주호',23,'관리',2);
-- INSERT into graduate_students(s_id,s_name,s_age,s_degree_program,s_department_num) values(7,'박동현',25,'열전달',3);
-- INSERT into graduate_students(s_id,s_name,s_age,s_degree_program,s_department_num) values(8,'황훈',28,'공정',3);
-- INSERT into graduate_students(s_id,s_name,s_age,s_degree_program,s_department_num) values(9,'김수지',22,'역학',2);

-- project 추가
-- INSERT into projects(proj_num,proj_sponsor_name,proj_starting_date,proj_budget,manage_p_id) values(1,'삼성전자',"2019-01-23",4200000,1);
-- INSERT into projects(proj_num,proj_sponsor_name,proj_starting_date,proj_budget,manage_p_id) values(2,'현대자동차',"2017-11-26",9800000,4);
-- INSERT into projects(proj_num,proj_sponsor_name,proj_starting_date,proj_budget,manage_p_id) values(3,'LG디스플레이',"2019-12-18",121000000,4);
-- INSERT into projects(proj_num,proj_sponsor_name,proj_starting_date,proj_budget,manage_p_id) values(4,'SK디스플레이',"2018-03-23",55000000,2);
-- INSERT into projects(proj_num,proj_sponsor_name,proj_starting_date,proj_budget,manage_p_id) values(5,'기아자동차',"2016-07-15",41000000,8);
-- professor 추가

-- Work_on(S) 추가
-- INSERT into work_on(project_num,student_id,professor_id) values(1,4,1);
-- INSERT into work_on(project_num,student_id,professor_id) values(1,2,1);
-- INSERT into work_on(project_num,student_id,professor_id) values(2,2,4);
-- INSERT into work_on(project_num,student_id,professor_id) values(2,1,4);
-- INSERT into work_on(project_num,student_id,professor_id) values(3,6,4);
-- INSERT into work_on(project_num,student_id,professor_id) values(4,8,2);
-- INSERT into work_on(project_num,student_id,professor_id) values(4,3,2);
-- INSERT into work_on(project_num,student_id,professor_id) values(4,6,2);
-- INSERT into work_on(project_num,student_id,professor_id) values(5,8,8);
-- INSERT into work_on(project_num,student_id,professor_id) values(5,4,8);

