const char RenameWifi[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8"> 
 <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<style>
body {font-family: Time New Roman;}
.tab {
    overflow: hidden;
    border: 1px solid #ccc;
    background-color: #FFCC00;
}

.button {
  display: inline-block;
  padding: 15px 25px;
  font-size: 24px;
  cursor: pointer;
  text-align: center;
  text-decoration: none;
  outline: none;
  color: #fff;
  background-color: #4CAF50;
  border: none;
  border-radius: 15px;
  box-shadow: 0 9px #999;
}
.button:hover {background-color: #3e8e41}
.button:active {
  background-color: #3e8e41;
  box-shadow: 0 5px #666;
  transform: translateY(4px);
}
</style>
<script type="text/javascript">




function SEND()
{
  var ressid =  document.getElementById("ssid").value ;
  var repass =  document.getElementById("pass").value ;
  console.log("ssid: "+ressid);
  console.log("pass: "+repass);
  var xhttp = new XMLHttpRequest();
  xhttp.open("GET","/renamewifi?ssid="+ressid+"&pass="+repass,true);      
  xhttp.send();
}
</script>
<body  style= "background-color: #000000;">       

<table width="500" height="400" border="4" cellpadding="1" align="center">
     <tr>
        <th  bgcolor="#66ff99" colspan="2"> <center> <font size="10"> <span style = "color: red">CHANGE NAME WIFI </span></font></center></th>
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
        <td  bgcolor="#FFFF00" colspan="1"> <center> <span style = "color: Blue"> <b> Pass WiFi</b> </span> </center> </td>
        <td bgcolor="#FF00FF" colspan="1">
      <center>
        <input id="pass" type="text" size="40" placeholder="Pass WiFi" >
      </center>
  
        </td>
     </tr> 
   
   <tr>
        <td  bgcolor="#FFFF00" colspan="1"> <center> <span style = "color: Blue"> <b> Send</b> </span> </center> </td>
        <td bgcolor="#FF00FF" colspan="1">
      <center>
         <button  type="button" class="button" onclick = "SEND()" style="height:50px; width:300px; ">Send</button>
      </center>
        </td>
     </tr>
  </table>

</body>
</html> 
)rawliteral";
