const char ConfigTypeResistor[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>
    <head>
       
        <link rel="shortcut icon" href="favicon.ico" type="image/x-icon">
        <meta charset="utf-8">
        <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">
        <title>ANV Group</title>
        <!------------------->
          <link rel="stylesheet" href="/boostrap/bootstrap.min.css">
          
<style>
          @media screen {
html, body{
    width: 100%;
    height: 100%;
    font-family: sans-serif;
    font-size: 17px;
    color: #222;
    overflow-y:auto;
    overflow-x:hidden;
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
.content_remove {
    height: 600px;
}
.iframe_x {
    height: 600px;
    width: 100%;
}

.footer {
    position: absolute;
    background: url("/footer"); 
    width: 100%;  
    height: 120px; 
    text-align: center; 
    color: #fff; 
    font-family: 'RobotoCondensed-Light'; 
    font-size: 15px;
    border-top: 5px solid #333;
    font-weight: bold;
    
}
.remote_x {
    margin: 50px;
}
.element_x {
   
    padding: 10px;
}
.container-fluid {
    width: 100%;
    margin-top: 50px;
}
.row {
    --bs-gutter-x: 0;
}
.title_e {
    background-color: blue;
    color: white;
}
.footer_e {
    background-color: blue;
    color: white; 
}
.btn_e {
    text-align: center;
    background-color: rgb(2, 10, 17);
    border: 1px solid white; /* Remove borders */
    cursor: pointer; /* Mouse pointer on hover */
    margin-top: 1px;
    margin-bottom: 1px;
}
.btn {
     /* Blue background */
    color: white; /* White text */
    font-size: 10px; /* Set a font size */
    border-radius: 0;   
  }
  
  /* Darker background on mouse-over */
  .btn_e:hover {
    background-color: #ff0;
  }
  .name_e {
      text-decoration-line: underline;
      margin-left: 2px;
  }
  .btn_on {
    background-color: rgb(57, 107, 151); /* Blue background */
    border: none; /* Remove borders */
    color: white; /* White text */
    padding: 10px; /* Some padding */
    font-size: 15px; /* Set a font size */
    cursor: pointer; /* Mouse pointer on hover */
    border-radius: 0;
    text-align: center;
    height: 50px;
  }
  .btn_on:hover {
    background-color: #ff0;
  }
  .btn_off {
    background-color: black; /* Blue background */
    border: none; /* Remove borders */
    color: white; /* White text */
    padding: 10px; /* Some padding */
    font-size: 15px; /* Set a font size */
    cursor: pointer; /* Mouse pointer on hover */
    border-radius: 0;
    text-align: center;
    height: 50px;
    margin-top: 5px;
  }
  .btn_off:hover {
    background-color: #ff0;
  }
  .khungchon {
    
    text-align: center; 
    color: #fffff; 
    width : 100%; 
  height: 30px;
    font-size: 15px;
    font-weight: lighter;
  }
  .footer_e_x {
      width: 50%;
  }

     
 }
</style>

</head>

    <body onload="Start()">
        <!--navigation-->
        <nav class="navbar navbar-expand-lg navbar-light bg-light">
            <a class="navbar-brand" href="#" style="margin-left: 50px;">
                <img src="/logo_anvgroup">
            </a>
          
            <div class="xnav_ngang" >
              <ul class="navbar-nav mr-auto">
                <li class="nav-item active" style="margin-left: 15px; margin-right: 15px;">
                  <!-- <a class="nav-link" href="#" target="iframe_a">Home</a> -->
                </li>
                <li class="nav-item">
                  
          <a class="nav-link" href="/api/system/Network"  target="iframe_a" style="margin-left: 15px; margin-right: 15px;">Setting NetWork</a>
                </li>
        <li class="nav-item">
                  
          <a class="nav-link" href="/api/control" onclick="SaveFinish()"  target="iframe_a" style="margin-left: 15px; margin-right: 15px;">UserInterface</a>
                </li>
                <li class="nav-link">
                     <a class="nav-link" href="/api/login" style="margin-left: 15px; margin-right: 15px;">LogOut</a>
                 </li>
              </ul>
            </div>
        </nav>
       <div class="content_remove">
    
          <div class="container-fluid padding" style="margin-top: 50px;">
            <div class="row">
                <div class="col-md-2 col-sm-1 col-xs-1"></div>
                <div id="id_load1" class="element_x col-md-2 col-sm-5 col-xs-10">
                    <div style="border: 1px solid black;">
                        <div class="title_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-8 col-sm-12 col-xs-12" style="margin-top: 5px;margin-bottom: 5px;"><span style="margin-left: 5px;">LOAD 1</span> </div>
                        
                            </div>
                        </div>

                        <div class="content_e col-md-12 col-sm-12 col-xs-12">
              <div class="row">
                  <div class="col-md-3 col-ms-3 col-xs-12">
                    <label style="margin-top: 15px;">Type</label>
                  </div>
                  <div class="col-md-8 col-ms-8 col-xs-12">
                      <select class="khungchon" style=" margin-top: 10px; margin-bottom: 10px;" id="load1typeresistor">
                      <option value = "1" style="text-align: center;">Serial</option>
                      <option value = "2" >parallel</option>
                      </select>
                  </div>
                             </div>
               <hr width="100%" style="margin-top:1px; margin-bottom:5px;"/>
               <div class="row">
                 <div class="col-md-6 col-ms-6 col-xs-12"> 
                  <button id="saveload1" type="submit" onclick="saveload1()" class="btn btn-primary" style="margin-top:0px; margin-left:5px; margin-bottom: 5px;"><i class="bi bi-check2">Save</i></button>
                 </div>
                 <div class="col-md-6 col-ms-6 col-xs-12"> 
                  <button id="cancelload1" type="submit" onclick="cancelload1()" class="btn btn-primary" style="margin-left:30px; margin-bottom: 5px;"><i style="margin: center; color: white;">Cancel</i></button>
                 </div>
              </div>
                        </div>
                        
                        <div class="footer_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="margin-top: 5px; height: 32px;"><p id="respondP1V1"><span style="margin-left: 5px; color:#000000"></span></p></div>
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="text-align: right; margin-top: 5px; height: 32px;"><p id="respondP1V2"><span style="margin-left: 5px; color:#000000"></span></p></div>
                            </div>
                        </div>
                    </div>
                </div> 
                <div id="id_load2" class="element_x col-md-2 col-sm-5 col-xs-10">
                    <div style="border: 1px solid black;">
                        <div class="title_e col-md-12 col-sm-12 col-xs-12">
                             <div class="row">
                                <div class="col-md-8 col-sm-12 col-xs-12" style="margin-top: 5px;margin-bottom: 5px;"><span style="margin-left: 5px;">LOAD 2</span> </div>
                        
                            </div>
                        </div>

                        <div class="content_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-3 col-ms-3 col-xs-12">
                   <label style="margin-top: 15px;">Type</label>
                </div>
                <div class="col-md-8 col-ms-8 col-xs-12">
                  <select class="khungchon" style=" margin-top: 10px; margin-bottom: 10px;" id="load2typeresistor">
                    <option value = "1" style="text-align: center;">Serial</option>
                    <option value = "2" >parallel</option>
                  </select>
                </div>
                            </div>
              <hr width="100%" style="margin-top:1px; margin-bottom:5px;"/>
               <div class="row">
                 <div class="col-md-6 col-ms-6 col-xs-12"> 
                  <button id="saveload2" type="submit" onclick="saveload2()" class="btn btn-primary" style="margin-top:0px; margin-left:5px; margin-bottom: 5px;"><i class="bi bi-check2">Save</i></button>
                 </div>
                 <div class="col-md-6 col-ms-6 col-xs-12"> 
                  <button id="cancelload2" type="submit" onclick="cancelload2()" class="btn btn-primary" style="margin-left:30px; margin-bottom: 5px;"><i style="margin: center; color: white;">Cancel</i></button>
                 </div>
              </div>
                        </div>
                        
                        <div class="footer_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="margin-top: 5px; height: 32px;"><p id="respondP2V1"><span style="margin-left: 5px;color:#000000"></span></p></div>
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="text-align: right; margin-top: 5px; height: 32px;"><p id="respondP2V2"><span style="margin-left: 5px;color:#000000"></span></p></div>
                            </div>
                        </div>
                    </div>
                </div> 
        
                <div id="id_load3" class="element_x col-md-2 col-sm-5 col-xs-10">
                    <div style="border: 1px solid black;">
                        <div class="title_e col-md-12 col-sm-12 col-xs-12">
              <div class="row">
                                <div class="col-md-12 col-sm-12 col-xs-12" style="margin-top: 5px;"><span style="margin-left: 5px;">LOAD 3</span> </div>
                            </div>
                        </div>

                        <div class="content_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-3 col-ms-3 col-xs-12">
                   <label style="margin-top: 15px;">Type</label>
                </div>
                <div class="col-md-8 col-ms-8 col-xs-12">
                  <select class="khungchon" style=" margin-top: 10px; margin-bottom: 10px;" id="load3typeresistor">
                    <option value = "1" style="text-align: center;">Serial</option>
                    <option value = "2" >parallel</option>
                  </select>
                </div>
                            </div>
              <hr width="100%" style="margin-top:1px; margin-bottom:5px;"/>
               <div class="row">
                 <div class="col-md-6 col-ms-6 col-xs-12"> 
                  <button id="saveload3" type="submit" onclick="saveload3()" class="btn btn-primary" style="margin-top:0px; margin-left:5px; margin-bottom: 5px;"><i class="bi bi-check2">Save</i></button>
                 </div>
                 <div class="col-md-6 col-ms-6 col-xs-12"> 
                  <button id="cancelload3" type="submit" onclick="cancelload3()" class="btn btn-primary" style="margin-left:30px; margin-bottom: 5px;"><i style="margin: center; color: white;">Cancel</i></button>
                 </div>
              </div>
                        </div>
                        
                        <div class="footer_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="margin-top: 5px; height: 32px;"><p id="respondP3V1"><span style="margin-left: 5px;color:#000000"></span></p></div>
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="text-align: right; margin-top: 5px; height: 32px;"><p id="respondP3V2"><span style="margin-left: 5px;color:#000000"></span></p></div>
                            </div>
                        </div>
                    </div>
                </div> 
                <div id="id_load4" class="element_x col-md-2 col-sm-5 col-xs-10">
                    <div style="border: 1px solid black;">
                        <div class="title_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-8 col-sm-12 col-xs-12" style="margin-top: 5px;"><span style="margin-left: 5px;">LOAD 4</span> </div>
                                
                            </div>
                        </div>

                        <div class="content_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-3 col-ms-3 col-xs-12">
                   <label style="margin-top: 15px;">Type</label>
                </div>
                <div class="col-md-8 col-ms-8 col-xs-12">
                  <select class="khungchon" style=" margin-top: 10px; margin-bottom: 10px;" id="load4typeresistor">
                    <option value = "1" style="text-align: center;">Serial</option>
                    <option value = "2" >parallel</option>
                  </select>
                </div>
                            </div>
              <hr width="100%" style="margin-top:1px; margin-bottom:5px;"/>
               <div class="row">
                 <div class="col-md-6 col-ms-6 col-xs-12"> 
                  <button id="saveload4" type="submit" onclick="saveload4()" class="btn btn-primary" style="margin-top:0px; margin-left:5px; margin-bottom: 5px;"><i class="bi bi-check2">Save</i></button>
                 </div>
                 <div class="col-md-6 col-ms-6 col-xs-12"> 
                  <button id="cancelload4" type="submit" onclick="cancelload4()" class="btn btn-primary" style="margin-left:30px; margin-bottom: 5px;"><i style="margin: center; color: white;">Cancel</i></button>
                 </div>
              </div>
                        </div>
                        
                        <div class="footer_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="margin-top: 5px; height: 32px;"><p id="respondP4V1"><span style="margin-left: 5px;color:#000000"></span></p></div>
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="text-align: right; margin-top: 5px; height: 32px;"><p id="respondP4V2"><span style="margin-left: 5px;color:#000000"></span></p></div>
                            </div>
                        </div>
                    </div>
                </div> 
                <div class="col-md-2 col-sm-1 col-xs-1"></div> 
            </div>
        </div> 
        
        <div class="container-fluid padding" style="margin-top: 50px;">
            <div class="row">
                <div class="col-md-2 col-sm-1 col-xs-1"></div>
                <div id="id_load5" class="element_x col-md-2 col-sm-5 col-xs-10">
                    <div style="border: 1px solid black;">
                        <div class="title_e col-md-12 col-sm-12 col-xs-12">
               <div class="row">
                <div class="col-md-12 col-sm-12 col-xs-12" style="margin-top: 5px;"><span style="margin-left: 5px;">LOAD 5</span> </div>
              </div>
                        </div>

                        <div class="content_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-3 col-ms-3 col-xs-12">
                   <label style="margin-top: 15px;">Type</label>
                </div>
                <div class="col-md-8 col-ms-8 col-xs-12">
                  <select class="khungchon" style=" margin-top: 10px; margin-bottom: 10px;" id="load5typeresistor">
                    <option value = "1" style="text-align: center;">Serial</option>
                    <option value = "2" >parallel</option>
                  </select>
                </div>
                            </div>
              <hr width="100%" style="margin-top:1px; margin-bottom:5px;"/>
               <div class="row">
                 <div class="col-md-6 col-ms-6 col-xs-12"> 
                  <button id="saveload5" type="submit" onclick="saveload5()" class="btn btn-primary" style="margin-top:0px; margin-left:5px; margin-bottom: 5px;"><i class="bi bi-check2">Save</i></button>
                 </div>
                 <div class="col-md-6 col-ms-6 col-xs-12"> 
                  <button id="cancelload5" type="submit" onclick="cancelload5()" class="btn btn-primary" style="margin-left:30px; margin-bottom: 5px;"><i style="margin: center; color: white;">Cancel</i></button>
                 </div>
              </div>
                        </div>
                        
                        <div class="footer_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="margin-top: 5px; height: 32px;"><p id="respondP5V1"><span style="margin-left: 5px;color:#000000"></span></p></div>
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="text-align: right; margin-top: 5px; height: 32px;"><p id="respondP5V2"><span style="margin-left: 5px;color:#000000"></span></p></div>
                            </div>
                        </div>
                    </div>
                </div> 
                <div id="id_load6" class="element_x col-md-2 col-sm-5 col-xs-10">
                    <div style="border: 1px solid black;">
                        <div class="title_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-12 col-sm-12 col-xs-12" style="margin-top: 5px;"><span style="margin-left: 5px;">LOAD 6</span> </div>
                                
                            </div>
                        </div>

                        <div class="content_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                 <div class="col-md-3 col-ms-3 col-xs-12">
                   <label style="margin-top: 15px;">Type</label>
                </div>
                <div class="col-md-8 col-ms-8 col-xs-12">
                  <select class="khungchon" style=" margin-top: 10px; margin-bottom: 10px;" id="load6typeresistor">
                    <option value = "1" style="text-align: center;">Serial</option>
                    <option value = "2" >parallel</option>
                  </select>
                </div>
                            </div>
              <hr width="100%" style="margin-top:1px; margin-bottom:5px;"/>
               <div class="row">
                 <div class="col-md-6 col-ms-6 col-xs-12"> 
                  <button id="saveload6" type="submit" onclick="saveload6()" class="btn btn-primary" style="margin-top:0px; margin-left:5px; margin-bottom: 5px;"><i class="bi bi-check2">Save</i></button>
                 </div>
                 <div class="col-md-6 col-ms-6 col-xs-12"> 
                  <button id="cancelload6" type="submit" onclick="cancelload6()" class="btn btn-primary" style="margin-left:30px; margin-bottom: 5px;"><i style="margin: center; color: white;">Cancel</i></button>
                 </div>
              </div>
                        </div>
                        
                        <div class="footer_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="margin-top: 5px; height: 32px;"><p id="respondP6V1"><span style="margin-left: 5px;color:#000000"></span></p></div>
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="text-align: right; margin-top: 5px; height: 32px;"><p id="respondP6V2"><span style="margin-left: 5px;color:#000000"></span></p></div>
                            </div>
                        </div>
                    </div>
                </div> 
                <div id="id_load7" class="element_x col-md-2 col-sm-5 col-xs-10">
                    <div style="border: 1px solid black;">
                        <div class="title_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-8 col-sm-12 col-xs-12" style="margin-top: 5px;"><span style="margin-left: 5px;">LOAD 7</span> </div>
                                
                            </div>
                        </div>

                        <div class="content_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-3 col-ms-3 col-xs-12">
                   <label style="margin-top: 15px;">Type</label>
                </div>
                <div class="col-md-8 col-ms-8 col-xs-12">
                  <select class="khungchon" style=" margin-top: 10px; margin-bottom: 10px;" id="load7typeresistor">
                    <option value = "1" style="text-align: center;">Serial</option>
                    <option value = "2" >parallel</option>
                  </select>
                </div>
                            </div>
                        </div>
                        <hr width="100%" style="margin-top:1px; margin-bottom:5px;"/>
               <div class="row">
                 <div class="col-md-6 col-ms-6 col-xs-12"> 
                  <button id="saveload7" type="submit" onclick="saveload7()" class="btn btn-primary" style="margin-top:0px; margin-left:5px; margin-bottom: 5px;"><i class="bi bi-check2">Save</i></button>
                 </div>
                 <div class="col-md-6 col-ms-6 col-xs-12"> 
                  <button id="cancelload7" type="submit" onclick="cancelload7()" class="btn btn-primary" style="margin-left:30px; margin-bottom: 5px;"><i style="margin: center; color: white;">Cancel</i></button>
                 </div>
              </div>
                        <div class="footer_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="margin-top: 5px; height: 32px;"><p id="respondP7V1"><span style="margin-left: 5px;color:#000000"></span></p></div>
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="text-align: right; margin-top: 5px; height: 32px;"><p id="respondP7V2"><span style="margin-left: 5px;color:#000000"></span></p></div>
                            </div>
                        </div>
                    </div>
                </div> 
                <div id="id_load8" class="element_x col-md-2 col-sm-5 col-xs-10">
                    <div style="border: 1px solid black;">
                        <div class="title_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-12 col-sm-12 col-xs-12" style="margin-top: 5px;"><span style="margin-left: 5px;">LOAD 8</span> </div>
                                
                            </div>
                        </div>

                        <div class="content_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                 <div class="col-md-3 col-ms-3 col-xs-12">
                   <label style="margin-top: 15px;">Type</label>
                </div>
                <div class="col-md-8 col-ms-8 col-xs-12">
                  <select class="khungchon" style=" margin-top: 10px; margin-bottom: 10px;" id="load8typeresistor">
                    <option value = "1" style="text-align: center;">Serial</option>
                    <option value = "2" >parallel</option>
                  </select>
                </div>
                            </div>
                        </div>
                        <hr width="100%" style="margin-top:1px; margin-bottom:5px;"/>
               <div class="row">
                 <div class="col-md-6 col-ms-6 col-xs-12"> 
                  <button id="saveload8" type="submit" onclick="saveload8()" class="btn btn-primary" style="margin-top:0px; margin-left:5px; margin-bottom: 5px;"><i class="bi bi-check2">Save</i></button>
                 </div>
                 <div class="col-md-6 col-ms-6 col-xs-12"> 
                  <button id="cancelload8" type="submit" onclick="cancelload8()" class="btn btn-primary" style="margin-left:30px; margin-bottom: 5px;"><i style="margin: center; color: white;">Cancel</i></button>
                 </div>
              </div>
                        <div class="footer_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="margin-top: 5px; height: 32px;"><p id="respondP8V1"><span style="margin-left: 5px;color:#000000"></span></div>
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="text-align: right; margin-top: 5px; height: 32px;"><p id="respondP8V2"><span style="margin-left: 5px;color:#000000"></span></p></div>
                            </div>
                        </div>
                    </div>
                </div> 
                <div class="col-md-2 col-sm-1 col-xs-1"></div> 
            </div>
        </div>
     <hr width="100%" style="margin-top:1px; margin-bottom:5px;"/>
      <button id="finish" type="button" onclick="nextpage()" class="btn btn-primary" style="margin-bottom: 5px; margin-left: 250px;"><i class="bi bi-check2">Next Page</i></button>
      
     </div>
        <div class="footer">
            <br/>
             Copyright © ANVGroup | Control Center. All rights reserved
        </div>

        <script>
    
    var DataJsonGiaoDien;
    var WB_GD_User1, WB_GD_Pass1, WB_GD_User2, WB_GD_Pass2, WB_GD_User3, WB_GD_Pass3, WB_GD_User4, WB_GD_Pass4, WB_GD_User5, WB_GD_Pass5;
    var PinCh1=0,PinCh2=0,PinCh3=0,PinCh4=0,PinCh5=0,PinCh6=0,PinCh7=0,PinCh8=0, GPinCh=0;
    var checkPinNo1=0, checkPinNo2=0,checkPinNo3=0, checkPinNo4=0, checkPinNo5=0, checkPinNo6=0, checkPinNo7=0, checkPinNo8=0;
    var DataVDK_GD;
    var sendDataload1, sendDataload2, sendDataload3, sendDataload4, sendDataload5, sendDataload6;
    var GlobalCheckTimeOut=0, LastGlobalCheckTimeOut=0;
    var CheckOpen_GD=0;
    
    <!--  phan set timer dem time-->
    const ChannelPin = [];
    var itimeCh1=0,itimeCh2=0,itimeCh3=0,itimeCh4=0,itimeCh5=0,itimeCh6=0,itimeCh7=0, itimeCh8=0;
    var readytime =0, check_Channel_pin = 0;
    var checkTimeOut1 = 0, checkTimeOut2 = 0, checkTimeOut3 = 0, checkTimeOut4 = 0, checkTimeOut5 = 0, checkTimeOut6 = 0, checkTimeOut7 = 0, checkTimeOut8 = 0;
      var count_timer=0;
      var t; <!-- t nay cho timer de ktra -->
      var timer_is_on=0;
  
  
  function Start()
  {
    LoadForm();
    UpdateData();
    
  }
  function LoadForm()
  {
      document.getElementById("id_load1").style.display = "block"; // show
      document.getElementById("id_load2").style.display = "block"; // 
    document.getElementById("id_load3").style.display = "block"; // show
      document.getElementById("id_load4").style.display = "block"; // 
    document.getElementById("id_load5").style.display = "block"; // show
      document.getElementById("id_load6").style.display = "block"; // 
    document.getElementById("id_load7").style.display = "none"; // hidden
      document.getElementById("id_load8").style.display = "none"; // hidden
      
  }
  
  function UpdateData()
  {
  //console.log("ok roi nhe: ");
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function()
    {
    if(this.readyState == 4 && this.status == 200)
    {
       DataVDK_GD = xhttp.responseText;
      console.log("Du lieu VDK: "+ DataVDK_GD);
      
      if(CheckOpen_GD == 0)
      { 
        DataJsonGiaoDien = JSON.parse(DataVDK_GD);
        XuLyDataLan1();
        CheckOpen_GD = 1;  // tam thoi bo =0 da
      }
      else 
      {
        GlobalCheckTimeOut++;
        XuLyDataLan2();
      }   
    }
    }
    
    xhttp.open("GET", "/GLoadData/select_resistor?CheckOpen_wb_GD=" + CheckOpen_GD + "&PinCh=" + GPinCh, true);
    xhttp.send();
    setTimeout(function(){ UpdateData() }, 1000);  
    }
  
  function XuLyDataLan1()
  {
    console.log("vao xu ly lan 1");
    // lay user va pass
    if(DataJsonGiaoDien.user1 != null && DataJsonGiaoDien.pass1 != null)
    {
      if(DataJsonGiaoDien.user1 != "" && DataJsonGiaoDien.pass1 != "")
      {
      WB_GD_User1 = DataJsonGiaoDien.user1;
      WB_GD_Pass1 = DataJsonGiaoDien.pass1;
      
      }  
    }
    
    if(DataJsonGiaoDien.user2 != null && DataJsonGiaoDien.pass2 != null)
    {
      if(DataJsonGiaoDien.user2 != "" && DataJsonGiaoDien.pass2 != "")
      {
        WB_GD_User2 = DataJsonGiaoDien.user2;
        WB_GD_Pass2 = DataJsonGiaoDien.pass2;
      }  
    }
          
    if(DataJsonGiaoDien.user3 != null && DataJsonGiaoDien.pass3 != null)
    {
      if(DataJsonGiaoDien.user3 != "" && DataJsonGiaoDien.pass3 != "")
      {
          WB_GD_User3 = DataJsonGiaoDien.user3;
          WB_GD_Pass3 = DataJsonGiaoDien.pass3;
      }  
    }
    if(DataJsonGiaoDien.user4 != null && DataJsonGiaoDien.pass4 != null)
    {
      if(DataJsonGiaoDien.user4 != "" && DataJsonGiaoDien.pass4 != "")
      {
          WB_GD_User4 = DataJsonGiaoDien.user4;
          WB_GD_Pass4 = DataJsonGiaoDien.pass4;
      }  
    }
    if(DataJsonGiaoDien.user5 != null && DataJsonGiaoDien.pass5 != null)
    {
      if(DataJsonGiaoDien.user5 != "" && DataJsonGiaoDien.pass5 != "")
      {
          WB_GD_User5 = DataJsonGiaoDien.user5;
          WB_GD_Pass5 = DataJsonGiaoDien.pass5;
      }  
    }
  }
  
  function XuLyDataLan2()
  {
    
   
    DataJsonGiaoDien = JSON.parse(DataVDK_GD);
    if(PinCh1)
    {
      console.log("gio ko biet sao");
      if(DataJsonGiaoDien.Pin1 != null)
      {
        // DL ok khong can biet tra ve gia tri gi 
        document.getElementById("respondP1V1").innerHTML = "transfer OK";
        PinCh1 = 0;
        GPinCh = 0;
        checkTimeOut1 = 0;
      }
    }
    if(PinCh2)
    {
      if(DataJsonGiaoDien.Pin2 != null)
      {
        // DL ok khong can biet tra ve gia tri gi 
        document.getElementById("respondP2V1").innerHTML = "transfer OK";
        checkTimeOut2 = 0;
        PinCh2 = 0;
        GPinCh = 0;
      }
    }
    if(PinCh3)
    {
      if(DataJsonGiaoDien.Pin3 != null)
      {
        // DL ok khong can biet tra ve gia tri gi 
        document.getElementById("respondP3V1").innerHTML = "transfer OK";
        PinCh3 = 0;
        GPinCh = 0;
        checkTimeOut3 = 0;
      }
    }
    if(PinCh4)
    {
      if(DataJsonGiaoDien.Pin4 != null)
      {
        // DL ok khong can biet tra ve gia tri gi
        document.getElementById("respondP4V1").innerHTML = "transfer OK";
        PinCh4 = 0;
        GPinCh = 0;
        checkTimeOut4 = 0;
      }
    }
    if(PinCh5)
    {
      if(DataJsonGiaoDien.Pin5 != null)
      {
        // DL ok khong can biet tra ve gia tri gi 
        document.getElementById("respondP5V1").innerHTML = "transfer OK";
        PinCh5 = 0;
        GPinCh = 0;
        checkTimeOut5 = 0;
      }
    }
    if(PinCh6)
    {
      if(DataJsonGiaoDien.Pin6 != null)
      {
        // DL ok khong can biet tra ve gia tri gi 
        document.getElementById("respondP6V1").innerHTML = "transfer OK";
        PinCh6 = 0;
        GPinCh = 0;
        checkTimeOut6 = 0;
      }
    }
   
  }
  function nextpage()
  {
     
    console.log("bam Finish");
    //var xhttp = new XMLHttpRequest();
    //xhttp.open("GET", "/api/control", false);
    //xhttp.send(null);   
     location.href = "/api/system/Network";
  }
  
    function saveload1()
    {
    console.log("tac dong save load 1!!!");
    if(document.getElementById("respondP1V1").innerHTML != "Disconnect")
    {
      var typeload1 = document.getElementById("load1typeresistor");
      var selectload1 = typeload1.options[typeload1.selectedIndex].value;
      if(selectload1 == "1")
      {
        console.log("chon Serial");
        sendDataload1 = "Serial";
      }
      else 
      {
        console.log("chon parallel");
        sendDataload1 = "parallel";
      }
       document.getElementById("respondP1V1").innerHTML = "Sending..";
       
       readytime = 1; 
       ChannelPin[0] = 1; // dem phan timer dinh time
       checkTimeOut1 = 1;
        
       checkPinNo1 =1;
       PinCh1 = 1;
       GPinCh = 1;
      
      var xhttp = new XMLHttpRequest();
      xhttp.open("GET", "/api/setting/typeresistor?Pin="+ checkPinNo1 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&senddata=" + sendDataload1, true); 
      xhttp.send();
    }
    }
    function cancelload1()
    {
       console.log("tac dong cancel load 1");
     
    }
  
  function saveload2()
    {
    console.log("tac dong save load 2!!!");
    if(document.getElementById("respondP2V1").innerHTML != "Disconnect")
    {
      var typeload2 = document.getElementById("load2typeresistor");
      var selectload2 = typeload2.options[typeload2.selectedIndex].value;
      if(selectload2 == "1")
      {
        console.log("chon Serial");
        sendDataload2 = "Serial";
      }
      else 
      {
        console.log("chon parallel");
        sendDataload2 = "parallel";
      }
       document.getElementById("respondP2V1").innerHTML = "Sending..";
       
       readytime = 1; 
       ChannelPin[1] = 1; // dem phan timer dinh time
       checkTimeOut2 = 2;
        
       checkPinNo2 =2;
       PinCh2 = 1;
       GPinCh = 2;
      
      var xhttp = new XMLHttpRequest();
      xhttp.open("GET", "/api/setting/typeresistor?Pin="+ checkPinNo2 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&senddata=" + sendDataload2, true); 
      xhttp.send();
    }
    }
  function cancelload2()
    {
       console.log("tac dong cancel load 2");
     
    }
  function saveload3()
    {
    console.log("tac dong save load 3!!!");
    if(document.getElementById("respondP3V1").innerHTML != "Disconnect")
    {
      var typeload3 = document.getElementById("load3typeresistor");
      var selectload3 = typeload3.options[typeload3.selectedIndex].value;
      if(selectload3 == "1")
      {
        console.log("chon Serial");
        sendDataload3 = "Serial";
      }
      else 
      {
        console.log("chon parallel");
        sendDataload3 = "parallel";
      }
       document.getElementById("respondP3V1").innerHTML = "Sending..";
       
       readytime = 1; 
       ChannelPin[2] = 1; // dem phan timer dinh time
       checkTimeOut3 = 1;
        
       checkPinNo3 =3;
       PinCh3 = 1;
       GPinCh = 3;
      
      var xhttp = new XMLHttpRequest();
      xhttp.open("GET", "/api/setting/typeresistor?Pin="+ checkPinNo3 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&senddata=" + sendDataload3, true); 
      xhttp.send();
    }
    }
  function cancelload3()
    {
       console.log("tac dong cancel load 3");
     
    }
  
  function saveload4()
    {
    console.log("tac dong save load 4!!!");
    if(document.getElementById("respondP4V1").innerHTML != "Disconnect")
    {
      var typeload4 = document.getElementById("load4typeresistor");
      var selectload4 = typeload4.options[typeload4.selectedIndex].value;
      if(selectload4 == "1")
      {
        console.log("chon Serial");
        sendDataload4 = "Serial";
      }
      else 
      {
        console.log("chon parallel");
        sendDataload4 = "parallel";
      }
       document.getElementById("respondP4V1").innerHTML = "Sending..";
       
       readytime = 1; 
       ChannelPin[3] = 1; // dem phan timer dinh time
       checkTimeOut4 = 1;
        
       checkPinNo4 =4;
       PinCh4 = 1;
       GPinCh = 4;
      
      var xhttp = new XMLHttpRequest();
      xhttp.open("GET", "/api/setting/typeresistor?Pin="+ checkPinNo4 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&senddata=" + sendDataload4, true); 
      xhttp.send();
    }
    }
  function cancelload4()
    {
       console.log("tac dong cancel load 4");
     
    }
  function saveload5()
    {
    console.log("tac dong save load 5!!!");
    if(document.getElementById("respondP5V1").innerHTML != "Disconnect")
    {
      var typeload5 = document.getElementById("load5typeresistor");
      var selectload5 = typeload5.options[typeload5.selectedIndex].value;
      if(selectload5 == "1")
      {
        console.log("chon Serial");
        sendDataload5 = "Serial";
      }
      else 
      {
        console.log("chon parallel");
        sendDataload5 = "parallel";
      }
       document.getElementById("respondP5V1").innerHTML = "Sending..";
       
       readytime = 1; 
       ChannelPin[4] = 1; // dem phan timer dinh time
       checkTimeOut5 = 1;
        
       checkPinNo5 =5;
       PinCh5 = 1;
       GPinCh = 5;
      
      var xhttp = new XMLHttpRequest();
      xhttp.open("GET", "/api/setting/typeresistor?Pin="+ checkPinNo5 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&senddata=" + sendDataload5, true); 
      xhttp.send();
    }
    }
  function cancelload5()
    {
       console.log("tac dong cancel load 5");
     
    }
  
  function saveload6()
    {
    console.log("tac dong save load 6!!!");
    if(document.getElementById("respondP6V1").innerHTML != "Disconnect")
    {
      var typeload6 = document.getElementById("load6typeresistor");
      var selectload6 = typeload6.options[typeload6.selectedIndex].value;
      if(selectload6 == "1")
      {
        console.log("chon Serial");
        sendDataload6 = "Serial";
      }
      else 
      {
        console.log("chon parallel");
        sendDataload6 = "parallel";
      }
       document.getElementById("respondP6V1").innerHTML = "Sending..";
       
       readytime = 1; 
       ChannelPin[5] = 1; // dem phan timer dinh time
       checkTimeOut6 = 1;
        
       checkPinNo6 =6;
       PinCh6 = 1;
       GPinCh = 6;
      
      var xhttp = new XMLHttpRequest();
      xhttp.open("GET", "/api/setting/typeresistor?Pin="+ checkPinNo6 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&senddata=" + sendDataload6, true); 
      xhttp.send();
    }
    }
  function cancelload6()
    {
       console.log("tac dong cancel load 6");
     
    }
 
  
  function stopCount()
  {
    clearTimeout(t);
    timer_is_on=0;
    
  } 
  
  
  function timedCount()
  {
    <!-- khi dem timeer thi chay trong phan nay -->
    t=setTimeout("timedCount()",1000);
  count_timer++;
    switch(count_timer)
    {
    case 3:
      count_timer=0;
      if(GlobalCheckTimeOut - LastGlobalCheckTimeOut > 0)
      {
        GlobalCheckTimeOut =0;
        LastGlobalCheckTimeOut = 0;
        LastGlobalCheckTimeOut = GlobalCheckTimeOut;
        if(document.getElementById("respondP1V1").innerHTML == "Disconnect")
        document.getElementById("respondP1V1").innerHTML = "";
        if(document.getElementById("respondP2V1").innerHTML == "Disconnect")
        document.getElementById("respondP2V1").innerHTML = ""; 
        if(document.getElementById("respondP3V1").innerHTML == "Disconnect")
        document.getElementById("respondP3V1").innerHTML = "";
        if(document.getElementById("respondP4V1").innerHTML == "Disconnect")
        document.getElementById("respondP4V1").innerHTML = "";
        if(document.getElementById("respondP5V1").innerHTML == "Disconnect")
        document.getElementById("respondP5V1").innerHTML = "";
        if(document.getElementById("respondP6V1").innerHTML == "Disconnect")
        document.getElementById("respondP6V1").innerHTML = ""; 
        if(document.getElementById("respondP7V1").innerHTML == "Disconnect")
        document.getElementById("respondP7V1").innerHTML = "";
        if(document.getElementById("respondP8V1").innerHTML == "Disconnect")
        document.getElementById("respondP8V1").innerHTML = "";
      }
      else {
        GlobalCheckTimeOut =0;
        LastGlobalCheckTimeOut = 0;
        LastGlobalCheckTimeOut = GlobalCheckTimeOut;
        document.getElementById("respondP1V1").innerHTML = "Disconnect"; 
        document.getElementById("respondP2V1").innerHTML = "Disconnect"; 
        document.getElementById("respondP3V1").innerHTML = "Disconnect"; 
        document.getElementById("respondP4V1").innerHTML = "Disconnect"; 
        document.getElementById("respondP5V1").innerHTML = "Disconnect"; 
        document.getElementById("respondP6V1").innerHTML = "Disconnect"; 
        document.getElementById("respondP7V1").innerHTML = "Disconnect";
        document.getElementById("respondP8V1").innerHTML = "Disconnect";    
      }
      break;
      
    }
  if(readytime)
  {
    if(ChannelPin[0])
    {
      itimeCh1++;
      if(checkTimeOut1) // bi loi
      {
        if(itimeCh1 == 4)
        {
          document.getElementById("respondP1V1").innerHTML = "timeOut";
          var xhttp = new XMLHttpRequest();
          xhttp.open("GET", "/api/setting/typeresistor?Pin="+ checkPinNo1 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&senddata=" + sendDataload1, true); 
          xhttp.send();
          console.log("gui lan lan 1 pin 2"); 
        }
        else if(itimeCh1 == 7)
        {
          document.getElementById("respondP1V1").innerHTML = "Disconnect";
          itimeCh1 = 0;
          ChannelPin[0] = 0;
        }
      }
      else 
      {
        if(itimeCh1 > 2)
        {
          itimeCh1 = 0;
          ChannelPin[0] = 0;
          document.getElementById("respondP1V1").innerHTML = "";
        }
      }
    }
    
    if(ChannelPin[1])
    {
      itimeCh2++;
      if(checkTimeOut2) // bi loi
      {
        if(itimeCh2 == 4)
        {
          document.getElementById("respondP2V1").innerHTML = "timeOut";
          var xhttp = new XMLHttpRequest();
          xhttp.open("GET", "/api/setting/typeresistor?Pin="+ checkPinNo2 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&senddata=" + sendDataload2, true); 
          xhttp.send();
          console.log("gui lan lan 1 pin 2"); 
        }
        else if(itimeCh2 == 7)
        {
          document.getElementById("respondP2V1").innerHTML = "Disconnect";
          itimeCh2 = 0;
          ChannelPin[1] = 0;
        }
      }
      else 
      {
        if(itimeCh2 > 2)
        {
          itimeCh2 = 0;
          ChannelPin[1] = 0;
          document.getElementById("respondP2V1").innerHTML = "";
        }
      }
    }
    
    if(ChannelPin[2])
    {
      itimeCh3++;
      if(checkTimeOut3) // bi loi
      {
        if(itimeCh3 == 4)
        {
          document.getElementById("respondP3V1").innerHTML = "timeOut";
          var xhttp = new XMLHttpRequest();
          xhttp.open("GET", "/api/setting/typeresistor?Pin="+ checkPinNo3 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&senddata=" + sendDataload3, true); 
          xhttp.send();
          console.log("gui lan lan 1 pin 3"); 
        }
        else if(itimeCh3 == 7)
        {
          document.getElementById("respondP3V1").innerHTML = "Disconnect";
          itimeCh3 = 0;
          ChannelPin[2] = 0;
        }
      }
      else 
      {
        if(itimeCh3 > 2)
        {
          itimeCh3 = 0;
          ChannelPin[2] = 0;
          document.getElementById("respondP3V1").innerHTML = "";
        }
      }
    }
    
    if(ChannelPin[3])
    {
      itimeCh4++;
      if(checkTimeOut4) // bi loi
      {
        if(itimeCh4 == 4)
        {
          document.getElementById("respondP4V1").innerHTML = "timeOut";
          var xhttp = new XMLHttpRequest();
          xhttp.open("GET", "/api/setting/typeresistor?Pin="+ checkPinNo4 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&senddata=" + sendDataload4, true); 
          xhttp.send();
          console.log("gui lan lan 1 pin 4"); 
        }
        else if(itimeCh4 == 7)
        {
          document.getElementById("respondP4V1").innerHTML = "Disconnect";
          itimeCh4 = 0;
          ChannelPin[3] = 0;
        }
      }
      else 
      {
        if(itimeCh4 > 2)
        {
          itimeCh4 = 0;
          ChannelPin[3] = 0;
          document.getElementById("respondP4V1").innerHTML = "";
        }
      }
    }
    
    if(ChannelPin[4])
    {
      itimeCh5++;
      if(checkTimeOut5) // bi loi
      {
        if(itimeCh5 == 4)
        {
          document.getElementById("respondP5V1").innerHTML = "timeOut";
          var xhttp = new XMLHttpRequest();
          xhttp.open("GET", "/api/setting/typeresistor?Pin="+ checkPinNo5 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&senddata=" + sendDataload5, true); 
          xhttp.send();
          console.log("gui lan lan 1 pin 5"); 
        }
        else if(itimeCh4 == 7)
        {
          document.getElementById("respondP5V1").innerHTML = "Disconnect";
          itimeCh5 = 0;
          ChannelPin[4] = 0;
        }
      }
      else 
      {
        if(itimeCh5 > 2)
        {
          itimeCh5 = 0;
          ChannelPin[4] = 0;
          document.getElementById("respondP5V1").innerHTML = "";
        }
      }
    }
    
    if(ChannelPin[5])
    {
      itimeCh6++;
      if(checkTimeOut6) // bi loi
      {
        if(itimeCh6 == 4)
        {
          document.getElementById("respondP6V1").innerHTML = "timeOut";
          var xhttp = new XMLHttpRequest();
          xhttp.open("GET", "/api/setting/typeresistor?Pin="+ checkPinNo6 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&senddata=" + sendDataload6, true); 
          xhttp.send();
          console.log("gui lan lan 1 pin 6"); 
        }
        else if(itimeCh6 == 7)
        {
          document.getElementById("respondP6V1").innerHTML = "Disconnect";
          itimeCh6 = 0;
          ChannelPin[5] = 0;
        }
      }
      else 
      {
        if(itimeCh6 > 2)
        {
          itimeCh6 = 0;
          ChannelPin[5] = 0;
          document.getElementById("respondP6V1").innerHTML = "";
        }
      }
    }
    
    for(var i=0;i<8;i++)
    {
        if(ChannelPin[i])
        {
          check_Channel_pin = 1;
          break;
        }
        else check_Channel_pin = 0;
    }
    if(check_Channel_pin ==0) 
    {
      readytime = 0; 
      
    }
    
  }
  }
  
  doTimer();
  function doTimer()
  {
    if (!timer_is_on)
    {
      timer_is_on=1;
      timedCount();
    }
    
  }
  
  
   
      </script> 
    </body>
</html>
)=====";
