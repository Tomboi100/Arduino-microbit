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

  #define Serial_print(x) Serial.println(x);
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
  long athletenum;
  long bestath = 0;
  long besttime = 0;

  while (test == 1){
    Serial.println("input athlete number");
    athletenum = hfunc();
    //athletelist[whilecount] = athletenum;
    
   
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

    if (swimHours < 0){ // checks if swimhours is negative
      Serial.println("SwimHours is negative");
      break;
    }

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
     if (TotalTotal > besttime){
      besttime = TotalTotal;
      bestath = athletenum;
      }
        
    Serial_print(besttime); 
    
    Serial.print("Athlete ");
    Serial.println(athletenum);
    Serial.println("Would you like to Continue yes/no");
    ans = sfunc();
    if (ans == "yes"){
      Serial.println("Continuing");
      continue;
      
    }
    else if(ans == "no"){
      Serial.print("The best athlete was: ");
      Serial.print(bestath);
      Serial.println(" With a time of: ");
      Serial.print(besttime/SEC2);
      Serial.print("hr ");
      Serial.print(((besttime%SEC2))/SEC);
      Serial.print("min ");
      Serial.print((besttime%SEC2)%SEC);
      Serial.println("sec ");
      Serial.println("Good Bye");
      break;
    }
  }  
}

void loop() {
}
