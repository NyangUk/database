
CREATE TABLE professors
(
    prof_id    INT            NOT NULL, 
    prof_name  VARCHAR(45)    NOT NULL, 
    prof_age   INT            NOT NULL, 
    PRIMARY KEY (prof_id),
    INDEX FK_1 (prof_id)
)ENGINE = InnoDB;

CREATE TABLE departments
(
    department_number  INT            NOT NULL, 
    department_name    VARCHAR(45)    NOT NULL, 
    main_office        VARCHAR(45)    NOT NULL, 
    manage_p_id        INT            NOT NULL, 
    PRIMARY KEY (department_number),
    INDEX FK_2 (department_number),
    FOREIGN KEY (manage_p_id) REFERENCES professors(prof_id)
)ENGINE = InnoDB;

CREATE TABLE projects
(
    proj_num            INT            NOT NULL, 
    proj_sponsor_name   VARCHAR(45)    NOT NULL, 
    proj_starting_date  VARCHAR(45)    NOT NULL, 
    proj_budget         INT            NOT NULL, 
    manage_p_id         INT            NOT NULL, 
    PRIMARY KEY (proj_num),
    INDEX FK_3 (proj_num),
    FOREIGN KEY (manage_p_id) REFERENCES professors(prof_id)
)ENGINE = InnoDB;

CREATE TABLE graduate_students
(
    s_id              INT            NOT NULL, 
    s_name            VARCHAR(45)    NOT NULL, 
    s_age             INT            NOT NULL, 
    s_degree_program  VARCHAR(45)    NOT NULL, 
    s_department_num  INT            NOT NULL,
    INDEX FK_4 (s_id),
    PRIMARY KEY (s_id),
    FOREIGN KEY (s_department_num) REFERENCES departments(department_number)
)ENGINE = InnoDB;

CREATE TABLE work_on
(
    project_num   INT             NOT NULL, 
    student_id    INT             NOT NULL, 
    professor_id  INT             NOT NULL, 
    PRIMARY KEY (student_id, professor_id),
    FOREIGN KEY (project_num) REFERENCES projects(proj_num),
    FOREIGN KEY (student_id) REFERENCES graduate_students(s_id),
    FOREIGN KEY (professor_id) REFERENCES professors(prof_id)
)ENGINE = InnoDB;

