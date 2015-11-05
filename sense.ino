int touchSense() { // a function to check the touch sensor and return the result
  long start = millis();
  long touchVar =  cs_4_2.capacitiveSensor(30);
  delay(10);

  Serial.println(touchVar);
  if (touchVar >= touchThreshold) {
    touched++;
  } if (touched == 6) {
    touched = 0;
  }

  switch (touched) {
    case 0:
      digitalWrite(leds[1, 2, 3, 4, 5], LOW);
      digitalWrite(leds[0], HIGH);
      break;
    case 1:
      digitalWrite(leds[2, 3, 4, 5], LOW);
      digitalWrite(leds[0, 1], HIGH);
      break;
    case 2:
      digitalWrite(leds[3, 4, 5], LOW);
      digitalWrite(leds[0, 1, 2], HIGH);
      break;
    case 3:
      digitalWrite(leds[0, 1, 2, 3, 4, 5], HIGH);
      Serial.println("all lights on");
      break;
    case 4:
      // pattern once all are on
      anime01(); // regular speed
      animeSpeed = 600;
      break;
    case 5:
      // once touched, it turns off
      anime02(); // faster speed
      animeSpeed = 900;
      break;
    case 6:
      // now everything is turned off
      digitalWrite(leds[0, 1, 2, 3, 4, 5], LOW);
      lightVar = 0;
      break;
  }
}

int darkSense() {
  int darkVar = analogRead(A0);
  Serial.println(darkVar);
  if (darkVar < darkThreshold) {
    darkState = 0;
  } else {
    darkState = 1;
  }
}
