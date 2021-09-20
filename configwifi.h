const char ConfigWifi_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8"> 
 <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<style>

 body {
      text-align:center;
      background-color:#e6fff5;
      color:Blue;
      font-family: Arial, Helvetica, sans-serif;
      }
          input {
            height:25px; 
            width:270px;
            font-size:20px;
            margin: 10px auto;
      border-radius:5px;
          }
      
      table
      {
      -moz-border-radius:10px;
      -webkit-border-radius:10px;
      border-radius:10px
  
      }
          #content {
            border: red solid 10px; 
            padding:5px;  
            height:auto; 
            width:auto; 
            border-radius:20px;
            margin: 0 auto;
      color: blue;
      background: #00ff99;

          }         
      .cssnhietdo{
  
              outline: none;
              margin: 15px 5px;
              width: 80px;
              height: 80px;
              border-radius: 50%;
              -moz-border-radius: 50%;
              -webkit-border-radius: 50%;
              color:black;
              font-size:20px;
              font-weight: bold;
        border: solid 5px #ffff66;
              background: #66ffff;
          }   
      
      .cssdoam{
              outline: none;
              margin: 15px 5px;
              width: 80px;
              height: 80px;
              border-radius: 50%;
              -moz-border-radius: 50%;
              -webkit-border-radius: 50%;
              color:black;
              font-size:20px;
              font-weight: bold;
        border: solid 5px #ffff66;
              background: #66ffff;
          }
      
    
      
      .cssden{
              outline: none;
              margin: 15px 5px;
              width: 80px;
              height: 80px;
              border-radius: 50%;
              -moz-border-radius: 50%;
              -webkit-border-radius: 50%;
              color:white;
              font-size:30px;
              font-weight: bold;
         border: solid 2px #23C48E;
              background: #23C48E;
        border: solid 5px #33ff33;
              background: #ff0000;
        
          }
      
      .cssquat{
              outline: none;
              margin: 15px 5px;
              width: 80px;
              height: 80px;
              border-radius: 50%;
              -moz-border-radius: 50%;
              -webkit-border-radius: 50%;
              color:white;
              font-size:30px;
              font-weight: bold;
         border: solid 2px #23C48E;
              background: #23C48E;
        border: solid 5px #33ff33;
              background: #ff0000;
          }     
          .button_quaylai{
            height:30px; 
            width:240px; 
            margin:10px 0;
            background-color:#3C89BC;
            border-radius:15px;
            outline:none;
            color:white;
            font-size:20px;
            font-weight: bold;
      border: solid 2px #ffff66;
      
          }   
      .button {
        display: inline-block;
        padding: 10px 25px;
        font-size: 40px;
        cursor: pointer;
        text-align: center;
        text-decoration: none;
        outline: none;
        color: back;
        background-color: #ffff00;
        border: none;
        border-radius: 20px;
        box-shadow: 0 9px #999;
        height:70px; 
        width:150px;
        border: solid 5px red;
      }

      .button:hover {background-color: #33ff33}

      .button:active {
        background-color: #ff0000;
        box-shadow: 0 5px #666;
        transform: translateY(4px);
      }
      
      tr
      {
        background-color:Orange;
        color:white;
        -moz-border-radius:10px;
        -webkit-border-radius:10px;
        border-radius:10px
      }
      th    
      {
       
        -moz-border-radius:10px;
        -webkit-border-radius:10px;
        border-radius:10px
        border: solid 5px Blue;
      }
      td    
      {
       
        -moz-border-radius:10px;
        -webkit-border-radius:10px;
        border-radius:10px
        border: solid 5px Blue;
      }
      .field-icon {
        float: right;
        margin-left: -25px;
        margin-top: -25px;
        position: relative;
        z-index: 2;
      }

      .container{
        padding-top:50px;
        margin: auto;
      }
      
</style>

<script type="text/javascript">

GetIP();
function GetIP()
{
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function ()
  {
    if(this.readyState == 4 && this.status == 200)
    {
      var DataVDK = xhttp.responseText;
      console.log("Dữ liệu VDK: " + DataVDK);
      if(DataVDK == "1")
      {
        
      }
      else
      {
         document.getElementById("ipesp").value = DataVDK;
      }
     
    }
  };
  
  xhttp.open("GET","/GetIP",true);      
  xhttp.send();
  setTimeout(function(){ GetIP() }, 1000);
}

function SEND()
{
  var ssid =  document.getElementById("ssid").value ;
  var pass =  document.getElementById("pass").value ;
  console.log("ssid: "+ ssid.length);
  console.log("pass: "+ pass.length);
  if(ssid.length == 0 && pass.length == 0)
  {
  
    alert("Vui Lòng Nhập Tên WiFi và Mật Khẩu WiFi!!!");
  }
  else 
  {
  
    var RXD = "{\"SSID\":\""+ssid+"\",\"PASS\":\""+pass+"\"}";
      var xhttp = new XMLHttpRequest();
      xhttp.open("GET","/configwifi?Json="+RXD,true);   
      xhttp.send();
  }
}
</script>
<body  style= "background-color: #ffffff;">   

<center>
<table width="500" height="400" border="1" cellpadding="1" align="center" class="center" style="margin: 0px auto;">
     <tr>
        <th  bgcolor="#66ff99" colspan="2"> <center> <font size="10"> <span style = "color: red">CONFIG WIFI</span></font></center></th>
   </tr>  
  
  
   <tr>
        <td  bgcolor="#FFFF00" colspan="1"> <center> <span style = "color: Blue"> <b> Name Wifi</b> </span> </center> </td>
        <td bgcolor="#FF00FF" colspan="1">
     <center>
        <input id="ssid" type="text" size="40" placeholder="Name Wifi" >
      </center>

        </td>
     </tr> 
   
   <tr>
        <td  bgcolor="#FFFF00" colspan="1"> <center> <span style = "color: Blue"> <b> Pass Wifi</b> </span> </center> </td>
        <td bgcolor="#FF00FF" colspan="1">
      <center>
        <input id="pass" type="text" size="40" placeholder="Pass Wifi" >
      </center>
  
        </td>
     </tr>
  
  
  
  <tr>
      <td  bgcolor="#FFFF00" colspan="1"> <center> <span style = "color: Blue"> <b> Send</b> </span> </center> </td>
      <td bgcolor="#FF00FF" colspan="1">
        <center>
          <button  type="button" class="button" onclick = "SEND()" style="height:100px; width:300px; ">Send</button>
        </center>
      </td>
    </tr>
  <tr>
      <td  bgcolor="#FFFF00" colspan="1"> <center> <span style = "color: Blue"> <b> IP ESP</b> </span> </center> </td>
      <td bgcolor="#FF00FF" colspan="1">
        <center>
          <input id="ipesp" type="text" size="40" placeholder="IP ESP" readonly>
          
        </center>
      </td>
    </tr>
    <tr style="margin-left">
   
      <th colspan="2"><button id="summit_user" type="submit" class="btn btn-primary" style="margin-left: 20px;"><a href="/rename/AP">Go to Rename wifi</a></button> </th>
    
    </tr>
  </table>
  
 </center>
</body>
</html>
)rawliteral";
