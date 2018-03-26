This is application template for [Esper].

# Development environment
* Source code projects are setup in [Platformio for Atom] community edition. All steps below assume this environment folders structure.

## Creating application with Esper:
* Git clone of the esper-app
* Open [platformio.ini] file and setup your board configuration.
* Select the board and include <Esper.hpp> file of the library:
```sh
#define USE_WEMOS_D1_MINI_BOARD     //select board
#define ESPER_DEBUG                 //enable Debug
#include "Esper.hpp"                //main H file
```
* Then during setup call:
```sh
ESPER_DEBUG_SETUP(74880);           //default ESP baud rate
Esper.begin();                      //init EEPROM
```
* During the loop you need to call only
```sh
Esper.run();
```
ESPER provides you 3 new callbacks that are already defined in the application template:

| Function | Description |
| :---: | --- |
| connected() | Triggered by ESPER when device setup is completed - it's connected to Wi-Fi and MQTT and connection parameters saved to EEPROM. MQTT init message sent. |
| disconnect() | Triggered if Wi-Fi, MQTT connection lost or ESPER OTA is initiated and device is going to reboot. |
| tictac() | Timer that is active only when device is online and ready. Intended to sensor readings. |

* Connect your ESP chip to USB port and Run build. For ESP-01 it takes 10 seconds to start AP.
* Connect to 'ESPER device' WiFi AP and open URL "esper.iot" to setup WiFi and MQTT settings.
* After save device will reboot and send esper/init MQTT message.

# Setting up MQTT environment
As ESPER communicates via MQTT here is proposed software stack that you can get to kick start your first DIY IoT project, like smart home:
* Orange PI Zero board with 8+ Gig SD card
* 8+ GB SD Card with (TODO: ready to burn SD card image):
  * Install [Armbian]
    * Don’t forget to [setup WiFi] ;)
  * Install [Mosquitto] MQTT broker (port 1880)
  * Install [Node-RED] (http://192.168.x.x:1880/)
    * Install [Node-RED Dashboard] extension and access it on http://192.168.x.x:1880/ui/
    * Import ESPER Node-RED test flow [test-mqtt.json] if ok then test connection to ESP with [esper-core.json]
  * (optional) To provide OTA images you may want to install [NginX] web server
    * then you will may need SSH client with SFTP to upload new firmware files into /var/www/html
Steps:
* Burn the SD card image and Boot Orange Pi Zero
* Burn your ESP8266 firmware with DHT11 example, reboot, connect to "ESPER device" network and configure it
* Now you should be able to see humidity and temperature charts.

License
----

MIT


[//]: #

[Esper]: https://github.com/palivoda/esper


[Armbian]: https://docs.armbian.com/User-Guide_Getting-Started/

[setup WiFi]: https://cloudvedas.com/how-to-use-nmtui-and-nmcli-tool-to-configure-network-in-redhat-linux/

[Mosquitto]: https://www.digitalocean.com/community/tutorials/how-to-install-and-secure-the-mosquitto-mqtt-messaging-broker-on-debian-8

[Node-RED]: https://diyprojects.io/install-node-red-orange-pi-running-armbian/#.Wrfo-2puaUm

[Node-RED Dashboard]: https://flows.nodered.org/node/node-red-dashboard

[test-mqtt.json]: /examples/node-RED/test-mqtt.json

[esper-core.json]: /examples/node-RED/esper-core.json

[NginX]: https://www.digitalocean.com/community/tutorials/how-to-install-linux-nginx-mysql-php-lemp-stack-on-debian-8

[Platformio for Atom]: http://docs.platformio.org/en/latest/ide/atom.html#installation
