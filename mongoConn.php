<?php
$uri="mongodb://jkang404:jkang404@ds032319.mlab.com:32319/posystem";
try{
$connection =new Mongoclient($uri);
echo"1: Connect to database server successfully".PHP_EOL;
}
catch(MongoConnectionException $e)
{
die('Error connecting to mongodb server'.$e->getMessage());
}

$db = $connection -> posystem;
echo "2: Database posystem selected".PHP_EOL;

$collection = $db -> inventory_db;
echo "3: Collection created successfully".PHP_EOL;


$document = array(
	    "part_id" => 1,
	    "partname" => "mouse",
	    "price" => "$20",
	    "warehouse" => "NYC" );
	    
$collection -> insert($document);

echo "4: Document inserted successfully".PHP_EOL;	  

?>

