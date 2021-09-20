const char index_webshowip[] PROGMEM = R"rawliteral(
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
.center {
  margin-left: auto;
  margin-right: auto;
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
  
  xhttp.open("GET","/GetIP1",true);      
  xhttp.send();
  setTimeout(function(){ GetIP() }, 1000);
}

</script>
<body  style= "background-color: #ffcc00;">   

<center>
<table width="auto" height="auto" border="1" cellpadding="1" align="center" class="center" style="margin: 0px auto;">
  <tr>
      <td  bgcolor="#FFFF00" colspan="1"> <center> <span style = "color: Blue"> <b> IP ESP</b> </span> </center> </td>
      <td bgcolor="#FF00FF" colspan="1">
        <center>
          <input id="ipesp" type="text" size="500" style="height:100px; width:300px; " >
          
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
