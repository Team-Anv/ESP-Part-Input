const char TimeZone[] PROGMEM = R"=====(
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
        <!-- <script type="text/javascript" src="data.json"></script> -->

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

    <body>
        <!--navigation-->
        <nav class="navbar navbar-expand-lg navbar-light bg-light">
            <a class="navbar-brand" href="#" style="margin-left: 50px;">
                <img src="/logo_anvgroup">
            </a>
          
            <div class="xnav_ngang">
              <ul class="navbar-nav mr-auto">
                <li class="nav-item active" style="margin-left: 15px; margin-right: 15px;">
                  <!-- <a class="nav-link" href="#" target="iframe_a">Home</a> -->
                </li>
                <li class="nav-item">
                 <a class="nav-link" href="/api/control"  target="iframe_a" style="margin-left: 15px; margin-right: 15px;">User Interface</a>
                </li>
                <li class="nav-item">
                    <!-- <a class="nav-link" href="/api/login" style="margin-left: 15px; margin-right: 15px;">LogOut</a> -->
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
                    <span><i class="bi bi-globe2"> Times Zone</i></span>
                  </div>
                </div>     
              </div>

              <form autocomplete="off" action="#" class="needs-validation" novalidate>
                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="timezone" style="margin: 10px;">Select Time Zone</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <select class="form-control" id="timezone">
                        <option value="Etc/GMT+12">(GMT-12:00) International Date Line West</option>
                        <option value="Pacific/Midway">(GMT-11:00) Midway Island, Samoa</option>
                        <option value="Pacific/Honolulu">(GMT-10:00) Hawaii</option>
                        <option value="US/Alaska">(GMT-09:00) Alaska</option>
                        <option value="America/Los_Angeles">(GMT-08:00) Pacific Time (US & Canada)</option>
                        <option value="America/Tijuana">(GMT-08:00) Tijuana, Baja California</option>
                        <option value="US/Arizona">(GMT-07:00) Arizona</option>
                        <option value="America/Chihuahua">(GMT-07:00) Chihuahua, La Paz, Mazatlan</option>
                        <option value="US/Mountain">(GMT-07:00) Mountain Time (US & Canada)</option>
                        <option value="America/Managua">(GMT-06:00) Central America</option>
                        <option value="US/Central">(GMT-06:00) Central Time (US & Canada)</option>
                        <option value="America/Mexico_City">(GMT-06:00) Guadalajara, Mexico City, Monterrey</option>
                        <option value="Canada/Saskatchewan">(GMT-06:00) Saskatchewan</option>
                        <option value="America/Bogota">(GMT-05:00) Bogota, Lima, Quito, Rio Branco</option>
                        <option value="US/Eastern">(GMT-05:00) Eastern Time (US & Canada)</option>
                        <option value="US/East-Indiana">(GMT-05:00) Indiana (East)</option>
                        <option value="Canada/Atlantic">(GMT-04:00) Atlantic Time (Canada)</option>
                        <option value="America/Caracas">(GMT-04:00) Caracas, La Paz</option>
                        <option value="America/Manaus">(GMT-04:00) Manaus</option>
                        <option value="America/Santiago">(GMT-04:00) Santiago</option>
                        <option value="Canada/Newfoundland">(GMT-03:30) Newfoundland</option>
                        <option value="America/Sao_Paulo">(GMT-03:00) Brasilia</option>
                        <option value="America/Argentina/Buenos_Aires">(GMT-03:00) Buenos Aires, Georgetown</option>
                        <option value="America/Godthab">(GMT-03:00) Greenland</option>
                        <option value="America/Montevideo">(GMT-03:00) Montevideo</option>
                        <option value="America/Noronha">(GMT-02:00) Mid-Atlantic</option>
                        <option value="Atlantic/Cape_Verde">(GMT-01:00) Cape Verde Is.</option>
                        <option value="Atlantic/Azores">(GMT-01:00) Azores</option>
                        <option value="Africa/Casablanca">(GMT+00:00) Casablanca, Monrovia, Reykjavik</option>
                        <option value="Etc/Greenwich">(GMT+00:00) Greenwich Mean Time : Dublin, Edinburgh, Lisbon, London</option>
                        <option value="Europe/Amsterdam">(GMT+01:00) Amsterdam, Berlin, Bern, Rome, Stockholm, Vienna</option>
                        <option value="Europe/Belgrade">(GMT+01:00) Belgrade, Bratislava, Budapest, Ljubljana, Prague</option>
                        <option value="Europe/Brussels">(GMT+01:00) Brussels, Copenhagen, Madrid, Paris</option>
                        <option value="Europe/Sarajevo">(GMT+01:00) Sarajevo, Skopje, Warsaw, Zagreb</option>
                        <option value="Africa/Lagos">(GMT+01:00) West Central Africa</option>
                        <option value="Asia/Amman">(GMT+02:00) Amman</option>
                        <option value="Europe/Athens">(GMT+02:00) Athens, Bucharest, Istanbul</option>
                        <option value="Asia/Beirut">(GMT+02:00) Beirut</option>
                        <option value="Africa/Cairo">(GMT+02:00) Cairo</option>
                        <option value="Africa/Harare">(GMT+02:00) Harare, Pretoria</option>
                        <option value="Europe/Helsinki">(GMT+02:00) Helsinki, Kyiv, Riga, Sofia, Tallinn, Vilnius</option>
                        <option value="Asia/Jerusalem">(GMT+02:00) Jerusalem</option>
                        <option value="Europe/Minsk">(GMT+02:00) Minsk</option>
                        <option value="Africa/Windhoek">(GMT+02:00) Windhoek</option>
                        <option value="Asia/Kuwait">(GMT+03:00) Kuwait, Riyadh, Baghdad</option>
                        <option value="Europe/Moscow">(GMT+03:00) Moscow, St. Petersburg, Volgograd</option>
                        <option value="Africa/Nairobi">(GMT+03:00) Nairobi</option>
                        <option value="Asia/Tbilisi">(GMT+03:00) Tbilisi</option>
                        <option value="Asia/Tehran">(GMT+03:30) Tehran</option>
                        <option value="Asia/Muscat">(GMT+04:00) Abu Dhabi, Muscat</option>
                        <option value="Asia/Baku">(GMT+04:00) Baku</option>
                        <option value="Asia/Yerevan">(GMT+04:00) Yerevan</option>
                        <option value="Asia/Kabul">(GMT+04:30) Kabul</option>
                        <option value="Asia/Yekaterinburg">(GMT+05:00) Yekaterinburg</option>
                        <option value="Asia/Karachi">(GMT+05:00) Islamabad, Karachi, Tashkent</option>
                        <option value="Asia/Calcutta">(GMT+05:30) Chennai, Kolkata, Mumbai, New Delhi</option>
                        <option value="Asia/Calcutta">(GMT+05:30) Sri Jayawardenapura</option>
                        <option value="Asia/Katmandu">(GMT+05:45) Kathmandu</option>
                        <option value="Asia/Almaty">(GMT+06:00) Almaty, Novosibirsk</option>
                        <option value="Asia/Dhaka">(GMT+06:00) Astana, Dhaka</option>
                        <option value="Asia/Rangoon">(GMT+06:30) Yangon (Rangoon)</option>
                        <option value="Asia/Bangkok" selected>(GMT+07:00) Bangkok, Hanoi, Jakarta</option>
                        <option value="Asia/Krasnoyarsk">(GMT+07:00) Krasnoyarsk</option>
                        <option value="Asia/Hong_Kong">(GMT+08:00) Beijing, Chongqing, Hong Kong, Urumqi</option>
                        <option value="Asia/Kuala_Lumpur">(GMT+08:00) Kuala Lumpur, Singapore</option>
                        <option value="Asia/Irkutsk">(GMT+08:00) Irkutsk, Ulaan Bataar</option>
                        <option value="Australia/Perth">(GMT+08:00) Perth</option>
                        <option value="Asia/Taipei">(GMT+08:00) Taipei</option>
                        <option value="Asia/Tokyo">(GMT+09:00) Osaka, Sapporo, Tokyo</option>
                        <option value="Asia/Seoul">(GMT+09:00) Seoul</option>
                        <option value="Asia/Yakutsk">(GMT+09:00) Yakutsk</option>
                        <option value="Australia/Adelaide">(GMT+09:30) Adelaide</option>
                        <option value="Australia/Darwin">(GMT+09:30) Darwin</option>
                        <option value="Australia/Brisbane">(GMT+10:00) Brisbane</option>
                        <option value="Australia/Canberra">(GMT+10:00) Canberra, Melbourne, Sydney</option>
                        <option value="Australia/Hobart">(GMT+10:00) Hobart</option>
                        <option value="Pacific/Guam">(GMT+10:00) Guam, Port Moresby</option>
                        <option value="Asia/Vladivostok">(GMT+10:00) Vladivostok</option>
                        <option value="Asia/Magadan">(GMT+11:00) Magadan, Solomon Is., New Caledonia</option>
                        <option value="Pacific/Auckland">(GMT+12:00) Auckland, Wellington</option>
                        <option value="Pacific/Fiji">(GMT+12:00) Fiji, Kamchatka, Marshall Is.</option>
                        <option value="Pacific/Tongatapu">(GMT+13:00) Nuku'alofa</option>
                      </select>
                    </div>
                  </div>
                </div>

                <div class="form-group form-check">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12"></div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <label class="form-check-label" style="margin-left: 10px;">
                        <input class="form-check-input" type="checkbox" id="ntp" name="remember">Enable NTP
                      </label>
                    </div> 
                  </div>
                </div>

                <div class="title_use_manament" style="margin: 20px; border-bottom: 2px solid gray;"></div>

                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="serveraddress" style="margin-left: 10px;">Server Address</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <input type="text" class="form-control" id="serveraddress" name="serveraddress" readonly>
                    </div> 
                  </div>
                </div>

                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="ntpport" style="margin-left: 10px;">NTP Port</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <input type="text" class="form-control" id="ntpport" name="ntpport" readonly>
                    </div> 
                  </div>
                </div>

                <div class="form-group">
                  <div class="row">
                    <div class="col-md-3 col-ms-3 col-xs-12">
                      <label for="sync" style="margin-left: 10px;">Synchronization Interval</label>
                    </div>
                    <div class="col-md-8 col-ms-8 col-xs-12">
                      <input type="text" class="form-control" id="sync" name="sync" readonly>
                    </div> 
                  </div>
                </div>

                <hr>
                <button id="summit_user" type="submit" class="btn btn-primary" style="margin-bottom: 20px;"><i class="bi bi-check2">Save</i></button>
              </form>
            </div>
          </div>
        </div>

        <script>
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
