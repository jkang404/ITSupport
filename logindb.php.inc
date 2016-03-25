            <?php
            class loginDB
            {
            private $db;
            private $ini;
            
                private function saltPassword($password)
            {
                    $salt = $this->ini['loginDB']['salt'];
                    return substr(sha1($password.$salt),10,-10);
            }
            public function __construct($iniFile)
            {
                    $this->ini = parse_ini_file($iniFile,true);
                    $host = $this->ini['loginDB']['host'];
                    $user = $this->ini['loginDB']['user'];
                    $password = $this->ini['loginDB']['password'];
                    $database = $this->ini['loginDB']['database'];
                    $this->db = new mysqli($host,$user,$password,$database);
                    if ($this->db->connect_errno > 0)
                    {
                            echo __FILE__.":".__LINE__.": failed to connect to db, re: ".$this->db->connect_error.PHP_EOL;
                            exit(0);
                    }
            }
            public function __destruct()
            {
                    $this->db->close();
            }
            
            public function checkUserPrivilegeLevel($username)
            {}
            
            public function enableUserAccount($username)
            {}
            public function checkIfUserExists($username)
            {
                    $username = $this->db->real_escape_string($username);
                    $query = "select username from login where username = '$username';";
                    $results = $this->db->query($query);
                    $row = $results->fetch_assoc();
                    if ($row['username'] === $username)
                    {
                            return true;
                    }
                    return false;
            }
            public function validateUser($username,$password)
            {
                    $username = $this->db->real_escape_string($username);
                    $password = $this->db->real_escape_string($this->saltPassword($password));
                    $query = "select username,password from login where username = '$username';";
                    $results = $this->db->query($query);
                    $row = $results->fetch_assoc();
                    if ($row['password'] === $password)
                    {
                            return true;
                    }
                    return false;
            }
            
            public function addNewUser($username,$password,$userRole)
            {
                    if ($this->checkIfUserExists($username) == true)
                    {
                            echo "cannot create new user $username, this user already exists!".PHP_EOL;
                            return;
                    }
                    $username = $this->db->real_escape_string($username);
                    $password = $this->db->real_escape_string($this->saltPassword($password));
                    $userRole = $this->db->real_escape_string($userRole);
                    $query = "insert into login (username,Password,userRole) values('$username','$password','$userRole');";
                    $results = $this->db->query($query);
            echo "$username added".PHP_EOL;
                    if ($this->db->errno > 0)
                    {
                            echo "DB error: ".$this->db->error.PHP_EOL;
                            return;
                    }
            return;
            }
                public function disableUserAccount($username,$password,$userRole)
            {
                if ($this->checkIfUserExists($username) == true)
                    {
                            //echo "cannot create new user $username, this user already exists!".PHP_EOL;
                            //return;
                    
                    $username = $this->db->real_escape_string($username);
                    $password = $this->db->real_escape_string($this->saltPassword($password));
                    $userRole = $this->db->real_escape_string($userRole);
                    $query = "delete from login where username = '$username';";
                    $results = $this->db->query($query);
                    
                    }
                    if ($this->db->errno > 0)
                    {
                            echo "DB error: ".$this->db->error.PHP_EOL;
                            return;
                    }
            
            }
                public function addParts($username,$password,$userRole)
            {
            
            if ($this->checkIfUserExists($username) == true)
                    {
                    echo "Enter part name ".PHP_EOL;
                $handle=fopen("php://stdin","r");
                $line=fgets($handle);
                $partname=trim($line);
            
                    echo "Enter part price  ".PHP_EOL;
                // $handle=fopen("php://stdin","r");
                $line1=fgets($handle);
                $partprice=trim($line1);
                    echo "Enter warehouse ".PHP_EOL;
                    $line2=fgets($handle);
                $warehouse=trim($line2);
                            //return;
                    
                    $username = $this->db->real_escape_string($username);
                    $password = $this->db->real_escape_string($this->saltPassword($password));
                    $userRole = $this->db->real_escape_string($userRole);
                    $partnamee = $this->db->real_escape_string($partname);
                    $partpricee = $this->db->real_escape_string($partprice);
                    $ware = $this->db->real_escape_string($warehouse);
                    $query = "Insert into inventory_db values ('','$partnamee','$partpricee','$ware')";
                    $results = $this->db->query($query);
                    if ($this->db->errno > 0)
                    {
                            echo "DB error: ".$this->db->error.PHP_EOL;
                            return;
                    }
                    }
                    else{echo"Wrong username".PHP_EOL;}
                }

            public function updatepart($username,$password,$userRole)
            {
            
            if ($this->checkIfUserExists($username) == true)
                    {
                    echo "Enter part name ".PHP_EOL;
                $handle=fopen("php://stdin","r");
                $line=fgets($handle);
                $partname=trim($line);
            
                    echo "Enter part price  ".PHP_EOL;
                // $handle=fopen("php://stdin","r");
                $line1=fgets($handle);
                $partprice=trim($line1);
                    echo "Enter warehouse ".PHP_EOL;
                    $line2=fgets($handle);
                $warehouse=trim($line2);
                            //return;
                    
                    $username = $this->db->real_escape_string($username);
                    $password = $this->db->real_escape_string($this->saltPassword($password));
                    $userRole = $this->db->real_escape_string($userRole);
                    $partnamee = $this->db->real_escape_string($partname);
                    $partpricee = $this->db->real_escape_string($partprice);
                    $ware = $this->db->real_escape_string($warehouse);
                    $query = "Update inventory_db set price='$partpricee',warehouse='$ware' where partname='$partname'";
                    $results = $this->db->query($query);
                    if ($this->db->errno > 0)
                    {
                            echo "DB error: ".$this->db->error.PHP_EOL;
                            return;
                    }
            echo"Parts Updated".PHP_EOL;
            }
            else{echo"Wrong username";}
                }


            public function addtocart($username,$password,$userRole)
            {
            
            if ($this->checkIfUserExists($username) == true)
                    {
                    
            
                    
                            //return;
                    $username = $this->db->real_escape_string($username);
                    $password = $this->db->real_escape_string($this->saltPassword($password));
                    $userRole = $this->db->real_escape_string($userRole);
                    //$partnamee = $this->db->real_escape_string($partname);
                    //$partpricee = $this->db->real_escape_string($partprice);
                    //$ware = $this->db->real_escape_string($warehouse);
                    $query = "select * from inventory_db";
                    $results = $this->db->query($query);
            while($list=$results->fetch_assoc())
                    {
                    echo"-----Parts------".PHP_EOL;
                    echo $list['partname'].PHP_EOL;
                    //$i++;
                    }
                    if ($this->db->errno > 0)
                    {
                            echo "DB error: ".$this->db->error.PHP_EOL;
                            return;
                    }
            echo "Enter part name to add to shopping cart".PHP_EOL;
                $handle=fopen("php://stdin","r");
                $line=fgets($handle);
                $partname=trim($line);
            $query = "select * from inventory_db where partname='$partname'";
                    $results = $this->db->query($query);
            while($list2=$results->fetch_assoc())
                    {
            //	echo"-----Parts------".PHP_EOL;
                    $partn=$list2['partname'];
                    $partpric=$list2['price'];
                    $waree=$list2['warehouse'];
                    //$i++;
                    }
            $query3="insert into shoppingcart values('','$partname','$partpric','$waree')";
            $results2=$this->db->query($query3);
            echo"Parts addded to shopping cart".PHP_EOL;
                
            }
            else
            {

            echo"Wrong username".PHP_EOL;
            }

            
        }
        
        public function placeorder($username,$password,$userRole)
            {
            
            if ($this->checkIfUserExists($username) == true)
                    {
                    
            
                    
                            //return;
                    $username = $this->db->real_escape_string($username);
                    $password = $this->db->real_escape_string($this->saltPassword($password));
                    $userRole = $this->db->real_escape_string($userRole);
                    //$partnamee = $this->db->real_escape_string($partname);
                    //$partpricee = $this->db->real_escape_string($partprice);
                    //$ware = $this->db->real_escape_string($warehouse);
                    $query = "select * from shoppingcart";
                    $results = $this->db->query($query);
                    echo"-----CART LIST------".PHP_EOL;
            while($list=$results->fetch_assoc())
                    {
                    
                    echo $list['partname'].PHP_EOL;
                    //$i++;
                    }
                    if ($this->db->errno > 0)
                    {
                            echo "DB error: ".$this->db->error.PHP_EOL;
                            return;
                    }
            echo "Enter part name to place order".PHP_EOL;
                $handle=fopen("php://stdin","r");
                $line=fgets($handle);
                $partname=trim($line);
            $query = "select * from shoppingcart where partname='$partname'";
                    $results = $this->db->query($query);
            while($list2=$results->fetch_assoc())
                    {
            //	echo"-----Parts------".PHP_EOL;
                    $partn=$list2['partname'];
                    $partpric=$list2['price'];
                    $waree=$list2['warehouse'];
                    //$i++;
                    }
            $query3="insert into orderhistory values('','$partname','$partpric','$waree')";
            $results2=$this->db->query($query3);
            $query4="delete from shoppingcart where partname='$partname'";
            $results3=$this->db->query($query4);
            echo"Parts ordered".PHP_EOL;
                
            }
            else
            {
            echo"Wrong username".PHP_EOL;
            }

            
        }
            
        
        
            
            
            public function viewpart($username,$password,$userRole)
            {
            
            if ($this->checkIfUserExists($username) == true)
                    {
                    //return true;
                    
                    $username = $this->db->real_escape_string($username);
                    $password = $this->db->real_escape_string($this->saltPassword($password));
                    $userRole = $this->db->real_escape_string($userRole);
                    $query = "select partname from inventory_db;";
                    $results = $this->db->query($query);
                    //$i=1;
                    while($list=$results->fetch_assoc())
                    {
                    echo"-----Parts------".PHP_EOL;
                    echo $list['partname'].PHP_EOL;
                    //$i++;
                    }
                    if ($this->db->errno > 0)
                    {
                            echo "DB error: ".$this->db->error.PHP_EOL;
                            return;
                    }
                
                    echo"Enter part name to view information".PHP_EOL;
                    $handle=fopen("php://stdin","r");
                    $line=fgets($handle);
                    $partiname=trim($line);
            $query2 = "select * from inventory_db where partname = '$partiname'";
                    $resultss = $this->db->query($query2);
                    //$i=1;
                    while($list2=$resultss->fetch_assoc())
                    {
                    echo"-----Part Information------".PHP_EOL;
                    echo $list2['partname'].PHP_EOL;
                    echo $list2['price'].PHP_EOL;
                    echo $list2['warehouse'].PHP_EOL;
                    //$i++;
                    }
                    if ($this->db->errno > 0)
                    {
                            echo "DB error: ".$this->db->error.PHP_EOL;
                            return;
                    }
                }
                else{echo"Wrong username".PHP_EOL;}
            }
            
            
             public function vieworder($username,$password,$userRole)
            {
            
            if ($this->checkIfUserExists($username) == true)
                    {
                    //return true;
                    
                    $username = $this->db->real_escape_string($username);
                    $password = $this->db->real_escape_string($this->saltPassword($password));
                    $userRole = $this->db->real_escape_string($userRole);
                    $query = "select * from orderhistory;";
                    $results = $this->db->query($query);
                    //$i=1;
                    echo"-----Order History-----".PHP_EOL;
                    while($list=$results->fetch_assoc())
                    {
                    //echo"-----Parts------".PHP_EOL;
                    echo $list['partname'].PHP_EOL;
                    echo $list['price'].PHP_EOL;
                    echo $list['warehouse'].PHP_EOL;
                    echo"\n";
                    //$i++;
                    }
                    if ($this->db->errno > 0)
                    {
                            echo "DB error: ".$this->db->error.PHP_EOL;
                            return;
                    }
                
                    
                }
                else{echo"Wrong username".PHP_EOL;}
            }
            

            

            }
            ?>

