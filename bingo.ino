void setup() {
  Serial.begin(9600);

}

void loop() {
  int randomnum = random(1, 100);
  
  Serial.println(randomnum);
  

}
