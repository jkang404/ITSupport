create database if not exists POsystem;
use POsystem;
drop table if exists `login`;
create table `login` (
  login int(20) primary key auto_increment,
  Password varchar(255),
  username varchar(255),
  userRole varchar(255),
  dispalyName varchar(30));

drop table if exists `shoppingcart`;
create table `shoppingcart` (
  cart_id int(20) primary key auto_increment,
  partname varchar(255),
  price varchar(255),
  warehouse varchar(255)
  
);


drop table if exists `orderhistory`;
create table `orderhistory` (
  order_id int(20) primary key auto_increment,
  partname varchar(255),
  price varchar(255),
  warehouse varchar(255)
  
);
