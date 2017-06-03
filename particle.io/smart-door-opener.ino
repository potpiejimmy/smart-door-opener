// buzzer is connected to D7

int buzzer = D7;
int BUZZING_TIME = 2000;

void setup()
{
   pinMode(buzzer, OUTPUT);
   Spark.function("buzz", doBuzzing);
   digitalWrite(buzzer, LOW);
}

void loop()
{
}

int doBuzzing(String command)
{
    digitalWrite(buzzer, HIGH);
    delay(BUZZING_TIME);
    digitalWrite(buzzer, LOW);
    return 1;
}
