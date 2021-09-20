const char DeviceInformation[] PROGMEM = R"=====(
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
    background: url(/footer); 
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

    <body onload="Update_DeviceInfor()">
        <!--navigation-->
        <nav class="navbar navbar-expand-lg navbar-light bg-light">
            <a class="navbar-brand" href="#" style="margin-left: 50px;">
                <img src="/logo_anvgroup">
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
                    <!-- <a class="nav-link" href="#" style="margin-left: 15px; margin-right: 15px;">LogOut</a> -->
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
                    <span><i class="bi bi-bootstrap-fill"> Basic Information</i></span>
                  </div>
                </div>     
              </div>

              <form autocomplete="off" action="#" class="needs-validation" novalidate>
                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="devicename" style="margin-left: 10px;">Device Name</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <input type="text" class="form-control" id="devicename" name="devicename" readonly>
                    </div> 
                  </div>
                </div>

                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="deviceno" style="margin-left: 10px;">Device No.</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <input type="text" class="form-control" id="deviceno" name="deviceno" readonly>
                    </div> 
                  </div>
                </div>

                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="serial" style="margin-left: 10px;">Serial No.</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <input type="text" class="form-control" id="serial" name="serial" readonly>
                    </div> 
                  </div>
                </div>

                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="plugin" style="margin-left: 10px;">Plugin Version</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <input type="text" class="form-control" id="plugin" name="plugin" readonly>
                    </div> 
                  </div>
                </div>

                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="input" style="margin-left: 10px;">Number of Input</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <input type="text" class="form-control" id="input" name="input" readonly>
                    </div> 
                  </div>
                </div>
                
                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="output" style="margin-left: 10px;">Number of Output</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <input type="text" class="form-control" id="output" name="output" readonly>
                    </div> 
                  </div>
                </div>

                <hr>
                <!--<button id="summit_user" type="submit" class="btn btn-primary" style="margin-bottom: 20px;"><i class="bi bi-check2">Save</i></button>  -->
              </form>
            </div>
          </div>
        </div>

        <script>
    var CheckOpen_Infor = 0;
        var WB_Name, WB_Num, WB_Seri, WB_In, WB_Out;
    
    function Update_DeviceInfor()
    {
  console.log("da phan ung chua");
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function()
      {
        if(this.readyState == 4 && this.status == 200)
        {
          var DataVDK_Infor = xhttp.responseText;
          if(DataVDK_Infor) CheckOpen_Infor = 1;
          console.log("Dữ liệu VDK: " + DataVDK_Infor);
          try {
        var DataJsonInfor = JSON.parse(DataVDK_Infor);
        
        if(DataJsonInfor.Name != null && DataJsonInfor.Num != null)
        {
          if(DataJsonInfor.Name != "" && DataJsonInfor.Num != "")
          {
          WB_Name = DataJsonInfor.Name;
          WB_Num =  DataJsonInfor.Num;
          
           $('#devicename').val(WB_Name);
           $('#deviceno').val(WB_Num);
          }  
        }
        if(DataJsonInfor.Seri != null && DataJsonInfor.In != null && DataJsonInfor.Out != null)
        {
           WB_Seri = DataJsonInfor.Seri;
           WB_In = DataJsonInfor.In;
           WB_Out = DataJsonInfor.Out;
           
           $('#serial').val(WB_Seri);
           $('#input').val(WB_In);
           $('#output').val(WB_Out);  
           $('#plugin').val('V1.0');
        }
      
            } catch (e) {
               console.log("Dữ liệu bị fale"); 
            }
          
        }
      }
      console.log("Du lieu checkOpen" + CheckOpen_Infor);
      if(CheckOpen_Infor == 0) {
        xhttp.open("GET", "/ILoadData/DeviceInf?CheckOpen_wb_Inf=" + CheckOpen_Infor, true); 
        xhttp.send();
        setTimeout(function(){ Update_DeviceInfor() }, 1000);
      }  
      
    }
    function logout()
    {
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET","/api/login",false);
      
            xhttp.send(); 
            
    }
          function saveSetting() {
            alert(111)
          }
        </script>
    </body>
</html>
)=====";
