int hfunc(){
    int result;
    while (!Serial.available()){
    ;
    }
    result = Serial.parseInt();
    Serial.println(result);
    return result;
  }

void setup() {
  Serial.begin(9600);
  const int SEC = 60;
  const int SEC2 = 3600;
  long swimHours;
  long swimMin;
  long swimSec;
  long bikeHours;
  int bikeMin;
  long bikeSec;
  long runHours;
  long runMin;
  long runSec;
  
  Serial.println("input swim hours");
  swimHours = hfunc();
  
  Serial.println("input swim Min");
  swimMin = hfunc();

  Serial.println("input swim sec");
  swimSec = hfunc();
  
  Serial.println("input bike hours");
  bikeHours = hfunc();
  
  Serial.println("input bike Min");
  bikeMin = hfunc();

  Serial.println("input bike sec");
  bikeSec = hfunc();

  Serial.println("input run hours");
  runHours = hfunc();
  
  Serial.println("input run Min");
  runMin = hfunc();

  Serial.println("input run sec");
  runSec = hfunc();

  swimHours = swimHours*SEC2;
  swimMin = swimMin*SEC;
  bikeHours = bikeHours*SEC2;
  bikeMin = bikeMin*SEC;
  runHours = runHours*SEC2;
  runMin = runMin*SEC;
  long swimTotal = swimHours + swimMin + swimSec;
  long bikeTotal = bikeHours + bikeMin + bikeSec;
  long runTotal = runHours + runMin + runSec;
  long TotalTotal = swimTotal + bikeTotal + runTotal;

  String names[] = {"swim", "bike", "run", "Total"};
  long totalsec[] = {swimTotal, bikeTotal, runTotal, TotalTotal};
  
  for (int i = 0; i < 4; i++) {
      Serial.print(names[i]);
      Serial.print("time: ");
      Serial.print(totalsec[i]/SEC2);
      Serial.print("hr ");
      Serial.print(((totalsec[i]%SEC2))/SEC);
      Serial.print("min ");
      Serial.print((totalsec[i]%SEC2)%SEC);
      Serial.println("sec ");
  }  
}

void loop() {
}
