drop table if exists AccoInfo;
CREATE TABLE `AccoInfo` (
  `id` varchar(10)  NOT NULL,
  `name` varchar(10)  NOT NULL,
  `balance` int NOT NULL,
  PRIMARY KEY (`id`)
);

insert into AccoInfo(id, name, balance) values 
('1001','hundsun', 100),
('1002','hundsun', 100);

drop table if exists AccoCurrent_202211;
CREATE TABLE `AccoCurrent_202211` (
  `id` varchar(10) NOT NULL,
  `amount` int NOT NULL,
  `time` varchar(11) NOT NULL
);

insert into AccoCurrent_202211 values
('1001', 100, '20221101'), 
('1001', 200, '20221102'), 
('1002', 100, '20221101'), 
('1002', 200, '20221102'); 

drop table if exists AccoCurrent_202212;
CREATE TABLE `AccoCurrent_202212` (
  `id` varchar(10) NOT NULL,
  `amount` int NOT NULL,
  `time` varchar(11) NOT NULL
);

insert into AccoCurrent_202212 values
('1001', 100, '20221201'),
('1001', 200, '20221202'),
('1002', 100, '20221201'),
('1002', 200, '20221202');
