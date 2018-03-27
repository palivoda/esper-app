#define USE_WEMOS_D1_MINI_BOARD     // Uncomment the board you are using
#define ESPER_DEBUG                 // Comment this out to disable debug prints
#define ESPER_BEAT_S 3              //Sensor pull time
#include "Esper.hpp"

void setup() {
  ESPER_DEBUG_SETUP(74880);
  Esper.begin();
}

void loop() {
  Esper.run();
}

void connected() {
  E_DEBUG("Connected...");
}

void disconnecting() {
  E_DEBUG("Disconnecting...");
}


void tictac()
{

    String message = String("Lets go party! There are ") + millis() + " people!";

    E_DEBUG("Sending %s ", message.c_str());

    mqtt.publish("hello/world", message.c_str());

    E_DEBUG_ASSERT(millis() > 1000);

    if (millis() > 1000) {
      E_DEBUG("Party face control set :)");
      E_DEBUG_BREAK();
    }

}
