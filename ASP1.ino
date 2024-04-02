char lettersA[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.', ',', '‘', '?', '!', '+', '-', '*', '/', '='};
char * Vidco[] = {"-", "!!-", "!-*", "-!", "!", "!-!", "--", "!--", "!!", "-!!", "-*", "!!*", "!-", "!*", "*-", "*!", "-!*", "!*-", "!*!", "*", "**", "--*", "--!", "-*!", "!**", "---", " ", "*!!-", "*!!*", "*!-!", "*!--", "*!--", "*!-*", "*!*!", "*!*-", "*!**", "*-!!", "*!!!", "*!!", "*!-", "*-!", "*--", "*-*", "**!", "**-", "***", "*!*", "*---*"};
const String input;
const String output;
#define potentiometer A0
#define IR 2

void setup() {
Serial.begin(9600);
}
void loop() {
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  Serial.println("input Ascii or Vidco");
    while (!Serial.available()){};
    input = Serial.readString();
    Serial.println(input);
    if (input.charAt(0)=='-'){
      Serial.println(Vidco2ascii(input));
      pinMode(11, OUTPUT);
      sendDigital(11, input);
      output = Vidco2ascii(input);
      CommandMsg(output);
    }else if (input.charAt(0)=='!'){
      Serial.println(Vidco2ascii(input));
      pinMode(11, OUTPUT);
      sendDigital(11, input);
      output = Vidco2ascii(input);
      CommandMsg(output);
    }else if (input.charAt(0)=='*'){
      Serial.println(Vidco2ascii(input));
      pinMode(11, OUTPUT);
      sendDigital(11, input);
      output = Vidco2ascii(input);
      CommandMsg(output);
    }else{
      Serial.println(ascii2Vidco(input));
      output = ascii2Vidco(input);
      pinMode(10, OUTPUT);
      sendDigital(10, output);
      CommandMsg(input);
    }
}
char * char2Vidco(char c) {
  c = tolower(c);
  for (int i = 0; i < 27; i++){
    if (c == lettersA[i]){
    return Vidco[i];
    }
  }
}
String ascii2Vidco (String s){
  String Vidco = "";
  int len = s.length();
  for (int i = 0; i < len; i++){
    Vidco = Vidco + char2Vidco(s[i]);
    if (s[i] != ' '      &&
      i < len - 1    &&
      s[i + 1] != ' ') {
        Vidco = Vidco + '/';
      }
    }
   return Vidco; 
  }
char Vidco2char(String c) {
  for (int i = 0; i < 27; i++){
    if (c == Vidco[i]){
    return lettersA[i];
    }
  }
}
String Vidco2ascii (String m){
  int mi = 0;
  char c;
  String s;
  String r;
  while (mi < m.length()){
    c = m[mi];
    switch (c){
      case ' ':
        if (s.length()){
          r += Vidco2char(s);
          s = "";
        }
        r += ' ';
        break;
      case '/':
        if (s.length()){
          r += Vidco2char(s);
          s = "";
        }
        break;
       case '-':
       case '!':
       case '*':
        s += c;
        if (s.length() > 8) {
          //
        }
    }
    mi++;
  }
  if (s.length()){
    r += Vidco2char(s);
  }
  return r;
  }
void sendDigital(int p, String message){
  int dot = 20 + analogRead(potentiometer); //1 time unit
  int dot2 = 2 * dot;
  int dot4 = 4 * dot;
  digitalWrite(p, LOW);
  int d;
  for (int i = 0; i < message.length(); i++){
    d = dot;
    switch (message[i]){
      case '!':
        digitalWrite(p, HIGH);
        delay(dot);
        digitalWrite(p, LOW);
        break;
      case '-':
        digitalWrite(p, HIGH);
        delay(dot2);
        digitalWrite(p, LOW);
        break;
      case '*':
        digitalWrite(p, HIGH);
        delay(dot4);
        digitalWrite(p, LOW);
        break;
      case '/':
        d = d + dot; //2 time units
        break;
      case ' ':
        d = d + dot4; //5 time units
        break;
      default:
        d = dot * 20;
    }
    delay(d);
  }
}
void CommandMsg(String message){
  message.toUpperCase();
  if (message=="PR"){
        int val = analogRead(potentiometer);
        digitalWrite(5, val);
        delay(3000);
      }else if (message=="IRRR"){
        pinMode(IR, INPUT);
        if (digitalRead(IR)==HIGH){
          Serial.println("HIGH");
        }else if (digitalRead(IR)==LOW){
          Serial.println("LOW");
        }        
      }else if (message.charAt(0)=='L'){
        String green;
        String orange;
        String yellow;
        String red;
        green = message.charAt(1); 
        green = green + message.charAt(2);
        green = green + message.charAt(3);
        orange = message.charAt(4);
        orange = orange + message.charAt(5);
        orange = orange + message.charAt(6);
        yellow = message.charAt(7);
        yellow = yellow + message.charAt(8);
        yellow = yellow + message.charAt(9);
        red = message.charAt(10);
        red = red + message.charAt(11);
        red = red + message.charAt(12);
        Serial.println(green);
        Serial.println(orange);
        Serial.println(yellow);
        Serial.println(red);
        digitalWrite(10, green.toInt());
        digitalWrite(6, orange.toInt());
        digitalWrite(9, yellow.toInt());
        digitalWrite(5, red.toInt());
        delay(3000);
      }
}
