void setup() {
  Serial.begin(9600);
  
  long swimHours;
  Serial.println("input swim hours");
  while (!Serial.available()){
    ;
  }
  swimHours = Serial.parseInt();
  Serial.println(swimHours);
  swimHours = swimHours*60*60;
  Serial.println(swimHours);
  
  long swimMin;
  Serial.println("input swim Min");
  while (!Serial.available()){
    ;
  }
  swimMin = Serial.parseInt();
  swimMin = swimMin*60;
  Serial.println(swimMin);

  long swimSec;
  Serial.println("input swim sec");
  while (!Serial.available()){
    ;
  }
  swimSec = Serial.parseInt();
  Serial.println(swimSec);

  long bikeHours;
  Serial.println("input bike hours");
  while (!Serial.available()){
    ;
  }
  bikeHours = Serial.parseInt();
  bikeHours = bikeHours*60*60;
  Serial.println(bikeHours);
  
  int bikeMin;
  Serial.println("input bike Min");
  while (!Serial.available()){
    ;
  }
  bikeMin = Serial.parseInt();
  bikeMin = bikeMin*60;
  Serial.println(bikeMin);

  long bikeSec;
  Serial.println("input bike sec");
  while (!Serial.available()){
    ;
  }
  bikeSec = Serial.parseInt();
  Serial.println(bikeSec);

  long runHours;
  Serial.println("input run hours");
  while (!Serial.available()){
    ;
  }
  runHours = Serial.parseInt();
  runHours = runHours*60*60;
  Serial.println(runHours);
  
  long runMin;
  Serial.println("input run Min");
  while (!Serial.available()){
    ;
  }
  runMin = Serial.parseInt();
  runMin = runMin*60;
  Serial.println(runMin);

  long runSec;
  Serial.println("input run sec");
  while (!Serial.available()){
    ;
  }
  runSec = Serial.parseInt();
  Serial.println(runSec);

  long swimTotal = swimHours + swimMin + swimSec;
  long bikeTotal = bikeHours + bikeMin + bikeSec;
  long runTotal = runHours + runMin + runSec;
  long TotalTotal = swimTotal + bikeTotal + runTotal;

  //Serial.println(swimTotal);
  //Serial.println(bikeTotal);
  //Serial.println(runTotal);
  //Serial.println(TotalTotal);

  long swimh = swimTotal/3600;
  long swimm = (swimTotal - (swimh*3600))/60;
  long swims = (swimTotal - (swimh*3600)) - (swimm*60);

  long bikeh = bikeTotal/3600;
  long bikem = (bikeTotal - (bikeh*3600))/60;
  long bikes = (bikeTotal - (bikeh*3600)) - (bikem*60);

  long runh = runTotal/3600;
  long runm = (runTotal - (runh*3600))/60;
  long runs = (runTotal - (runh*3600)) - (runm*60);

  long Totalh = TotalTotal/3600;
  long Totalm = (TotalTotal - (Totalh*3600))/60;
  long Totals = (TotalTotal - (Totalh*3600)) - (Totalm*60);

  //Serial.println(Totalh);
  //Serial.println(Totalm);
  //Serial.println(Totals);
  
  long swim[] = {swimh, swimm, swims};
  long bike[] = {bikeh, bikem, bikes};
  long run_[] = {runh, runm, runs};
  long total[] = {Totalh, Totalm, Totals};
  char *timep[] = {"hr ", "min ", "sec "};
  
  Serial.print("Swim Time: ");
  for (int s = 0; s < 3; s = s+1) {
      Serial.print(swim[s]);
      Serial.print(timep[s]);
  }
  Serial.println(" ");
  Serial.print("Bike Time: ");
  for (int b = 0; b < 3; b = b+1) {
      Serial.print(bike[b]);
      Serial.print(timep[b]);
  }
  Serial.println(" ");
  Serial.print("Run Time: ");
  for (int r = 0; r < 3; r = r+1) {
      Serial.print(run_[r]);
      Serial.print(timep[r]);
  }
  Serial.println(" ");
  Serial.print("Total Time: ");
  for (int t = 0; t < 3; t = t+1) {
      Serial.print(total[t]);
      Serial.print(timep[t]);
  }
}
void loop() {
}
