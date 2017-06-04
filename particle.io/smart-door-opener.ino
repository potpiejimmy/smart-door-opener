// buzzer is connected to D7

int buzzer = D7;
int BUZZING_TIME = 2000;

int doBuzz = 0;

void setup()
{
   pinMode(buzzer, OUTPUT);
   Spark.function("buzz", triggerBuzz);
   digitalWrite(buzzer, LOW);
}

void loop()
{
    if (doBuzz) {
        digitalWrite(buzzer, HIGH);
        delay(BUZZING_TIME);
        digitalWrite(buzzer, LOW);
        doBuzz = 0;
    }
}

int triggerBuzz(String command)
{
    doBuzz = 1;
    return 1;
}
