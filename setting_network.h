const char SettingNetwork[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>ANV Group</title>
        <!------------------->

        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">
        <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.3/css/all.min.css"/>

        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>

        <script src="https://cdnjs.cloudflare.com/ajax/libs/i18next/1.11.1/i18next.min.js"></script>
       

        <style>
          @media screen {
html, body{
    width: 100%;
    height: 100%;
    font-family: sans-serif;
    font-size: 17px;
    color: #222;
}

body::-webkit-scrollbar {
    display: none;
}

.navbar{
    background-color: #0056a6 !important;
}
.navbar ul {
    margin-left: 0;
}
.navbar li a {
    color: #fff !important;
}
.navbar li a:hover {
    color: #ff0 !important;
}
.iframe_x {
    height: 600px;
    width: 100%;
}
.footer {
    position: absolute;
    background: url(http://control.local/footer); 
    width: 100%;  
    height: 120px; 
    text-align: center; 
    color: #fff; 
    font-family: 'RobotoCondensed-Light'; 
    font-size: 15px;
    border-top: 5px solid #333;
    font-weight: bold;
    
}

/*vertical*/
.content_system {
    height: 600px;
    
    padding: 0;
    margin: 0;
}
.main-nav ul{
  padding: 0;
}
.main-nav li {
  list-style: none;
}
.main-nav a {
  text-decoration: none;
  
  display: block;
  color: #fff;
 
  padding: 5px 0px 5px 10px;
  border-bottom: 1px solid white;
}
.main-nav a:hover{
  background-color: yellow;
}
.main-nav {
  background-color: #0056a6;
  margin: 5px;
}    
.main-nav-ul ul{
  display: none;
}
.main-nav-ul li:hover ul {
  display: block;
}
.main-nav-ul li ul li a{
  margin-left: 10px;
}

.table tbody tr.highlight td {
  background-color: #ddd;
}

}
        </style>
    </head>

    <body onload="UpdateData_Network()">
        <!--navigation-->
        <nav class="navbar navbar-expand-lg navbar-light bg-light">
            <a class="navbar-brand" href="#" style="margin-left: 50px;">
                <img src="/logo_anvil">
            </a>
          
            <div class="xnav_ngang">
              <ul class="navbar-nav mr-auto">
                <li class="nav-item active" style="margin-left: 15px; margin-right: 15px;">
                  <a class="nav-link" href="#" target="iframe_a">Home</a>
                </li>
                <li class="nav-item">
                  <a class="nav-link" href="/api/control"  target="iframe_a" style="margin-left: 15px; margin-right: 15px;">User Interface</a>
                </li>
               <li class="nav-item">
                   <a class="nav-link" onclick="logout()" href="/api/login" style="margin-left: 15px; margin-right: 15px;">LogOut</a>
               </li> 
                 
              </ul>
            </div>
        </nav>

        <div class="content_system">
          <div class="row">
            <div class="col-md-2 col-sm-2 col-xs-2" style="border-right: 2px double gray; margin-top: 5px;">
              <nav class="main-nav" id="menu_doc">
                <ul class="main-nav-ul">
                  <li><a href="/api/config/resistor">Config Resistor</a></li>
                  <li><a href="/api/system/Network">Network</a></li>
                  <li><a href="/api/system/usermanerment">User management</a></li>
                  <li><a href="/api/system/infor">Device Information</a></li>
                  <li><a href="/api/system/timezone">Time zone</a></li>
                </ul>
              </nav>
            </div>

            <div class="col-md-10 col-sm-10 com-xs-10">
              <div class="title_use_manament" style="margin: 20px; border-bottom: 2px solid gray; font-size: 17px">
                <div class="row">
                  <div class="col-md-9 col-sm-9 com-xs-9">
                    <span><i class="bi bi-gear">Setting</i></span>
                  </div>
                </div>     
              </div>

              <form autocomplete="off" action="#" class="needs-validation" novalidate>
                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="nic" style="margin: 10px;">NIC Type</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <select class="form-control" id="nic">
                        <option>Auto</option>
                        <option>10M Half-dup</option>
                        <option>10M Full-dup</option>
                        <option>100M Half-dup</option>
            <option>100M Full-dup</option>
                      </select>
                    </div>
                  </div>
                </div>

                <div class="form-group form-check">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12"></div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <label class="form-check-label" style="margin-left: 10px;">
                        <input class="form-check-input" type="checkbox" id="uhdcp" name="remember">DHCP
                      </label>
                    </div> 
                  </div>
                </div>

                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="ipv4address" style="margin: 10px;">IPv4 Address</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <input type="text" class="form-control" id="ipv4address" name="ipv4address">
                    </div> 
                  </div>
                </div>
                
                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="ipv4subnet" style="margin: 10px;">IPv4 Subnet Mask</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <input type="text" class="form-control" id="ipv4subnet" name="ipv4subnet">
                    </div> 
                  </div>
                </div>

                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="ipv4gateway" style="margin-left: 10px;">IPv4 Default Gateway</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <input type="text" class="form-control" id="ipv4gateway" name="ipv4gateway">
                    </div> 
                  </div>
                </div>
               
                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="serverport" style="margin-left: 10px;">Server Port</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <input type="text" class="form-control" id="serverport" name="serverport">
                    </div> 
                  </div>
                </div>

                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="macaddress" style="margin-left: 10px;">Mac Address</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <input type="text" class="form-control" id="macaddress" name="macaddress" readonly>
                    </div> 
                  </div>
                </div>

                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="dnsserver" style="margin-left: 10px;">DNS Server</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <input type="text" class="form-control" id="dnsserver" name="dnsserver" readonly>
                    </div> 
                  </div>
                </div>

                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="pref" style="margin-left: 10px;">Preferred DNS Server</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <input type="text" class="form-control" id="pref" name="pref">
                    </div> 
                  </div>
                </div>
                <hr>
                <button id="summit_user" type="submit" onclick="saveSetting()" class="btn btn-primary" style="margin-bottom: 20px;"><i class="bi bi-check2">Save</i></button>
              </form>
            </div>
          </div>
        </div>

        <script>
    var CheckOpen_NetWk = 0;
    var U_IPv4Add, U_IPv4Subnet, U_IPv4Gateway, U_IPv4ServerPort, U_Macdress, U_DNSServer, U_PreDNS;
    function UpdateData_Network()
    {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function()
      {
        if(this.readyState == 4 && this.status == 200)
        {
           var DataVDK_NetWk = xhttp.responseText;
           if(DataVDK_NetWk) CheckOpen_NetWk = 1;
           console.log("Dữ liệu VDK: " + DataVDK_NetWk);
           try {
            var DataJsonNetWk = JSON.parse(DataVDK_NetWk);
            
            if(DataJsonNetWk.IP != null && DataJsonNetWk.Subnet != null)
            {
              U_IPv4Add = DataJsonNetWk.IP;
              U_IPv4Subnet = DataJsonNetWk.Subnet;
              <!-- dau Dl vao -->
              $('#ipv4address').val(U_IPv4Add);
              $('#ipv4subnet').val(U_IPv4Subnet);
            }
            if(DataJsonNetWk.Gateway != null && DataJsonNetWk.SerPort != null)
            {
              U_IPv4Gateway = DataJsonNetWk.Gateway;
              U_IPv4ServerPort = DataJsonNetWk.SerPort;
              $('#ipv4gateway').val(U_IPv4Gateway);
              $('#serverport').val(U_IPv4ServerPort);
               
            }
            
            if(DataJsonNetWk.Mac != null && DataJsonNetWk.DNS != null && DataJsonNetWk.preDNS != null)
            {
              U_Macdress = DataJsonNetWk.Mac;
              U_DNSServer = DataJsonNetWk.DNS;
              U_PreDNS = DataJsonNetWk.preDNS; 
        
              $('#macaddress').val(U_Macdress);
              $('#dnsserver').val(U_DNSServer);
              $('#pref').val(U_PreDNS);
              
            } 
             
          } catch (e) {
             console.log("Dữ liệu bị fale"); 
          }
        }
      
      }
      console.log("Du lieu checkOpen Network: " + CheckOpen_NetWk);
      if(CheckOpen_NetWk == 0) {
        xhttp.open("GET", "/NetWkLoadData/Network?CheckOpen_wb_NetWk=" + CheckOpen_NetWk, true); 
        xhttp.send();
        setTimeout(function(){ UpdateData_Network() }, 1000);
      }  
      
    }

    function logout()
    {
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/api/login",false);
      
            xhttp.send(); 
            
    }
        function saveSetting() {
            event.preventDefault();
            console.log("Da phan ung !!!");
      var IPv4_AddToVDK = document.getElementById("ipv4address").value;
      var IPv4_SubnetToVDK = document.getElementById("ipv4subnet").value;
      var IPv4_GatewayToVDK = document.getElementById("ipv4gateway").value;
     // var IPv4_ServerPortToVDK = document.getElementById("serverport").value;
      
     // var DNS_ServerToVDK = document.getElementById("dnsserver").value;
    //  var Preferred_DNSToVDK = document.getElementById("pref").value;
            console.log("IPv4_Sent: " + IPv4_AddToVDK);
            console.log("IPv4_Subnet: " + IPv4_SubnetToVDK);
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/api/setting/network?IPv4_Add_Wb="+IPv4_AddToVDK+"&IPv4_Sub_Wb="+IPv4_SubnetToVDK+"&IPv4_Gate_Wb="+IPv4_GatewayToVDK,true);
      
            xhttp.send(); 
            alert("You Send Ip Successfull");
            
        }
        </script>
    </body>
</html>
)=====";
