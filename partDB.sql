create database if not exists POsystem;
use POsystem;
drop table if exists `inventory_db`;
create table `inventory_db` (
  part_id int(20) primary key auto_increment,
  partname varchar(255),
  price varchar(20),
  warehouse varchar(255)
);


