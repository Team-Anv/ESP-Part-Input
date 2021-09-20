const char UserManerment[] PROGMEM = R"=====(
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
    overflow: hidden;
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

    <body onload="UpdateData_user()">
        <!--navigation-->
        <nav class="navbar navbar-expand-lg navbar-light bg-light">
            <a class="navbar-brand" href="#" style="margin-left: 50px;">
                <img src="/logo_anvgroup">
            </a>
          
            <div class="xnav_ngang">
              <ul class="navbar-nav mr-auto">
                <li class="nav-item" style="margin-left: 15px; margin-right: 15px;">
                  <a class="nav-link" href="#" target="iframe_a">Home</a>
                </li>
                <li class="nav-item active">
                  <a class="nav-link" href="/api/control"  target="iframe_a" style="margin-left: 15px; margin-right: 15px;">User Interface</a>
                </li>
                <li class="nav-item">
                    <!-- <a class="nav-link" href="/api/login" style="margin-left: 15px; margin-right: 15px;">LogOut</a> -->
                    <a class="nav-link" onclick="logout()" href=" " style="margin-left: 15px; margin-right: 15px;">LogOut</a>
                  </li>
              </ul>
            </div>
        </nav>

        <div class="content_system">
          <div class="row">
            <div class="col-md-2 col-sm-2 col-xs-2" style="margin-top: 5px;">
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
      
      <!-- bat su kien cho 3 su kien Add/modify/Delete khi nhan vao cac nut  -->
      
            <div class="col-md-10 col-sm-10 com-xs-10" style="border-left: 2px double gray; ">
              <div class="title_use_manament" style="margin: 20px; border-bottom: 2px solid gray; font-size: 17px">
                <div class="row">
                  <div class="col-md-9 col-sm-9 com-xs-9">
                    <span><i class="bi bi-person-badge-fill">User management</i></span>
                  </div>
                  <div class="col-md-1 col-sm-1 com-xs-1">
                    <button type="button" class="btn-primary" onclick="loadAdd()" data-toggle="modal" data-target="#addModal" style="width: 70px; margin-left: -20px;">Add</button>
                  </div>
                  <div class="col-md-1 col-sm-1 com-xs-1">
                    <button id="id_modify" type="button" onclick="loadModify()" class="btn-primary" style="width: 70px; margin-left: -20px;">Modify</button>
                  </div>
                  <div class="col-md-1 col-sm-1 com-xs-1">
                    <button type="button" class="btn-danger" onclick="deleteRowUser()" style="width: 70px; margin-left: -20px;">Delete</button>
                  </div>
                </div>     
              </div>

              <table id="infoTable" class="table table-fixed table-condensed">
                <thead>
                  <tr>
                    <th class="col-xs-3">No.</th>
                    <th class="col-xs-3">User</th>
                    <th class="col-xs-6">Level</th>
                    <th class="col-xs-0" style="display: none;">Pass</th>
                  </tr>
                </thead>
                <tbody>
                  
                </tbody>
              </table>

            </div>
          </div>
        </div>

        <!-- Modal: add user -->
        <div class="modal fade right" id="addModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel"
        aria-hidden="true" data-backdrop="false">
          <div class="modal-dialog modal-full-height modal-right modal-notify modal-info" role="document">
            <div class="modal-content">
              <!--Header-->
              <div class="modal-header">
                <span style="margin-left: 10px; font-size: 20px; font-weight: bold;"><i>Add user</i></span>
                <button type="button" class="close" data-dismiss="modal" aria-label="Close" style="margin-right: 10px;">
                  <span aria-hidden="true" class="white-text">×</span>
                </button>
              </div>
        
        <!-- day la the Add user  ---->
        
              <!--Body-->
              <div class="modal-body">
                <form autocomplete="off" action="#" class="needs-validation" novalidate>
                  <div class="form-group">
                    <div class="row">
                      <div class="col-md-3 col-ms-3 col-xs-12">
                        <label for="uname" style="margin: 10px;">Username:</label>
                      </div>
                      <div class="col-md-8 col-ms-8 col-xs-12">
            
            <!-- day la the Input user lay id o day ---->
            
                        <input type="text" class="form-control" id="uname" placeholder="Enter username" name="uname">
                        <div class="registrationFormAlert" id="CheckUser"></div>
                      </div> 
                    </div>
                  </div>
                  <div class="form-group form-check">
                    <div class="row">
                      <div class="col-md-3 col-ms-3 col-xs-12"></div>
                      <div class="col-md-8 col-ms-8 col-xs-12">
                        <label class="form-check-label" style="margin-left: 10px;">
                          <input class="form-check-input" type="checkbox" id="uadmin" name="remember"> Admin
                        </label>
                      </div> 
                    </div>
                    
                  </div>
                  <div class="form-group">
                    <div class="row">
                      <div class="col-md-3 col-ms-3 col-xs-12">
                        <label for="pwd" style="margin: 10px;">Password:</label>
                      </div>
                      <div class="col-md-8 col-ms-8 col-xs-12">
            
             <!-- day la the Input Pass lay id o day ---->
             
                        <input type="password" class="form-control" id="pwd" placeholder="Enter password" name="pswd">
                        <div class="registrationFormAlert" id="CheckPassword"></div>
                      </div> 
                    </div>
                  </div>

                  <div class="form-group">
                    <div class="row">
                      <div class="col-md-3 col-ms-3 col-xs-12">
                        <label for="pwd_confirm" style="margin: 10px;">Confirm:</label>
                      </div>
                      <div class="col-md-8 col-ms-8 col-xs-12">
                        <input type="password" class="form-control" id="pwd_confirm" placeholder="Enter password" name="pswd" onchange="checkConfirmPass()">
                        <div class="registrationFormAlert" id="CheckPasswordMatch"></div>
                      </div> 
                    </div>
                  </div>
                  <hr>
          
          <!-- ************************************************************************************************  -->
          <!-- sư kien submit o day --> 
          
           <!-- ************************************************************************************************  -->
                  <button id="summit_user" onclick="submit_UserESP()" type="submit" class="btn btn-primary" style="float: right;"><i class="bi bi-check2">Submit</i></button>
                </form>
                
                <script>
                // Disable form submissions if there are invalid fields khi click nut Add
        
                function loadAdd(){
                  $('#uname').val('');
                  $('#uadmin').checked = false;
                  $('#pwd').val('');
                  $('#pwd_confirm').val('');
                  document.getElementById('CheckPasswordMatch').innerHTML = "";
                  document.getElementById('CheckPassword').innerHTML = "";
                  document.getElementById('CheckUser').innerHTML = "";
                }

                function checkConfirmPass(){ 
                  var pass = $("#pwd").val();
                  var pass_comfirm = $("#pwd_confirm").val();
                    if (pass != pass_comfirm){
                      document.getElementById('CheckPasswordMatch').innerHTML = "Passwords do not match.";
                      document.getElementById('CheckPasswordMatch').style.color="red";
                    }
                    else
                      document.getElementById('CheckPasswordMatch').innerHTML = "";
                }
                </script>
              </div>
            </div>
          </div>
        </div>

        <!--**********************************************modifyModal****************************************************************-->
        <div class="modal fade right" id="modifyModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel"
        aria-hidden="true" data-backdrop="false">
          <div class="modal-dialog modal-full-height modal-right modal-notify modal-info" role="document">
            <div class="modal-content">
              <!--Header-->
              <div class="modal-header">
                <span style="margin-left: 10px; font-size: 20px; font-weight: bold;"><i>Modify user</i></span>
                <button type="button" class="close" data-dismiss="modal" aria-label="Close" style="margin-right: 10px;">
                  <span aria-hidden="true" class="white-text">×</span>
                </button>
              </div>

              <!--Body-->
              <div class="modal-body">
                <form autocomplete="off" action="#" class="needs-validation" novalidate>
                  <div class="form-group">
                    <div class="row">
                      <div class="col-md-3 col-ms-3 col-xs-12">
                        <label for="uname" style="margin: 10px;">Username:</label>
                      </div>
                      <div class="col-md-8 col-ms-8 col-xs-12">
                        <input type="text" class="form-control" id="uname2" placeholder="Enter username" name="uname">
                        <div class="registrationFormAlert" id="CheckUser2"></div>
                      </div> 
                    </div>
                  </div>
                  <div class="form-group form-check">
                    <div class="row">
                      <div class="col-md-3 col-ms-3 col-xs-12"></div>
                      <div class="col-md-8 col-ms-8 col-xs-12">
                        <label class="form-check-label" style="margin-left: 10px;">
                          <input class="form-check-input" type="checkbox" id="uadmin2" name="remember"> Admin
                        </label>
                      </div> 
                    </div>
                    
                  </div>
                  <div class="form-group">
                    <div class="row">
                      <div class="col-md-3 col-ms-3 col-xs-12">
                        <label for="pwd" style="margin: 10px;">Password:</label>
                      </div>
                      <div class="col-md-8 col-ms-8 col-xs-12">
                        <input type="password" class="form-control" id="pwd2" placeholder="Enter password" name="pswd">
                        <div class="registrationFormAlert" id="CheckPassword2"></div>
                      </div> 
                    </div>
                  </div>

                  <div class="form-group">
                    <div class="row">
                      <div class="col-md-3 col-ms-3 col-xs-12">
                        <label for="pwd_confirm" style="margin: 10px;">Confirm:</label>
                      </div>
                      <div class="col-md-8 col-ms-8 col-xs-12">
                        <input type="password" class="form-control" id="pwd_confirm2" placeholder="Enter password" name="pswd" onchange="checkConfirmPass2()">
                        <div class="registrationFormAlert" id="CheckPasswordMatch2"></div>
                      </div> 
                    </div>
                  </div>
                  <hr>
                  <input type="text" id="id_user" style="display: none;"></input>
          <!--**********************Bat su kien modifyModal o day****************************************************************-->
                  <button id="summit_user2" onclick="modify_submit()" type="submit" class="btn btn-primary" style="float: right;"><i class="bi bi-check2">Submit</i></button>
                </form>
                
                <script>
                // Disable form submissions if there are invalid fields
                

                function checkConfirmPass2(){ 
                  var pass = $("#pwd2").val();
                  var pass_comfirm = $("#pwd_confirm2").val();
                    if (pass != pass_comfirm){
                      document.getElementById('CheckPasswordMatch2').innerHTML = "Passwords do not match.";
                      document.getElementById('CheckPasswordMatch2').style.color="red";
                    }
                    else
                      document.getElementById('CheckPasswordMatch2').innerHTML = "";
                }
                </script>
              </div>
            </div>
          </div>
        </div>

        <div class="footer">
            <br/>
             Copyright © ANVGroup | Control Center. All rights reserved
        </div>

        <script>
     <!-- viet code cho phan back_end -->
    
    var checkOpen = 0;
      function UpdateData_user()
      {
       var xhttp = new XMLHttpRequest();
       
        xhttp.onreadystatechange = function()
         {
        if(this.readyState == 4 && this.status == 200)
        {
           var DataVDK = xhttp.responseText;
           console.log(DataVDK);
           if (DataVDK) checkOpen = 1;
          <!-- try catch bat json dung sai dat trong nay -->
          try {
            var DataJsonUser = JSON.parse(DataVDK);
            
            if((DataJsonUser.user1 != null) && (DataJsonUser.pass1 != null))
            {
              if(DataJsonUser.user1 !="")
              {
                var vdkUser1 = DataJsonUser.user1;
                var vdkPass1 = DataJsonUser.pass1;
              
                if(vdkUser1 == "admin")
                   $("#infoTable > tbody").append("<tr><td>"+ ($('#infoTable')[0].rows.length) +"</td><td>"+ vdkUser1 +"</td><td>"+ "Admin" +"</td><td>" + "" + "</td></tr>");
                else $("#infoTable > tbody").append("<tr><td>"+ ($('#infoTable')[0].rows.length) +"</td><td>"+ vdkUser1 +"</td><td>"+ "User" +"</td><td>" + "" + "</td></tr>");
              } 
            }
            
            if((DataJsonUser.user2 != null) && (DataJsonUser.pass2 != null))
            {
              if(DataJsonUser.user2 !="")
              {
                var vdkUser2 = DataJsonUser.user2;
                var vdkPass2 = DataJsonUser.pass2;
                if(vdkUser2 == "admin")
                   $("#infoTable > tbody").append("<tr><td>"+ ($('#infoTable')[0].rows.length) +"</td><td>"+ vdkUser2 +"</td><td>"+ "Admin" +"</td><td>" + "" + "</td></tr>");
                else $("#infoTable > tbody").append("<tr><td>"+ ($('#infoTable')[0].rows.length) +"</td><td>"+ vdkUser2 +"</td><td>"+ "User" +"</td><td>" + "" + "</td></tr>");
              }
            }
            if((DataJsonUser.user3 != null) && (DataJsonUser.pass3 != null))
            {
              if(DataJsonUser.user3 !="")
              {
                var vdkUser3 = DataJsonUser.user3;
                var vdkPass3 = DataJsonUser.pass3;
                if(vdkUser3 == "admin")
                   $("#infoTable > tbody").append("<tr><td>"+ ($('#infoTable')[0].rows.length) +"</td><td>"+ vdkUser3 +"</td><td>"+ "Admin" +"</td><td>" + "" + "</td></tr>");
                else $("#infoTable > tbody").append("<tr><td>"+ ($('#infoTable')[0].rows.length) +"</td><td>"+ vdkUser3 +"</td><td>"+ "User" +"</td><td>" + "" + "</td></tr>");
              }
              
            }
            if((DataJsonUser.user4 != null) && (DataJsonUser.pass4 != null))
            {
              if(DataJsonUser.user4 !="")
              {
                var vdkUser4 = DataJsonUser.user4;
                var vdkPass4 = DataJsonUser.pass4;
                if(vdkUser4 == "admin")
                   $("#infoTable > tbody").append("<tr><td>"+ ($('#infoTable')[0].rows.length) +"</td><td>"+ vdkUser4 +"</td><td>"+ "Admin" +"</td><td>" + "" + "</td></tr>");
                else $("#infoTable > tbody").append("<tr><td>"+ ($('#infoTable')[0].rows.length) +"</td><td>"+ vdkUser4 +"</td><td>"+ "User" +"</td><td>" + "" + "</td></tr>");
              }
              
            }
            if((DataJsonUser.user5 != null) && (DataJsonUser.pass5 != null))
            {
                if(DataJsonUser.user5 !="")
              {
                var vdkUser5 = DataJsonUser.user5;
                var vdkPass5 = DataJsonUser.pass5;
                if(vdkUser4 == "admin")
                   $("#infoTable > tbody").append("<tr><td>"+ ($('#infoTable')[0].rows.length) +"</td><td>"+ vdkUser5 +"</td><td>"+ "Admin" +"</td><td>" + "" + "</td></tr>");
                else $("#infoTable > tbody").append("<tr><td>"+ ($('#infoTable')[0].rows.length) +"</td><td>"+ vdkUser5 +"</td><td>"+ "User" +"</td><td>" + "" + "</td></tr>");
              }
            }
                 
          } catch (e) {
            console.log("Dữ liệu bị fale");
            
          }
        }
      }
        console.log(checkOpen + 'CheckOpen');
      if (checkOpen == 0){
        xhttp.open("GET","/U_LoadData/user?checkOpen=" + checkOpen, true);
        xhttp.send();
        setTimeout(function(){ UpdateData_user()}, 1000);
      }
         
        }
    
    var id_user_wb1 = 0; <!-- biet xem user thu bao nhieu -->
    
    function submit_UserESP(){
    console.log("id_user_wb1 submit: " + id_user_wb1);
    if(id_user_wb1<6)
    {
       var DataUser_wb1 = document.getElementById("uname").value; 
        var DataPass_wb1 = document.getElementById("pwd").value; 
        
        var xhttp = new XMLHttpRequest();
      
        xhttp.open("GET","/api/setting/account?id_user_wb=" + id_user_wb1 + "&DataUser_wb=" + DataUser_wb1 + "&DataPass_wb=" + DataPass_wb1, true);
        xhttp.send();
    }  
    }
    
    function loadAdd(){
       console.log("da nhay vao all Load");
       id_user_wb1 = $('#infoTable')[0].rows.length;
     if(id_user_wb1 >5)
     {
        var CheckNumberUser = confirm("ban da vuot qua so luong user");
      return;
     }
    
     console.log("Id_user: " + id_user_wb1);
    }
  
    <!-- END ---->
          // click able row
          $('#infoTable').on('click', 'tbody tr', function(event) {
            $(this).addClass('highlight').siblings().removeClass('highlight');
          });

          //click add khi bam submit
          $('#summit_user').click(function(event){
          
            event.preventDefault();
            if($('#infoTable')[0].rows.length < 6)
      {
      var table1 = document.getElementById("infoTable");   
        var check_user = 0;

        //check user null
        if ($('#uname').val() == ''){
          document.getElementById('CheckUser').innerHTML = "User name is null.";
          document.getElementById('CheckUser').style.color="red";
          return;
        }
        else
          document.getElementById('CheckUser').innerHTML = "";
        //check pass null
        if ($('#pwd').val() == ''){
          document.getElementById('CheckPassword').innerHTML = "Password is null.";
          document.getElementById('CheckPassword').style.color="red";
          return;
        }
        else
          document.getElementById('CheckPassword').innerHTML = "";


        if ($('#uname').val() == '' || $('#pwd').val() == '' || $('#pwd_confirm').val() == '') return;
        if ($('#pwd').val() != $('#pwd_confirm').val()) return;
      
        
      if (table1.rows.length == 1){
        $("#infoTable > tbody").append("<tr><td>"+ table1.rows.length +"</td><td>"+ $('#uname').val() +"</td><td>"+ ($('#uadmin')[0].checked == true ? 'Admin' : 'User') +"</td><td>" + $('#pwd').val() + "</td></tr>");
        $('#infoTable')[0].rows[1].cells[3].style.display = "none";
        $('#addModal').modal('hide');
      } else {
        for (var i = 2; i <= table1.rows.length; i++){
        if ($('#infoTable')[0].rows[i-1].cells[1].innerHTML == $('#uname').val()){
        check_user = 1;
        break;
        } 
        }

        if (check_user != 1){
        $("#infoTable > tbody").append("<tr><td>"+ (table1.rows.length) +"</td><td>"+ $('#uname').val() +"</td><td>"+ ($('#uadmin')[0].checked == true ? 'Admin' : 'User') +"</td><td>" + $('#pwd').val() + "</td></tr>");
        $('#infoTable')[0].rows[i-1].cells[3].style.display = "none";
        $('#addModal').modal('hide');
        }
      } 
      }
      else {
        alert("Da vuot qua so user");
      return;
      } 
          });

          //load modify
          // button modify khi bam submit
          $('#summit_user2').click(function(event){
            event.preventDefault();
      
            var table1 = document.getElementById("infoTable");   
            //check user null
            if ($('#uname2').val() == ''){
              document.getElementById('CheckUser2').innerHTML = "User name is null.";
              document.getElementById('CheckUser2').style.color="red";
              return;
            }
            else
              document.getElementById('CheckUser2').innerHTML = "";
            //check pass null
            if ($('#pwd2').val() == ''){
              document.getElementById('CheckPassword2').innerHTML = "Password is null.";
              document.getElementById('CheckPassword2').style.color="red";
              return;
            }
            else
              document.getElementById('CheckPassword2').innerHTML = "";


            if ($('#uname2').val() == '' || $('#pwd2').val() == '' || $('#pwd_confirm2').val() == '') return;
            if ($('#pwd2').val() != $('#pwd_confirm2').val()) return;

            
            <!-- update user -->
            var id_row = $('#id_user').val();
            var row_update = table1.rows[id_row];
            var check_user = 0;
      // phan update
      // lay id_row de bie dang chinh sua o ptu nao
      
      

            for (var i = 2; i <= table1.rows.length; i++){
                if ($('#infoTable')[0].rows[i-1].cells[1].innerHTML == $('#uname2').val() && $('#infoTable')[0].rows[i-1].cells[0].innerHTML != id_row){
                  check_user = 1;
                  break;
                } 
              }
            if (check_user == 0){
              row_update.cells[1].innerHTML = $('#uname2').val();
              row_update.cells[2].innerHTML = ($('#uadmin2').checked == true ? 'Admin' : 'User');
              row_update.cells[3].innerHTML = $('#pwd2').val();
              document.getElementById('CheckUser2').innerHTML = "";
              $('#modifyModal').modal('hide');
            } else {
              document.getElementById('CheckUser2').innerHTML = "User name is exists.";
              document.getElementById('CheckUser2').style.color="red";
            }
      
      <!-- code truyen xuong ESP o day -->
        
        var DataUser_modify = document.getElementById("uname2").value; 
        var DataPass_modify = document.getElementById("pwd2").value; 
        console.log("DataUser_modify: "+ DataUser_modify);
        console.log("DataPass_modify: "+ DataPass_modify);
        console.log("id row ta can lay di nhe: " + id_row);
        
        var xhttp = new XMLHttpRequest();
      
        xhttp.open("GET","/api/modify/usermanerment?id_row=" + id_row + "&DataUser_wb=" + DataUser_modify + "&DataPass_wb=" + DataPass_modify, true);
        xhttp.send();
            
          });
      
      
          <!--  bam vao modify thi o chay doan ctrinh nay -->
          function loadModify(){
      <!-- id_user_wb1 = $('#infoTable')[0].rows.length; -->
      <!-- id_user_wb1 = id_user_wb1 - 1;  -->
      <!-- console.log("Id_user: " + id_user_wb1); -->
         console.log("thu tu 2");
            var table1 = $('#infoTable')[0];
      console.log("Load modify nhe");
            for (var i = 2; i <= table1.rows.length; i ++){
              if (table1.rows[i-1].className == 'highlight'){
                $("#modifyModal").modal('show');
                
                $('#id_user').val(table1.rows[i-1].cells[0].innerHTML);
                $('#uname2').val(table1.rows[i-1].cells[1].innerHTML);
                $('#uadmin2').checked = (table1.rows[i-1].cells[2].innerHTML == 'User' ? false : true);
                $('#pwd2').val(table1.rows[i-1].cells[3].innerHTML);
                $('#pwd_confirm2').val(table1.rows[i-1].cells[3].innerHTML);
                break;
              }
            }
      
       
       <!-- code VDK o day -->
      <!-- phan modyfy tam dung o day, can do lai code ve web -->
      
          }
        
        // delete row User
        function deleteRowUser(){
          var table1 = $('#infoTable')[0], id_row = 0;

          for (var i = 2; i <= table1.rows.length; i ++){
              if (table1.rows[i-1].className == 'highlight'){
                id_row = i - 1;
                break;
              }
            }
        console.log("id_row xoa: " + id_row);
          var getUser = table1.rows[id_row].cells[1].innerHTML;
      
          console.log("user check la: " + getUser);
          if(confirm('Do you want delete Row?')) {
          document.getElementById('infoTable').deleteRow(id_row);
      
      var xhttp = new XMLHttpRequest();
      xhttp.open("GET","/api/delete/usermanerment?id_row=" + id_row + "&nameUser="+ getUser, true);
      xhttp.send();
          }
        }
        
         function logout()
        { 
                console.log("hehe");
                var xhttp = new XMLHttpRequest();
                xhttp.open("GET","/api/login",false);
          
                xhttp.send(); 
                
        }

      </script> 
    </body>
</html>
)=====";
