int logic() {

  switch (stateVar) {

    case (0): // day . lights are off + stay off
      {
        lightVar = 0;
        digitalWrite(leds[0, 1, 2, 3, 4, 5], LOW); // or should u write "leds[0, 1, 2, 3, 4, 5]" ?

        if (darkState == 1) {
          lightVar = !lightVar;
          stateVar = 1; // move to next case
          Serial.println("State 1 - it's dark !");
        }
      }
      break;

    case (1): // night . lights turn on
      {
        darkState = 1; //redundant ?
        lightVar = 1;
        digitalWrite(leds[0, 1, 2, 3, 4, 5], HIGH);
        int currentTime = millis();

        if (currentTime - prevLedTime >= 20000) {
          maxBrightness = 150;
          Serial.println("sleeeeeeepy");
          break;

        } else if (currentTime - prevLedTime >= 30000) {
          maxBrightness = 50;
          Serial.println("sleeeeeeeeeeeeeeeeeeeepy");
          break;
      }
    }
    break;
}
}
