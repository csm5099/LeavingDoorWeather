#define NOTE_C4 262
#define NOTE_E4 330
#define NOTE_G4 392

int tempo = 180;
int buzzer = 4;
// rain .-. .- .. -.
int rain[] = { NOTE_C4, 4, NOTE_E4, 4, NOTE_G4, 4, NOTE_C4, 16, NOTE_C4, 8, NOTE_C4, 16, NOTE_C4, 16, NOTE_C4, 8, NOTE_C4, 16, NOTE_C4, 16, NOTE_C4, 8, NOTE_C4, 16 };
// sun ... ..- -.
int sun[] = { NOTE_E4, 4, NOTE_G4, 4, NOTE_C4, 4, NOTE_E4, 16, NOTE_E4, 16, NOTE_E4, 16, NOTE_E4, 16, NOTE_E4, 16, NOTE_E4, 8, NOTE_E4, 8, NOTE_E4, 16 };
// dust -.. ..- ... -
int dust[] = { NOTE_G4, 4, NOTE_E4, 4, NOTE_C4, 4, NOTE_G4, 8, NOTE_G4, 16, NOTE_G4, 16, NOTE_G4, 16, NOTE_G4, 16, NOTE_G4, 8, NOTE_G4, 16, NOTE_G4, 16, NOTE_G4, 16, NOTE_G4, 8 };
int notes = 0;
int wholenote = 0;
int divider = 0;
int noteDuration = 0;

void makeSound(int melody[]) {
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5;
    }
    tone(buzzer, melody[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(buzzer);
  }
  delay(500);
}

void weatherSound(int weather) {
  if (weather == 1) {
    notes = sizeof(rain) / sizeof(rain[0]) / 2;
    wholenote = (60000 * 4) / tempo;
    makeSound(rain);

  } else if (weather == 2) {
    notes = sizeof(sun) / sizeof(sun[0]) / 2;
    wholenote = (60000 * 4) / tempo;
    makeSound(sun);

  } else if (weather == 3) {
    notes = sizeof(dust) / sizeof(dust[0]) / 2;
    wholenote = (60000 * 4) / tempo;
    makeSound(dust);

  } else {
    ;
  }
}
