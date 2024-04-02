void setup() {
  Serial.begin(9600);
  testPythag();
}
void loop() {
  
}
float pythag (float a, float b){
  float c;
  c = sqrt(sq(a)+sq(b));
  return c;
}
void testPythag(){
  float a;
  Serial.print("Please enter a: ");
  while (!Serial.available()){;}
  a = Serial.parseFloat();
  Serial.println(a);
  float b;
  Serial.print("Please enter b: ");
  while (!Serial.available()){;}
  b = Serial.parseFloat();
  Serial.println(b);
  Serial.print("The length of the hyptenuse is: ");
  Serial.println(pythag(a,b));
}
