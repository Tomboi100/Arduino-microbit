long hfunc(){
    long result;
    while (!Serial.available()){
    ;
    }
    result = Serial.parseInt();
    Serial.println(result);
    return result;
  }
String sfunc(){
    String result;
    while (!Serial.available()){
    ;
    }
    result = Serial.readString();
    result.toLowerCase();
    Serial.println(result);
    return result;
  }
long c1func(long x, long y){
    long result;
    result = x*y;
    return result;
  }

  #define Serial_print(x) Serial.print(x);
void setup() {
  Serial.begin(9600);
  const int SEC = 60;
  const int SEC2 = 3600;
  long swimHours;
  long swimMin;
  long swimSec;
  long bikeHours;
  long bikeMin;
  long bikeSec;
  long runHours;
  long runMin;
  long runSec;
  String ans = "yes";
  int test = 1;
  int athletelist[] = {};
  int athletetimes[] = {};
  int athletenum;
  int whilecount = 0;

  while (test == 1){
    Serial.println("input athlete number");
    athletenum = hfunc();
    athletelist[whilecount] = athletenum;
    
   
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

    swimHours = c1func(swimHours, SEC2);
    swimMin = c1func(swimMin, SEC);
    bikeHours = c1func(bikeHours, SEC2);
    bikeMin = c1func(bikeMin, SEC);
    runHours = c1func(runHours, SEC2);
    runMin = c1func(runMin, SEC);
    long swimTotal = swimHours + swimMin + swimSec;
    long bikeTotal = bikeHours + bikeMin + bikeSec;
    long runTotal = runHours + runMin + runSec;
    long TotalTotal = swimTotal + bikeTotal + runTotal;
    athletetimes[whilecount] = TotalTotal;

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
     
    Serial_print(whilecount); 
    for(int i = 0; i < whilecount + 1; i++){
      Serial.println(athletelist[i]);
      Serial.println(athletetimes[i]); 
    }
     
    Serial.print("Athlete ");
    Serial.println(athletelist[whilecount]);
    Serial.println("Would you like to Continue yes/no");
    ans = sfunc();
    if (ans == "yes"){
      Serial.println("Continuing");
      whilecount = whilecount + 1;
      continue;
    }
    else if(ans == "no"){
      Serial.println("Good Bye");
      break;
    }
  }  
}

void loop() {
}
