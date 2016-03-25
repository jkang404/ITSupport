#!/usr/bin/php
<?php

//require_once("PatientReg.php.inc");
require_once("logindb.php.inc");

function print_help()
{
  echo "usage: ".PHP_EOL;
  echo __FILE__." -u <username> -p <password> -r <userRole>  -c <command arguments...>".PHP_EOL;
}
if ($argc < 2)
{
   print_help();
   exit(0);
}
$cArgs = array();
for ($i = 0; $i < $argc;$i++)
{
  if (($argv[$i] === "-h") ||
      ($argv[$i] === "--help"))
  {
      print_help();
      exit(0);
  }
  if ($argv[$i] === '-u')
  {
    $username = $argv[$i + 1];
    $i++;
    continue;
  }
  if ($argv[$i] === '-p')
  {
    $password = $argv[$i + 1];
    $i++;
    continue;
  }
  if ($argv[$i] === '-r')
  {
    $userRole = $argv[$i + 1];
    $i++;
    continue;
  }
  
  if ($argv[$i] === '-c')
  {
    $command = $argv[$i + 1];
    $i++;
    continue;
  }
  
  $cArgs[] = $argv[$i];  
}
if (!isset($username))
{
   echo "no username specified".PHP_EOL;
   print_help();
   exit(0);
}
if (!isset($password))
{
   echo "no password specified".PHP_EOL;
   print_help();
   exit(0);
}

if (!isset($userRole))
{
   echo "no role specified".PHP_EOL;
   print_help();
   exit(0);
}

if (!isset($command))
{
   echo "no command specified".PHP_EOL;
   print_help();
   exit(0);
}
switch ($command)
{
  case 'addNewUser':
   $login = new loginDB("logindb.ini");
   if ($login->addNewUser($username,$password,$userRole))
   
   {
      echo "$username added".PHP_EOL;
   }
  
   
   break;
case 'addparts':
 $login = new loginDB("logindb.ini");

if($userRole=='manager')
{
   if ($login->addParts($username,$password,$userRole))
   
   {
      echo "Parts added".PHP_EOL;
   }
}
else
{
echo "Only managers are allowed to add parts".PHP_EOL;
}
break;

case 'updatepart':
$login = new loginDB("logindb.ini");
if($userRole=='manager')
{
   if ($login->updatepart($username,$password,$userRole))
   
   {
      echo "Parts Updated".PHP_EOL;
   }
}
else
{
echo "Only managers are allowed to update parts".PHP_EOL;
}
break;
case 'addtocart':
$login = new loginDB("logindb.ini");
$login->addtocart($username,$password,$userRole);
break;

case 'placeorder':
$login = new loginDB("logindb.ini");
$login->placeorder($username,$password,$userRole);
break;
  case 'viewparts':
$login = new loginDB("logindb.ini");
$login->viewpart($username,$password,$userRole);
  break; 
  case 'vieworder':
$login = new loginDB("logindb.ini");
$login->vieworder($username,$password,$userRole);
  break;

   case 'disableUserAccount':
   $login = new loginDB("logindb.ini");
   if ($login->disableUserAccount($username,$password,$userRole))
   
   {
      echo "$username not deleted".PHP_EOL;
   }
   else 
   {
      echo "$username deleted".PHP_EOL;
   }
   break;
  
  case 'validateUser':
   $login = new loginDB("logindb.ini");
   if ($login->validateUser($username,$password))
   
   {
      echo "password validated!!!".PHP_EOL;
   }
   
   else
   {
      echo "password does not validate!".PHP_EOL;
   }
   
   break;
default:
echo"Wrong command".PHP_EOL;
break;
   
}
?>
