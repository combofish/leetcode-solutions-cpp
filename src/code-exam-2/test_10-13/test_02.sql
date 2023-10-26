DROP TABLE IF EXISTS Employee;
CREATE TABLE Employee (
Eno int NOT NULL, 
Ename varchar(255) DEFAULT NULL,
Esex varchar(255) NOT NULL, 
Eage int DEFAULT NULL,
Edept varchar(255) DEFAULT NULL, 
PRIMARY KEY (Eno)
);
INSERT INTO Employee VALUES ('1', '张三', '男', '32', '部门A');
INSERT INTO Employee VALUES ('2', '李四', '男', '26', '部门B');
INSERT INTO Employee VALUES ('3', '王五', '男', '28', '部门A');
INSERT INTO Employee VALUES ('4', '赵七', '男', '29', '部门A');
INSERT INTO Employee VALUES ('5', '周六', '女', '30', '部门C');
DROP TABLE IF EXISTS Course;
CREATE TABLE Course (
CNo varchar(255) NOT NULL,
Cname varchar(255) DEFAULT NULL, 
Ccredit int DEFAULT NULL,
PRIMARY KEY (CNo)
);
INSERT INTO Course VALUES ('001', '数据库', '10');
INSERT INTO Course VALUES ('002', '计算机基础', '10');
INSERT INTO Course VALUES ('003', '金融基础', '20');
INSERT INTO Course VALUES ('004', '投资基础', '10');
DROP TABLE IF EXISTS SC;
CREATE TABLE SC (
Eno int NOT NULL,
CNo varchar(255) DEFAULT NULL,
Grade int DEFAULT NULL,  PRIMARY KEY (Eno)
) ;
INSERT INTO SC VALUES ('1', '001', '60');
INSERT INTO SC VALUES ('2', '001', '80');
INSERT INTO SC VALUES ('3', '001', '86');
INSERT INTO SC VALUES ('4', '001', '88');
INSERT INTO SC VALUES ('5', '001', '86');
