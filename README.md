# christmas_tree
Just a smart Christmas tree


Ive created a small Christmastree with a ESP8266, and 25 SK6812 RGBWW 5050 LEDs.

This Tree is controlled by a button to switch between modes which controll the LEDs in diffrent colors or scenes.

Also you can set the mode over MQTT at the topic smarthome/Weihnachtsbaum/modus. Of course you can change the topics later in the codelines by yourself.

This tree is more or less a gimmik for Christmas.

Im not a professional coder, nor a professional hardware/pcb designer. In general it has to work and look good.


Overview of the MQTT-Topics:

<b>smarthome/Weihnachtsbaum/alarm</b> - if you publish a true, the tree with light up in diffrent flashing red lights like an alarm.<br>
<b>smarthome/Weihnachtsbaum/dauer_an</b> - if you publish a true to this topic, the LEDs will shine with full white brightness as long as you publish a false.<br>
<b>smarthome/Weihnachtsbaum/helligkeit</b> - you can publish a number between 0 and 255 to this topic, then the tree will set the brightness of the LEDs to the published number.<br>
<b>smarthome/Weihnachtsbaum/modus</b> - if you publish a number between 0 and 14, you can set the diffrent colors or scenes.<br>

0 - LEDs off<br>
2 - LEDs off<br>
4 - LEDs white<br>
6 - LEDs red<br>
8 - LEDS green<br>
10 - LEDs blue<br>
12 - LEDs yellow<br>
14 - LEDs rainbow<br>

<b>smarthome/Weihnachtsbaum/debug</b> - This topic only publishes the current mode of the tree. It doesnt react if you publish a message to it.<br><br><br>


Currently im using the tree with Node-Red and its Dashboard to control the tree.


In this repository you will find the code, the gerberfiles and the BOM for the Tree.


You have to put all the .ino files in one directory and open one file only. Then the Arduino IDE will open all other .ino files in diffrent tabs.

All of them need to be uploadet to your ESP.

Add your MQTT-Server IP at line 19 of esp8266_weihnachtsbaum.ino

Add your WiFi name and password at line 42 and 43 of esp8266_weihnachtsbaum.ino

Change the Topicnames at line 25 - 36 if you need to.

Change the IP-Adresses at line 45 - 48
