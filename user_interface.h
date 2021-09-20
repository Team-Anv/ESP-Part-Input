const char UserInterface[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>ANV Group</title>
        <!------------------->

        <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.1/dist/css/bootstrap.min.css">
        <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.3/css/all.min.css"/>

        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-gtEjrD/SeCtmISkJkNUaaKMoLD0//ElJ19smozuHV6z3Iehds+3Ulb9Bn9Plx0x4" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.9.2/dist/umd/popper.min.js" integrity="sha384-IQsoLXl5PILFhosVNubq5LC7Qb9DXgDA9i+tQ8Zj3iwWAwPtgFTxbJ8NT4GN1R8p" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.1/dist/js/bootstrap.min.js" integrity="sha384-Atwg2Pkwv9vp0ygtn1JAojH0nYbwNJLPhwyoVbhoPwBhjQPR5VtM2+xf0Uwh9KtT" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/i18next/1.11.1/i18next.min.js"></script>
        <!-- <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script> -->
        
        <script type="text/javascript" src="/boostrap/loader.js"></script>

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
   text-align: center;
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
  .ctemp {
    background-color: #cccccc; /* Blue background */
    border: none; /* Remove borders */
    color: white; /* White text */
    padding: 10px; /* Some padding */
    font-size: 15px; /* Set a font size */
    cursor: pointer; /* Mouse pointer on hover */
    border-radius: 0;
    text-align: center;
    height: 50px;
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
  
  
  .footer_e_x {
      width: 50%;
  }    
 }
        </style>
    </head>

    <body onload="UpdateData()">
        <!--navigation-->
        <nav class="navbar navbar-expand-lg navbar-light bg-light">
            <a class="navbar-brand" href="#" style="margin-left: 50px;">
                <img src="/logo_anvgroup">
            </a>
          
            <div class="xnav_ngang" >
        
        <ul class="navbar-nav mr-auto">
          <li class="nav-item">
              <a class="nav-link" href="/api/config/resistor" style="margin-left: 15px; margin-right: 15px;">System</a>
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
                <div class="element_x col-md-2 col-sm-5 col-xs-10">
                    <div style="border: 1px solid black;">
                        <div class="title_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-6 col-sm-12 col-xs-12" style="margin-top: 5px;"><span style="margin-left: 5px;">Temp</span> </div>
                <div class="footer_e_x col-md-6 col-sm-12 col-xs-12" style="margin-top: 5px;height: 32px;"><p id="Tempnotify" style="text-align: right;color:#cccccc">Activate</p></div>
                            </div>
              
                        </div>

                        <div class="content_e col-md-12 col-sm-12 col-xs-12">
                            <center>  
                <span id="chart_nhietdo"  ;style="width: 400px; height: 120px;"></span>
              </center>
                        </div>
                        
                        <div class="footer_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="margin-top: 5px; height: 32px;"><p id="respondP1V1Temp"><span style="margin-left: 5px; color:#000000"></span></p></div> <!-- wating o day nhe -->
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="text-align: right; margin-top: 5px; height: 32px;"><p id="respondP1V2Temp"><span style="margin-left: 5px; color:#000000">OFF</span></p></div>
                            </div>
                        </div>
                    </div>
                </div> 
        <!-- o thu nhat tao xong -->
                <div class="element_x col-md-2 col-sm-5 col-xs-10">
                    <div style="border: 1px solid black;">
                        <div class="title_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-6 col-sm-12 col-xs-12" style="margin-top: 5px;"><span style="margin-left: 5px;">Smoke 1</span> </div>
                  <div class="footer_e_x col-md-6 col-sm-12 col-xs-12" style="margin-top: 5px;height: 32px;"><p id="No2notify" style="text-align: right;color:#cccccc">Activate</p></div>
                
                            </div>
                        </div>

                        <div class="content_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-6 col-sm-12 col-xs-12" style="text-align: center; margin-top: 10px;">
                                    <img id="id_img_pin2" src="/smoke" alt="" width="100px" height="100px">
                                </div>
                                <div class="col-md-6 col-sm-12 col-xs-12" style="padding: 5px;">
                                    <div class="btn_on col-md-12 col-sm-12 col-xs-12">
                                        <button id="GPIO1_ON_WB" onclick="TURN_ON_PIN2()" type="button" class="btn">Alarm</button>      
                                    </div>
                                    <div class="btn_off col-md-12 col-sm-12 col-xs-12">
                                        <button id="GPIO1_OFF_WB" onclick="TURN_OFF_PIN2()" type="button" class="btn">Disalarm</button> 
                                    </div>  
                                </div>   
                            </div>
                        </div>
                        
                        <div class="footer_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="margin-top: 5px; height: 32px;"><p id="respondP2V1"><span style="margin-left: 5px;color:#000000"></span></p></div>
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="text-align: right; margin-top: 5px; height: 32px;"><p id="respondP2V2" style="margin-left: 5px;color:#000000">OFF</p></div>
                            </div>
                        </div>
                    </div>
                </div> 
                <div class="element_x col-md-2 col-sm-5 col-xs-10">
                    <div style="border: 1px solid black;">
                        <div class="title_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-6 col-sm-12 col-xs-12" style="margin-top: 5px;"><span style="margin-left: 5px;">Smoke 2</span> </div>
                  <div class="footer_e_x col-md-6 col-sm-12 col-xs-12" style="margin-top: 5px;height: 32px;"><p id="No3notify" style="text-align: right;color:#cccccc">Activate</p></div>
                            </div>
                        </div>

                        <div class="content_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-6 col-sm-12 col-xs-12" style="text-align: center; margin-top: 10px;">
                                    <img id="id_img_pin3" src="/smoke" alt="" width="100px" height="100px">
                                </div>
                                <div class="col-md-6 col-sm-12 col-xs-12" style="padding: 5px;">
                                    <div class="btn_on col-md-12 col-sm-12 col-xs-12">
                                        <button id="Pin3_ON_WB" onclick="TURN_ON_PIN3()" type="button" class="btn">Alarm</i></button>      
                                    </div>
                                    <div class="btn_off col-md-12 col-sm-12 col-xs-12">
                                        <button id="Pin3_OFF_WB" onclick="TURN_OFF_PIN3()" type="button" class="btn">Disalarm</i></button> 
                                    </div>  
                                </div>   
                            </div>
                        </div>
                        
                        <div class="footer_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="margin-top: 5px; height: 32px;"><p id="respondP3V1"><span style="margin-left: 5px;color:#000000"></span></p></div>
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="text-align: right; margin-top: 5px; height: 32px;"><p id="respondP3V2" style="margin-left: 5px;color:#000000">OFF</p></div>
                            </div>
                        </div>
                    </div>
                </div> 
                <div class="element_x col-md-2 col-sm-5 col-xs-10">
                    <div style="border: 1px solid black;">
                        <div class="title_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-6 col-sm-12 col-xs-12" style="margin-top: 5px;"><span style="margin-left: 5px;">Smoke 3</span> </div>
                <div class="footer_e_x col-md-6 col-sm-12 col-xs-12" style="margin-top: 5px;height: 32px;"><p id="No4notify" style="text-align: right;color:#cccccc">Activate</p></div>
         
                            </div>
                        </div>

                        <div class="content_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-6 col-sm-12 col-xs-12" style="text-align: center; margin-top: 10px;">
                                    <img id="id_img_pin4" src="/smoke" alt="" width="100px" height="100px">
                                </div>
                                <div class="col-md-6 col-sm-12 col-xs-12" style="padding: 5px;">
                                    <div class="btn_on col-md-12 col-sm-12 col-xs-12">
                                        <button id="Pin4_ON_WB" onclick="TURN_ON_PIN4()" type="button" class="btn">Alarm</i></button>      
                                    </div>
                                    <div class="btn_off col-md-12 col-sm-12 col-xs-12">
                                        <button id="Pin4_OFF_WB" onclick="TURN_OFF_PIN4()" type="button" class="btn">Disalarm</i></button> 
                                    </div>  
                                </div>   
                            </div>
                        </div>
                        
                        <div class="footer_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="margin-top: 5px; height: 32px;"><p id="respondP4V1"><span style="margin-left: 5px;color:#000000"></span></p></div>
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="text-align: right; margin-top: 5px; height: 32px;"><p id="respondP4V2" style="margin-left: 5px;color:#000000">OFF</p></div>
                            </div>
                        </div>
                    </div>
                </div> 
                <div class="col-md-2 col-sm-1 col-xs-1"></div> 
            </div>
        </div> 
    <!-- dive tren và div duoi 4-4 -->
        
        <div class="container-fluid padding" style="margin-top: 50px;">
            <div class="row">
                <div class="col-md-2 col-sm-1 col-xs-1"></div>
                <div class="element_x col-md-2 col-sm-5 col-xs-10">
                    <div style="border: 1px solid black;">
                        <div class="title_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-6 col-sm-12 col-xs-12" style="margin-top: 5px;"><span style="margin-left: 5px;">Moverment</span> </div>
                                <div class="footer_e_x col-md-6 col-sm-12 col-xs-12" style="margin-top: 5px;height: 32px;"><p id="No5notify" style="text-align: right;color:#cccccc">Activate</p></div>
                            </div>
                        </div>

                        <div class="content_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-6 col-sm-12 col-xs-12" style="text-align: center; margin-top: 10px;">
                                    <img id="id_img_pin5" src="/people_move" alt="" width="100px" height="100px">
                                </div>
                                <div class="col-md-6 col-sm-12 col-xs-12" style="padding: 5px;">
                                    <div class="btn_on col-md-12 col-sm-12 col-xs-12">
                                        <button id="Pin5_ON_WB" onclick="TURN_ON_PIN5()" type="button" class="btn">Alarm</i></button>      
                                    </div>
                                    <div class="btn_off col-md-12 col-sm-12 col-xs-12">
                                        <button id="Pin5_OFF_WB" onclick="TURN_OFF_PIN5()" type="button" class="btn">Disalarm</i></button> 
                                    </div>  
                                </div>   
                            </div>
                        </div>
                        
                        <div class="footer_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="margin-top: 5px; height: 32px;"><p id="respondP5V1"><span style="margin-left: 5px;color:#000000"></span></p></div>
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="text-align: right; margin-top: 5px; height: 32px;"><p id="respondP5V2" style="margin-left: 5px;color:#000000">OFF</p></div>
                            </div>
                        </div>
                    </div>
                </div> 
                <div class="element_x col-md-2 col-sm-5 col-xs-10">
                    <div style="border: 1px solid black;">
                        <div class="title_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-6 col-sm-12 col-xs-12" style="margin-top: 5px;"><span style="margin-left: 5px;">Distance</span> </div>
                               
                                <div class="footer_e_x col-md-6 col-sm-12 col-xs-12" style="margin-top: 5px;height: 32px;"><p id="No6notify" style="text-align: right;color:#cccccc">Activate</p></div>
                            </div>
                        </div>

                        <div class="content_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-6 col-sm-12 col-xs-12" style="text-align: center; margin-top: 10px;">
                                    <img id="id_img_pin6" src="/distance" alt="" width="100px" height="100px">
                                </div>
                                <div class="col-md-6 col-sm-12 col-xs-12" style="padding: 5px;">
                                    <div class="btn_on col-md-12 col-sm-12 col-xs-12">
                                        <button id="Pin6_ON_WB" onclick="TURN_ON_PIN6()" type="button" class="btn">Alarm</i></button>      
                                    </div>
                                    <div class="btn_off col-md-12 col-sm-12 col-xs-12">
                                        <button id="Pin6_OFF_WB" onclick="TURN_OFF_PIN6()" type="button" class="btn">Disalarm</i></button> 
                                    </div>  
                                </div>   
                            </div>
                        </div>
                        
                        <div class="footer_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="margin-top: 5px; height: 32px;"><p id="respondP6V1"><span style="margin-left: 5px;color:#000000"></span></p></div>
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="text-align: right; margin-top: 5px; height: 32px;"><p id="respondP6V2" style="margin-left: 5px;color:#000000">OFF</p></div>
                            </div>
                        </div>
                    </div>
                </div> 
        <!-- phan tu 7 -->
                <div class="element_x col-md-2 col-sm-5 col-xs-10">
                    <div style="border: 1px solid black;">
                        <div class="title_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-6 col-sm-12 col-xs-12" style="margin-top: 5px;"><span style="margin-left: 5px;">Button</span> </div>
                               <div class="footer_e_x col-md-6 col-sm-12 col-xs-12" style="margin-top: 5px;height: 32px;"><p id="No7notify" style="text-align: right;color:#cccccc">Activate</p></div>
                            </div>
                        </div>

                        <div class="content_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-6 col-sm-12 col-xs-12" style="text-align: center; margin-top: 10px;">
                                    <img id="id_img_pin7" src="/button" alt="" width="100px" height="100px">
                  
                                </div>
                                <div class="col-md-6 col-sm-12 col-xs-12" style="padding: 5px;">
                                    <div class="btn_on col-md-12 col-sm-12 col-xs-12">
                                        <button id="Pin7_ON_WB" onclick="TURN_ON_PIN7()" type="button" class="btn">Alarm</i></button>      
                                    </div>
                                    <div class="btn_off col-md-12 col-sm-12 col-xs-12">
                                        <button id="Pin7_OFF_WB" onclick="TURN_OFF_PIN7()" type="button" class="btn">Disalarm</i></button> 
                                    </div>  
                                </div>   
                            </div>
                        </div>
                        
                        <div class="footer_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="margin-top: 5px; height: 32px;"><p id="respondP7V1"><span style="margin-left: 5px;color:#000000"></span></div>
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="text-align: right; margin-top: 5px; height: 32px;"><p id="respondP7V2" style="margin-left: 5px;color:#000000">OFF</p></div>
                            </div>
                        </div>
                    </div>
                </div> 
        
                <div class="element_x col-md-2 col-sm-5 col-xs-10">
                    <div style="border: 1px solid black;">
                        <div class="title_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-12 col-sm-12 col-xs-12" style="margin-top: 5px; height: 32px;"><span style="margin-left: 5px;">Resistor Serial</span> </div>
                               
                            </div>
                        </div>

                        <div class="content_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="col-md-6 col-sm-12 col-xs-12" style="text-align: center; margin-top: 10px; margin-bottom: 5px;">
                                    <img id="id_img_resis" src="/impact" alt="" width="100px" height="100px">
                  
                                </div>
                                <div class="col-md-6 col-sm-12 col-xs-12" style="padding: 5px;">
                                    <p id="ResistorNotify" style="text-align: center; margin-top: 45px ;color:#0b8a00">Normal</p>
                                </div>   
                            </div>
                        </div>
                        
                        <div class="footer_e col-md-12 col-sm-12 col-xs-12">
                            <div class="row">
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="margin-top: 5px; height: 32px;"><p id="respondP8V1"><span style="margin-left: 5px;color:#000000"></span></div>
                                <div class="footer_e_x col-md-6 col-sm-6 col-xs-6" style="text-align: right; margin-top: 5px; height: 32px;"><p id="respondP8V2" style="margin-left: 5px;color:#000000"></p></div>
                            </div>
                        </div>
                    </div>
                </div> 
                <div class="col-md-2 col-sm-1 col-xs-1"></div> 
            </div>
        </div>
        </div>
        <div class="footer">
            <br/>
             Copyright © ANVGroup | Control Center. All rights reserved
        </div>

    <script>
    
    var CheckOpen_GD = 0;
    var WB_GD_User1, WB_GD_Pass1, WB_GD_User2, WB_GD_Pass2, WB_GD_User3, WB_GD_Pass3, WB_GD_User4, WB_GD_Pass4, WB_GD_User5, WB_GD_Pass5, WB_Pin1,WB_Pin2,WB_Pin3,WB_Pin4,WB_Pin5,WB_Pin6,WB_SS,WB_NT;
    var ModeP1,ModeP2,ModeP3,ModeP4,ModeP5,ModeP6,ModeP7,ModeP8;
    var ValSensor=0;
    var PinCh1=1,PinCh2=1,PinCh3=1,PinCh4=1,PinCh5=1,PinCh6=1,PinCh7=1,PinCh8=1;
  var PinCh1OneTime = 0, PinCh2OneTime = 0, PinCh3OneTime = 0, PinCh4OneTime = 0, PinCh5OneTime = 0,PinCh6OneTime = 0, PinCh7OneTime = 0, PinCh8OneTime = 0;
  
    var checkPinNo1=0, checkPinNo2=0,checkPinNo3=0, checkPinNo4=0, checkPinNo5=0, checkPinNo6=0, checkPinNo7=0, checkPinNo8=0;
    var statusPin1=0, statusPin2=0, statusPin3=0, statusPin4=0, statusPin5=0, statusPin6=0, statusPin7=0, statusPin8=0;
    var DataJsonGiaoDien,DataVDK_GD;
    <!--  phan set timer dem time-->
     const ChannelPin = [];
     var itimeCh1=0,itimeCh2=0,itimeCh3=0,itimeCh4=0,itimeCh5=0,itimeCh6=0,itimeCh7=0, itimeCh8=0;
     var readytime =0;
     var check_Channel_pin =0;
     var GlobalCheckTimeOut = 0, checkTimeOut1=0,checkTimeOut2=0, checkTimeOut3=0, checkTimeOut4=0, checkTimeOut5=0, checkTimeOut6=0, checkTimeOut7=0,checkTimeOut8=0;
      var LastGlobalCheckTimeOut=0, count_timer =0;
  
    
     
      var t; <!-- t nay cho timer de ktra -->
      var timer_is_on=0;
      
  
    function UpdateData()
    {
       //console.log("vao Upload: ");
       var xhttp = new XMLHttpRequest(); // dang bo do tai day
       xhttp.onreadystatechange = function()
       {
      if(this.readyState == 4 && this.status == 200)
      {
         DataVDK_GD ="";
       DataVDK_GD = xhttp.responseText;
       
       console.log("Dữ liệu VDK: " + DataVDK_GD);
       DataJsonGiaoDien = JSON.parse(DataVDK_GD);
       
        if(CheckOpen_GD == 0)
        { 
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
      xhttp.open("GET", "/GLoadData/UserInterface?CheckOpen_wb_GD=" + CheckOpen_GD, true);
      xhttp.send();
      setTimeout(function(){ UpdateData() }, 1000); 
      
    }
  
  function XuLyDataLan1()
  {
    console.log("vao xu ly lan 1");
    // lay user va pass
    if(DataJsonGiaoDien.u1 != null && DataJsonGiaoDien.p1 != null)
    {
      if(DataJsonGiaoDien.u1 != "" && DataJsonGiaoDien.p1 != "")
      {
        //console.log("nahy vao user1 lu bien ra roi");
        WB_GD_User1 = DataJsonGiaoDien.u1;
        WB_GD_Pass1 = DataJsonGiaoDien.p1;
        console.log("user1: "+WB_GD_User1);
        console.log("pass1: "+WB_GD_Pass1);
      }  
    }
    if(DataJsonGiaoDien.u2 != null && DataJsonGiaoDien.p2 != null)
    {
      if(DataJsonGiaoDien.u2 != "" && DataJsonGiaoDien.p2 != "")
      {
          WB_GD_User2 = DataJsonGiaoDien.u2;
          WB_GD_Pass2 = DataJsonGiaoDien.p2;
      }  
    }
          
    if(DataJsonGiaoDien.u3 != null && DataJsonGiaoDien.p3 != null)
    {
      if(DataJsonGiaoDien.u3 != "" && DataJsonGiaoDien.p3 != "")
      {
          WB_GD_User3 = DataJsonGiaoDien.u3;
          WB_GD_Pass3 = DataJsonGiaoDien.p3;
      }  
    }
    if(DataJsonGiaoDien.u4 != null && DataJsonGiaoDien.p4 != null)
    {
      if(DataJsonGiaoDien.u4 != "" && DataJsonGiaoDien.p4 != "")
      {
          WB_GD_User4 = DataJsonGiaoDien.u4;
          WB_GD_Pass4 = DataJsonGiaoDien.p4;
      }  
    }
    if(DataJsonGiaoDien.u5 != null && DataJsonGiaoDien.p5 != null)
    {
      if(DataJsonGiaoDien.u5 != "" && DataJsonGiaoDien.p5 != "")
      {
          WB_GD_User5 = DataJsonGiaoDien.u5;
          WB_GD_Pass5 = DataJsonGiaoDien.p5;
      }  
    }
    //mode for each pin
    if(DataJsonGiaoDien.MP1 != null && DataJsonGiaoDien.MP2 != null && DataJsonGiaoDien.MP3 != null && DataJsonGiaoDien.MP4 != null)
    {
          if(DataJsonGiaoDien.MP1 != "" && DataJsonGiaoDien.MP2 != "" && DataJsonGiaoDien.MP3 != "" && DataJsonGiaoDien.MP4 != "")
          {
             ModeP1 = DataJsonGiaoDien.MP1;
             ModeP2 = DataJsonGiaoDien.MP2;
             ModeP3 = DataJsonGiaoDien.MP3;
             ModeP4 = DataJsonGiaoDien.MP4;
          }  
    }
    if(DataJsonGiaoDien.MP5 != null && DataJsonGiaoDien.MP6 != null)
    {
      if(DataJsonGiaoDien.MP5 != "" && DataJsonGiaoDien.MP6 != "")
      {
             ModeP5 = DataJsonGiaoDien.MP5;
             ModeP6 = DataJsonGiaoDien.MP6;
      }  
    }
  // lay cam bien nhiet
    if(DataJsonGiaoDien.Val != null)
    {
      if(DataJsonGiaoDien.Val != "")
      {
        ValSensor = DataJsonGiaoDien.Val;
        //document.getElementById("ptemp").innerHTML = ValSensor;
      }  
    }
    // lay trang thai tung chan ESP
    if(DataJsonGiaoDien.Pin1 != null && DataJsonGiaoDien.Pin2 != null && DataJsonGiaoDien.Pin3 != null && DataJsonGiaoDien.Pin4 != null)
    {
    WB_Pin1 = DataJsonGiaoDien.Pin1;
    WB_Pin2 = DataJsonGiaoDien.Pin2;
    WB_Pin3 = DataJsonGiaoDien.Pin3;
    WB_Pin4 = DataJsonGiaoDien.Pin4;
    }
    
    if(DataJsonGiaoDien.Pin5 != null && DataJsonGiaoDien.Pin6 != null && DataJsonGiaoDien.SS != null && DataJsonGiaoDien.NT != null)
    {
    WB_Pin5 = DataJsonGiaoDien.Pin5;
    WB_Pin6 = DataJsonGiaoDien.Pin6;
    WB_SS = DataJsonGiaoDien.SS;
    WB_NT = DataJsonGiaoDien.NT;
    }
  }
  
  function XuLyDataLan2()
  {
    console.log("vao xu ly lan 2");
    
    if(DataJsonGiaoDien.Val != null)
    {
    if(DataJsonGiaoDien.Val != "")
    {
      ValSensor = DataJsonGiaoDien.Val;  
      //document.getElementById('ptemp').innerHTML = ValSensor; 
    }   
    }
  
    if(DataJsonGiaoDien.Pin1 != null && DataJsonGiaoDien.Pin2 != null && DataJsonGiaoDien.Pin3 != null && DataJsonGiaoDien.Pin4 != null)
    {

    WB_Pin1 = DataJsonGiaoDien.Pin1;
      
    if(ModeP1 == "B")
    {
      if(WB_Pin1 == "1") 
      {
        if(PinCh2 == 1) // giu PinCh2 ko doi PinCh1
        {
          if(PinCh2OneTime)
          {
            PinCh2OneTime = 0;
            document.getElementById("respondP2V1").innerHTML = "transfer OK";
            checkTimeOut2 = 0;
            if(document.getElementById("No2notify").innerHTML != "Activate")
            document.getElementById("No2notify").innerHTML = "Activate";
          }
          //console.log("thuxem: "); 
          //console.log(document.getElementById("respondP2V2").innerHTML);
          if(document.getElementById("respondP2V2").innerHTML != "Impact")
          {
            $('#id_img_pin2').attr('src','/Bell');
            document.getElementById("respondP2V2").innerHTML = "Impact";
          }
        }
        else 
        {
          if(PinCh2OneTime)
          {
            PinCh2OneTime = 0;
            document.getElementById("respondP2V1").innerHTML = "transfer OK";
            checkTimeOut2 = 0;
            if(document.getElementById("No2notify").innerHTML != "Turn Off")
            document.getElementById("No2notify").innerHTML = "Turn Off";
          }
          if(document.getElementById("respondP2V2").innerHTML != "Turn Off")
          {
            $('#id_img_pin2').attr('src','/warning');
            document.getElementById("respondP2V2").innerHTML = "Turn Off"; 
          }
        }
      }  
      else if(WB_Pin1 == "0") 
      {
        if(PinCh2 == 1)   // giu PinCh2 ko doi PinCh1
        {
          if(PinCh2OneTime)
          {
            PinCh2OneTime = 0;
            document.getElementById("respondP2V1").innerHTML = "transfer OK";
            checkTimeOut2 = 0;
            if(document.getElementById("No2notify").innerHTML != "Activate")
              document.getElementById("No2notify").innerHTML = "Activate";
          }
          
          if(document.getElementById("respondP2V2").innerHTML != "No Impact")
          {
            $('#id_img_pin2').attr('src','/smoke');
            document.getElementById("respondP2V2").innerHTML = "No Impact";
          }
          
        }
        else {
          if(PinCh2OneTime)
          {
            PinCh2OneTime = 0;
            document.getElementById("respondP2V1").innerHTML = "transfer OK";
            checkTimeOut2 = 0;
            if(document.getElementById("No2notify").innerHTML != "Turn Off")
              document.getElementById("No2notify").innerHTML = "Turn Off";
          }
          
          if(document.getElementById("respondP2V2").innerHTML != "Turn Off")
          {
            $('#id_img_pin2').attr('src','/warning');
            document.getElementById("respondP2V2").innerHTML = "Turn Off";
          }
        }
      }
    }
 
    WB_Pin2 = DataJsonGiaoDien.Pin2;
    if(ModeP2 == "B")
    {
      if(WB_Pin2 == "1") 
      {
        if(PinCh3 == 1) // van giu PinCh3
        {
          if(PinCh3OneTime)
          {
              PinCh3OneTime = 0;
              document.getElementById("respondP3V1").innerHTML = "transfer OK";
              checkTimeOut3 = 0;
              if(document.getElementById("No3notify").innerHTML != "Activate")
              document.getElementById("No3notify").innerHTML = "Activate";
          }
          //console.log("thuxem: "); 
          //console.log(document.getElementById("respondP2V2").innerHTML);
          if(document.getElementById("respondP3V2").innerHTML != "Impact")
          {
            $('#id_img_pin3').attr('src','/Bell');
            document.getElementById("respondP3V2").innerHTML = "Impact";
          }
        }
        else 
        {
          if(PinCh3OneTime)
          {
              PinCh3OneTime = 0;
              document.getElementById("respondP3V1").innerHTML = "transfer OK";
              checkTimeOut3 = 0;
              if(document.getElementById("No3notify").innerHTML != "Turn Off")
              document.getElementById("No3notify").innerHTML = "Turn Off";
          }
          if(document.getElementById("respondP3V2").innerHTML != "Turn Off")
          {
              $('#id_img_pin3').attr('src','/warning');
              document.getElementById("respondP3V2").innerHTML = "Turn Off"; 
          }
        }
      }  
      else if(WB_Pin2 == "0") 
        {
        if(PinCh3 == 1)
        {
            if(PinCh3OneTime)
            {
            PinCh3OneTime = 0;
            document.getElementById("respondP3V1").innerHTML = "transfer OK";
            checkTimeOut3 = 0;
            if(document.getElementById("No3notify").innerHTML != "Activate")
              document.getElementById("No3notify").innerHTML = "Activate";
            }
            //console.log("thuxem2: "); 
            //console.log(document.getElementById("respondP3V2").innerHTML);
            if(document.getElementById("respondP3V2").innerHTML != "No Impact")
            {
            $('#id_img_pin3').attr('src','/smoke');
            document.getElementById("respondP3V2").innerHTML = "No Impact";
            }
        }
        else 
        {
            if(PinCh3OneTime)
            {
            PinCh3OneTime = 0;
            document.getElementById("respondP3V1").innerHTML = "transfer OK";
            checkTimeOut3 = 0;
            if(document.getElementById("No3notify").innerHTML != "Turn Off")
              document.getElementById("No3notify").innerHTML = "Turn Off";
            }
            if(document.getElementById("respondP3V2").innerHTML != "Turn Off")
            {
            $('#id_img_pin3').attr('src','/warning');
            document.getElementById("respondP3V2").innerHTML = "Turn Off";
            }
        }
      }
    }
      
    WB_Pin3 = DataJsonGiaoDien.Pin3;
    if(ModeP3 == "B")
    {
      if(WB_Pin3 == "1") 
      {
        if(PinCh4 == 1) // van giu PinCh4
        {
          if(PinCh4OneTime)
          {
            PinCh4OneTime = 0;
            document.getElementById("respondP4V1").innerHTML = "transfer OK";
            checkTimeOut4 = 0;
            if(document.getElementById("No4notify").innerHTML != "Activate")
            document.getElementById("No4notify").innerHTML = "Activate";
          }
          //console.log("thuxem: "); 
          //console.log(document.getElementById("respondP2V2").innerHTML);
          if(document.getElementById("respondP4V2").innerHTML != "Impact")
          {
            $('#id_img_pin4').attr('src','/Bell');
            document.getElementById("respondP4V2").innerHTML = "Impact";
          }
        }
        else 
        {
          if(PinCh4OneTime)
          {
            PinCh4OneTime = 0;
            document.getElementById("respondP4V1").innerHTML = "transfer OK";
            checkTimeOut4 = 0;
            if(document.getElementById("No4notify").innerHTML != "Turn Off")
            document.getElementById("No4notify").innerHTML = "Turn Off";
          }
          if(document.getElementById("respondP4V2").innerHTML != "Turn Off")
          {
            $('#id_img_pin4').attr('src','/warning');
            document.getElementById("respondP4V2").innerHTML = "Turn Off"; 
          }
        }
      }
      else if(WB_Pin3 == "0") 
      {
        if(PinCh4 == 1) // PinCh4 van giu
        {
            if(PinCh4OneTime)
            {
            PinCh4OneTime = 0;
            document.getElementById("respondP4V1").innerHTML = "transfer OK";
            checkTimeOut4 = 0;
            if(document.getElementById("No4notify").innerHTML != "Activate")
              document.getElementById("No4notify").innerHTML = "Activate";
            }
            //console.log("thuxem2: "); 
            //console.log(document.getElementById("respondP2V2").innerHTML);
            if(document.getElementById("respondP4V2").innerHTML != "No Impact")
            {
            $('#id_img_pin4').attr('src','/smoke');
            document.getElementById("respondP4V2").innerHTML = "No Impact";
            }
          
        }
        else 
        {
            if(PinCh4OneTime)
            {
            PinCh4OneTime = 0;
            document.getElementById("respondP4V1").innerHTML = "transfer OK";
            checkTimeOut4 = 0;
            if(document.getElementById("No4notify").innerHTML != "Turn Off")
              document.getElementById("No4notify").innerHTML = "Turn Off";
            }
            if(document.getElementById("respondP4V2").innerHTML != "Turn Off")
            {
            $('#id_img_pin4').attr('src','/warning');
            document.getElementById("respondP4V2").innerHTML = "Turn Off";
            }
        }
      }
    }
    WB_Pin4 = DataJsonGiaoDien.Pin4;
        if(ModeP4 == "B")
    {
      if(WB_Pin4 == "1") 
      {
        if(PinCh5 == 1) // van giu PinCh5
        {
          if(PinCh5OneTime)
          {
            PinCh5OneTime = 0;
            document.getElementById("respondP5V1").innerHTML = "transfer OK";
            checkTimeOut5 = 0;
            if(document.getElementById("No5notify").innerHTML != "Activate")
              document.getElementById("No5notify").innerHTML = "Activate";
          }
          //console.log("thuxem: "); 
          //console.log(document.getElementById("respondP2V2").innerHTML);
          if(document.getElementById("respondP5V2").innerHTML != "Impact")
          {
            $('#id_img_pin5').attr('src','/move_impact');
            document.getElementById("respondP5V2").innerHTML = "Impact";
          }
        }
        else 
        {
          if(PinCh5OneTime)
          {
            PinCh5OneTime = 0;
            document.getElementById("respondP5V1").innerHTML = "transfer OK";
            checkTimeOut5 = 0;
            if(document.getElementById("No5notify").innerHTML != "Turn Off")
              document.getElementById("No5notify").innerHTML = "Turn Off";
          }
          if(document.getElementById("respondP5V2").innerHTML != "Turn Off")
          {
            $('#id_img_pin5').attr('src','/warning');
            document.getElementById("respondP5V2").innerHTML = "Turn Off"; 
          }
        }
      }
      else if(WB_Pin4 == "0")
      {
        if(PinCh5 == 1) // van giu PinCh5
        {
          if(PinCh5OneTime)
          {
            PinCh5OneTime = 0;
            document.getElementById("respondP5V1").innerHTML = "transfer OK";
            checkTimeOut5 = 0;
            if(document.getElementById("No5notify").innerHTML != "Activate")
              document.getElementById("No5notify").innerHTML = "Activate";
          }
          //console.log("thuxem2: "); 
          //console.log(document.getElementById("respondP2V2").innerHTML);
          if(document.getElementById("respondP5V2").innerHTML != "No Impact")
          {
            $('#id_img_pin5').attr('src','/people_move');
            document.getElementById("respondP5V2").innerHTML = "No Impact";
          }
          
        }
        else 
        {
          if(PinCh5OneTime)
          {
            PinCh5OneTime = 0;
            document.getElementById("respondP5V1").innerHTML = "transfer OK";
            checkTimeOut5 = 0;
            if(document.getElementById("No5notify").innerHTML != "Turn Off")
              document.getElementById("No5notify").innerHTML = "Turn Off";
          }
          if(document.getElementById("respondP5V2").innerHTML != "Turn Off")
          {
            $('#id_img_pin5').attr('src','/warning');
            document.getElementById("respondP5V2").innerHTML = "Turn Off";
          }
        }
        
      }
    }
      
    }
    
    if(DataJsonGiaoDien.Pin5 != null && DataJsonGiaoDien.Pin6 != null && DataJsonGiaoDien.SS != null && DataJsonGiaoDien.NT != null)
    {
        //console.log("vao Pin 5-6 chua vay?");
        WB_Pin5 = DataJsonGiaoDien.Pin5;
        if(ModeP5 == "B")
    {
      if(WB_Pin5 == "1")
      {
          if(PinCh6 == 1)
          {
            if(PinCh6OneTime)
            {
                PinCh6OneTime = 0;
                document.getElementById("respondP6V1").innerHTML = "transfer OK";
                checkTimeOut6 = 0;
                if(document.getElementById("No6notify").innerHTML != "Activate")
                document.getElementById("No6notify").innerHTML = "Activate";
            }
            //console.log("thuxem: "); 
            //console.log(document.getElementById("respondP2V2").innerHTML);
            if(document.getElementById("respondP6V2").innerHTML != "Impact")
            {
                $('#id_img_pin6').attr('src','/Bell');
                document.getElementById("respondP6V2").innerHTML = "Impact";
            }
          }
          else 
          {
            if(PinCh6OneTime)
            {
                PinCh6OneTime = 0;
                document.getElementById("respondP6V1").innerHTML = "transfer OK";
                checkTimeOut6 = 0;
                if(document.getElementById("No6notify").innerHTML != "Turn Off")
                document.getElementById("No6notify").innerHTML = "Turn Off";
            }
            if(document.getElementById("respondP6V2").innerHTML != "Turn Off")
            {
                $('#id_img_pin6').attr('src','/warning');
                document.getElementById("respondP6V2").innerHTML = "Turn Off"; 
            }
          }
      }
      else if(WB_Pin5 == "0")
      {
        if(PinCh6 == 1)
        {
            if(PinCh6OneTime)
            {
              PinCh6OneTime = 0;
              document.getElementById("respondP6V1").innerHTML = "transfer OK";
              checkTimeOut6 = 0;
              if(document.getElementById("No6notify").innerHTML != "Activate")
                document.getElementById("No6notify").innerHTML = "Activate";
            }
            //console.log("thuxem2: "); 
            //console.log(document.getElementById("respondP2V2").innerHTML);
            if(document.getElementById("respondP6V2").innerHTML != "No Impact")
            {
              $('#id_img_pin6').attr('src','/distance');
              document.getElementById("respondP6V2").innerHTML = "No Impact";
            }
          
        }
        else 
        {
            if(PinCh6OneTime)
            {
              PinCh6OneTime = 0;
              document.getElementById("respondP6V1").innerHTML = "transfer OK";
              checkTimeOut6 = 0;
              if(document.getElementById("No6notify").innerHTML != "Turn Off")
                document.getElementById("No6notify").innerHTML = "Turn Off";
            }
            if(document.getElementById("respondP6V2").innerHTML != "Turn Off")
            {
              $('#id_img_pin6').attr('src','/warning');
              document.getElementById("respondP6V2").innerHTML = "Turn Off";
            }
        }
        
      }
    }
      
    WB_Pin6 = DataJsonGiaoDien.Pin6;
    if(ModeP6 == "B")
    {
      if(WB_Pin6 == "1")
      {
        if(PinCh7 == 1)
        {
          if(PinCh7OneTime)
          {
            PinCh7OneTime = 0;
            document.getElementById("respondP7V1").innerHTML = "transfer OK";
            checkTimeOut7 = 0;
            if(document.getElementById("No7notify").innerHTML != "Activate")
            document.getElementById("No7notify").innerHTML = "Activate";
          }
          //console.log("thuxem: "); 
          //console.log(document.getElementById("respondP2V2").innerHTML);
          if(document.getElementById("respondP7V2").innerHTML != "Impact")
          {
            $('#id_img_pin7').attr('src','/Bell');
            document.getElementById("respondP7V2").innerHTML = "Impact";
          }
        }
        else 
        {
          if(PinCh7OneTime)
          {
            PinCh7OneTime = 0;
            document.getElementById("respondP7V1").innerHTML = "transfer OK";
            checkTimeOut7 = 0;
            if(document.getElementById("No7notify").innerHTML != "Turn Off")
            document.getElementById("No7notify").innerHTML = "Turn Off";
          }
          if(document.getElementById("respondP7V2").innerHTML != "Turn Off")
          {
            $('#id_img_pin7').attr('src','/warning');
            document.getElementById("respondP7V2").innerHTML = "Turn Off"; 
          }
        }
      }
      else if(WB_Pin6 == "0")
      {
        if(PinCh7 == 1)
        {
          if(PinCh7OneTime)
          {
          PinCh7OneTime = 0;
          document.getElementById("respondP7V1").innerHTML = "transfer OK";
          checkTimeOut7 = 0;
          if(document.getElementById("No7notify").innerHTML != "Activate")
            document.getElementById("No7notify").innerHTML = "Activate";
          }
          //console.log("thuxem2: "); 
          //console.log(document.getElementById("respondP2V2").innerHTML);
          if(document.getElementById("respondP7V2").innerHTML != "No Impact")
          {
          $('#id_img_pin7').attr('src','/button');
          document.getElementById("respondP7V2").innerHTML = "No Impact"; 
          }
          
        }
        else {
          if(PinCh7OneTime)
          {
          PinCh7OneTime = 0;
          document.getElementById("respondP7V1").innerHTML = "transfer OK";
          checkTimeOut7 = 0;
          if(document.getElementById("No7notify").innerHTML != "Turn Off")
            document.getElementById("No7notify").innerHTML = "Turn Off";
          }
          if(document.getElementById("respondP7V2").innerHTML != "Turn Off")
          {
          $('#id_img_pin7').attr('src','/warning');
          document.getElementById("respondP7V2").innerHTML = "Turn Off";
          }
        }
        
      }
    }
    WB_SS = DataJsonGiaoDien.SS;
    WB_NT = DataJsonGiaoDien.NT;
    
    if(WB_SS == "1" && WB_NT== "0") //ss - normal
    { 
      if(document.getElementById("ResistorNotify").innerHTML != "Normal")
      {
        document.getElementById("ResistorNotify").innerHTML = "Normal";
        document.getElementById("ResistorNotify").style.color = "#0b8a00";
        $('#id_img_resis').attr('src','/impact');
      }
    }
    
    if(WB_SS == "0" ||  WB_NT== "1")
    {
      
      if(document.getElementById("ResistorNotify").innerHTML != "Error!")
      {
        document.getElementById("ResistorNotify").innerHTML = "Error!";
        document.getElementById("ResistorNotify").style.color = "red";
        $('#id_img_resis').attr('src','/ierror');
      } 
    }
    
  
    }
  
  }
  
    google.charts.load('current', {'packages':['gauge']});
    google.charts.setOnLoadCallback(drawChart);
    function drawChart() 
    {
          var data = google.visualization.arrayToDataTable([
          ['Label', 'Value'],
          ['Nhiệt độ', 80],
        ]);
   
    var optionsnhietdo = {
          min: 0, max: 150,
          width: 400, height: 120,
          redFrom: 130, redTo: 150,
          yellowFrom:100, yellowTo: 140,
          minorTicks: 5
        };
    
    var chart = new google.visualization.Gauge(document.getElementById('chart_nhietdo'));   
    
    chart.draw(data, optionsnhietdo);
    
    setInterval(function() {
      
    var datanhietdo = ValSensor;
          data.setValue(0, 1, datanhietdo);
          chart.draw(data, optionsnhietdo);
        }, 1000);
    
    
    }
 
 // pin 2 tro di
  function TURN_ON_PIN2()
    {
    console.log("tac dong GPIO1_ON!!!");
    console.log("ModeP2 " + ModeP2);
    if(document.getElementById("respondP2V1").innerHTML != "Disconnect")
    {
      if(ModeP1 == "B")
      {
        if(PinCh2 ==0)
        {
          readytime = 1; 
          ChannelPin[1] = 1; // dem phan timer dinh time
          document.getElementById("respondP2V1").innerHTML = "Sending..";
          checkTimeOut2 = 1; // chay vao phan timer
          PinCh2OneTime =1; // khoi dong de check timer cho phan truyen di success or faile
             
          PinCh2 = 1; // nhan biet kenh upload - off
          checkPinNo2 = 2; // cho dk duo ESP nhan ve
          statusPin2 = "1";// 
            
          var xhttp = new XMLHttpRequest();
          xhttp.open("GET", "/api/button?Pin="+ checkPinNo2 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin2, true); 
          xhttp.send();
        }
      }
    }
    
    }
  
  function TURN_OFF_PIN2()
  {
    console.log("tac dong GPIO1_OFF!!!");
    if(document.getElementById("respondP2V1").innerHTML != "Disconnect")
  {
    if(ModeP1 == "B")
    {
      if(PinCh2)
      {
        readytime = 1; 
        ChannelPin[1] = 1; // dem phan timer dinh time
        document.getElementById("respondP2V1").innerHTML = "Sending..";
        checkTimeOut2 = 1; // chay vao phan timer
        PinCh2OneTime =1; // khoi dong de check timer cho phan truyen di success or faile
        
        PinCh2 = 0; // nhan biet kenh upload
        checkPinNo2 = 2; // cho dk duo ESP nhan ve
        statusPin2 = "0";
        
         var xhttp = new XMLHttpRequest();
         xhttp.open("GET", "/api/button?Pin="+ checkPinNo2 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin2, true); 
         xhttp.send();
      }
    }
  }
    
 }
 function TURN_ON_PIN3()
 { 
    console.log("tac dong PIN3_ON!!!");
  if(document.getElementById("respondP3V1").innerHTML != "Disconnect")
  {
    if(ModeP2 == "B")
    {
      if(PinCh3 == 0)
      {
        readytime = 1;
        ChannelPin[2] = 1; // dem phan timer dinh time
        checkTimeOut3 = 1;  // chay vao phan timer
        PinCh3OneTime =1; // khoi dong de check timer cho phan truyen di success or faile
        document.getElementById("respondP3V1").innerHTML = "Sending..";
        
        PinCh3 = 1; // nhan biet kenh upload - off
        checkPinNo3 = 3; // cho dk duo ESP nhan ve
        statusPin3 = "1";// 
        
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "/api/button?Pin="+ checkPinNo3 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin3, true); 
        xhttp.send();
      }
    }
  }
    
 }
  function TURN_OFF_PIN3()
    {
        console.log("tac dong Pin3_OFF!!!");
    if(document.getElementById("respondP3V1").innerHTML != "Disconnect")
    {
      if(ModeP2 == "B")
      {
        if(PinCh3)
        {
          readytime = 1; // cho phep nhay vao phan timer de bat dau dem khi click
          ChannelPin[2] = 1; // phan dem timer chan nao
          checkTimeOut3 = 1; // phan check co phai a timeOut ko
          PinCh3OneTime = 1; // khoi dong 1 lan khi upload
          document.getElementById("respondP3V1").innerHTML = "Sending..";
          
          PinCh3 = 0; // trong phan upload ko tac dong
          checkPinNo3 = 3; // cho dk duo ESP nhan ve
          statusPin3 = "0";// 
          
          var xhttp = new XMLHttpRequest();
          xhttp.open("GET", "/api/button?Pin="+ checkPinNo3 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin3, true); 
          xhttp.send();
          
        }
      }
    }
    
    }
  function TURN_ON_PIN4()
    {
    if(document.getElementById("respondP4V1").innerHTML != "Disconnect")
    {
      if(ModeP3 == "B")
      {
        if(PinCh4 ==0)
        {
          readytime = 1; 
          ChannelPin[3] = 1; // dem phan timer dinh time
          document.getElementById("respondP4V1").innerHTML = "Sending..";
          checkTimeOut4 = 1; // chay vao phan timer
          PinCh4OneTime =1; // khoi dong de check timer cho phan truyen di success or faile
             
          PinCh4 = 1; // nhan biet kenh upload - off
          checkPinNo4 = 4; // cho dk duo ESP nhan ve
          statusPin4 = "1";// 
            
          var xhttp = new XMLHttpRequest();
          xhttp.open("GET", "/api/button?Pin="+ checkPinNo4 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin4, true); 
          xhttp.send();
        }
      }
    }
    }
  
  function TURN_OFF_PIN4()
  {
    if(document.getElementById("respondP4V1").innerHTML != "Disconnect")
    {
      if(ModeP3 == "B")
      {
        if(PinCh4)
        {
          readytime = 1; 
          ChannelPin[3] = 1; // dem phan timer dinh time
          document.getElementById("respondP4V1").innerHTML = "Sending..";
          checkTimeOut4 = 1; // chay vao phan timer
          PinCh4OneTime =1; // khoi dong de check timer cho phan truyen di success or faile
          
          PinCh4 = 0; // nhan biet kenh upload
          checkPinNo4 = 4; // cho dk duo ESP nhan ve
          statusPin4 = "0";
          
           var xhttp = new XMLHttpRequest();
           xhttp.open("GET", "/api/button?Pin="+ checkPinNo4 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin4, true); 
           xhttp.send();
        }
      }
    }
        
  }
  function TURN_ON_PIN5()
 {
  if(document.getElementById("respondP5V1").innerHTML != "Disconnect")
  {
    if(ModeP4 == "B")
    {
      if(PinCh5 ==0)
      {
        readytime = 1; 
        ChannelPin[4] = 1; // dem phan timer dinh time
        document.getElementById("respondP5V1").innerHTML = "Sending..";
        checkTimeOut5 = 1; // chay vao phan timer
        PinCh5OneTime =1; // khoi dong de check timer cho phan truyen di success or faile
           
        PinCh5 = 1; // nhan biet kenh upload - off
        checkPinNo5 = 5; // cho dk duo ESP nhan ve
        statusPin5 = "1";// 
          
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "/api/button?Pin="+ checkPinNo5 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin5, true); 
        xhttp.send();
      }
    }
  }
    
 }
  
  function TURN_OFF_PIN5()
  {
  if(document.getElementById("respondP5V1").innerHTML != "Disconnect")
  {
    if(ModeP4 == "B")
    {
      if(PinCh5)
      {
        readytime = 1; 
        ChannelPin[4] = 1; // dem phan timer dinh time
        document.getElementById("respondP5V1").innerHTML = "Sending..";
        checkTimeOut5 = 1; // chay vao phan timer
        PinCh5OneTime =1; // khoi dong de check timer cho phan truyen di success or faile
        
        PinCh5 = 0; // nhan biet kenh upload
        checkPinNo5 = 5; // cho dk duo ESP nhan ve
        statusPin5 = "0";
        
         var xhttp = new XMLHttpRequest();
         xhttp.open("GET", "/api/button?Pin="+ checkPinNo5 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin5, true); 
         xhttp.send();
      }
    }
  }
    
  }
  function TURN_ON_PIN6()
  {
  if(document.getElementById("respondP6V1").innerHTML != "Disconnect")
  {
    if(ModeP5 == "B")
    {
      if(PinCh6 ==0)
      {
        readytime = 1; 
        ChannelPin[5] = 1; // dem phan timer dinh time
        document.getElementById("respondP6V1").innerHTML = "Sending..";
        checkTimeOut6 = 1; // chay vao phan timer
        PinCh6OneTime =1; // khoi dong de check timer cho phan truyen di success or faile
           
        PinCh6 = 1; // nhan biet kenh upload - off
        checkPinNo6 = 6; // cho dk duo ESP nhan ve
        statusPin6 = "1";// 
          
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "/api/button?Pin="+ checkPinNo6 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin6, true); 
        xhttp.send();
      }
    }
  }
    
  }
  function TURN_OFF_PIN6()
  {
  if(document.getElementById("respondP6V1").innerHTML != "Disconnect")
  {
    if(ModeP5 == "B")
    {
      if(PinCh6)
      {
        readytime = 1; 
        ChannelPin[5] = 1; // dem phan timer dinh time
        document.getElementById("respondP6V1").innerHTML = "Sending..";
        checkTimeOut6 = 1; // chay vao phan timer
        PinCh6OneTime =1; // khoi dong de check timer cho phan truyen di success or faile
        
        PinCh6 = 0; // nhan biet kenh upload
        checkPinNo6 = 6; // cho dk duo ESP nhan ve
        statusPin6 = "0";
        
         var xhttp = new XMLHttpRequest();
         xhttp.open("GET", "/api/button?Pin="+ checkPinNo6 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin6, true); 
         xhttp.send();
      }
    }
  }
    
  }
  
  function TURN_ON_PIN7()
  {
  if(document.getElementById("respondP7V1").innerHTML != "Disconnect")
  {
    if(ModeP6 == "B")
    {
      if(PinCh7 ==0)
      {
        readytime = 1; 
        ChannelPin[6] = 1; // dem phan timer dinh time
        document.getElementById("respondP7V1").innerHTML = "Sending..";
        checkTimeOut7 = 1; // chay vao phan timer
        PinCh7OneTime =1; // khoi dong de check timer cho phan truyen di success or faile
           
        PinCh7 = 1; // nhan biet kenh upload - off
        checkPinNo7 = 7; // cho dk duo ESP nhan ve
        statusPin7 = "1";// 
          
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "/api/button?Pin="+ checkPinNo7 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin7, true); 
        xhttp.send();
      }
    }
  }
    
  }
  
  function TURN_OFF_PIN7()
  {
  if(document.getElementById("respondP7V1").innerHTML != "Disconnect")
  {
    if(ModeP6 == "B")
    {
      if(PinCh7)
      {
        readytime = 1; 
        ChannelPin[6] = 1; // dem phan timer dinh time
        document.getElementById("respondP7V1").innerHTML = "Sending..";
        checkTimeOut7 = 1; // chay vao phan timer
        PinCh7OneTime =1; // khoi dong de check timer cho phan truyen di success or faile
        
        PinCh7 = 0; // nhan biet kenh upload
        checkPinNo7 = 7; // cho dk duo ESP nhan ve
        statusPin7 = "0";
        
         var xhttp = new XMLHttpRequest();
         xhttp.open("GET", "/api/button?Pin="+ checkPinNo7 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin7, true); 
         xhttp.send();
      }
    }
  }
    
  }
  
   
  function stopCount()
  {
    clearTimeout(t);
    timer_is_on=0;
    
  } 
  
  
  function timedCount()
  {
  //console.log("nhay vao time readytime chua?");
    <!-- khi dem timeer thi chay trong phan nay -->
    t=setTimeout("timedCount()",1000);
  
  count_timer++;
  switch (count_timer)
  {
    case 3:
        count_timer=0;
        if(GlobalCheckTimeOut - LastGlobalCheckTimeOut > 0)
        {
          GlobalCheckTimeOut =0;
          LastGlobalCheckTimeOut = 0;
          LastGlobalCheckTimeOut = GlobalCheckTimeOut;
          if(document.getElementById("respondP1V1Temp").innerHTML == "Disconnect")
            document.getElementById("respondP1V1Temp").innerHTML = "";
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
          document.getElementById("respondP1V1Temp").innerHTML = "Disconnect"; 
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
    //console.log("nhay vao time readytime chua?");

    if(ModeP1 == "B")
    {
      if(ChannelPin[1])
      {
      itimeCh2++;
      if(checkTimeOut2)
      {
        if(itimeCh2 == 4)
        {
        document.getElementById("respondP2V1").innerHTML = "timeOut";
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "/api/button?Pin="+ checkPinNo2 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin2, true); 
        xhttp.send();
        console.log("gui lan lan 1 pin 2"); 
        }
        
        else if(itimeCh2 == 7)
        {
        itimeCh2 = 0;
        ChannelPin[1] = 0;
        document.getElementById("respondP2V1").innerHTML = "Disconnect";
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
    }
    
    if(ModeP2 == "B")
    {
      if(ChannelPin[2])
      {
        itimeCh3++;
        if(checkTimeOut3)
        {
          if(itimeCh3 == 4)
          {
            document.getElementById("respondP3V1").innerHTML = "timeOut";
            var xhttp = new XMLHttpRequest();
            xhttp.open("GET", "/api/button?Pin="+ checkPinNo3 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin3, true); 
            xhttp.send();
            console.log("gui lan lan 1 pin 3");
          }
          else if(itimeCh3 == 7)
          {
            itimeCh3 = 0;
            ChannelPin[2] = 0;
            document.getElementById("respondP3V1").innerHTML = "Disconnect";
          }
        }
        else 
        {
          if(itimeCh3 >2)
          {
            itimeCh3 = 0;
            ChannelPin[2] = 0;
            document.getElementById("respondP3V1").innerHTML = "";
          }
        }
      }
    }
    
    if(ModeP3 == "B")
    {
      if(ChannelPin[3])
      {
      itimeCh4++;
      if(checkTimeOut4)
      {
        if(itimeCh4 == 4)
        {
        document.getElementById("respondP4V1").innerHTML = "timeOut";
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "/api/button?Pin="+ checkPinNo4 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin4, true); 
        xhttp.send();
        console.log("gui lan lan 1 pin 4"); 
        }
        
        else if(itimeCh4 == 7)
        {
        itimeCh4 = 0;
        ChannelPin[3] = 0;
        document.getElementById("respondP4V1").innerHTML = "Disconnect";
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
    }
    
    if(ModeP4 == "B")
    {
      if(ChannelPin[4])
      {
      itimeCh5++;
      if(checkTimeOut5)
      {
        if(itimeCh5 == 4)
        {
        document.getElementById("respondP5V1").innerHTML = "timeOut";
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "/api/button?Pin="+ checkPinNo5 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin5, true); 
        xhttp.send();
        console.log("gui lan lan 1 pin 5"); 
        }
        
        else if(itimeCh5 == 7)
        {
        itimeCh5 = 0;
        ChannelPin[4] = 0;
        document.getElementById("respondP5V1").innerHTML = "Disconnect";
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
    }
    
    if(ModeP5 == "B")
    {
      if(ChannelPin[5])
      {
      itimeCh6++;
      if(checkTimeOut6)
      {
        if(itimeCh6 == 4)
        {
        document.getElementById("respondP6V1").innerHTML = "timeOut";
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "/api/button?Pin="+ checkPinNo6 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin6, true); 
        xhttp.send();
        console.log("gui lan lan 1 pin 6"); 
        }
        
        else if(itimeCh6 == 7)
        {
        itimeCh6 = 0;
        ChannelPin[5] = 0;
        document.getElementById("respondP6V1").innerHTML = "Disconnect";
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
    }
    
    if(ModeP6 == "B")
    {
      if(ChannelPin[6])
      {
      itimeCh7++;
      if(checkTimeOut7)
      {
        if(itimeCh7 == 4)
        {
        document.getElementById("respondP7V1").innerHTML = "timeOut";
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "/api/button?Pin="+ checkPinNo7 +"&U="+ WB_GD_User1+"&P="+ WB_GD_Pass1+ "&control=" + statusPin7, true); 
        xhttp.send();
        console.log("gui lan lan 1 pin 7"); 
        }
        
        else if(itimeCh7 == 7)
        {
        itimeCh7 = 0;
        ChannelPin[6] = 0;
        document.getElementById("respondP7V1").innerHTML = "Disconnect";
        } 
      }
      else 
      {
        if(itimeCh7 > 2)
        {
        itimeCh7 = 0;
        ChannelPin[6] = 0;
        document.getElementById("respondP7V1").innerHTML = "";
        } 
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
      //stopCount();
    }
    
  }
    <!-- t=setTimeout("timedCount()",1000); -->
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
