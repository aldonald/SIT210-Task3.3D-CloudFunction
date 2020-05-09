int led = A5;

void flash() {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
}

void pat() {
    digitalWrite(led, HIGH);
    delay(2000);
    digitalWrite(led, LOW);
    delay(2000);
}

void wave(const char *x, const char *command) {
    Serial.printlnf("%s", command);
    // Solution to comparing found at https://stackoverflow.com/questions/10271268/comparing-const-char-to-a-string
    // This gave me alternate solutions until I compared the result to 0
    if (strcmp(command, "wave") == 0) {
        Serial.printlnf("GOT A WAVE");
        int a[] = {0, 1, 2};
        for (int n : a) {
            flash();
        }
    }
    if (strcmp(command, "pat") == 0) {
        Serial.printlnf("GOT A PAT");
        pat();
        pat();
    }
}

void setup() {
    Serial.begin(9600);
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", wave, ALL_DEVICES);
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
}



void loop() {

}