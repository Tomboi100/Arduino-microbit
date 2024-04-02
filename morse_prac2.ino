char lettersA[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '};
char * morseA[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "};

#define ledpin 5
#define phone_pin A2
#define pot_pin A0
#define button_pin 3

void setup() {
Serial.begin(9600);
pinMode(ledpin, OUTPUT);
Serial.println(char2morse('A'));
Serial.println(char2morse('z'));
String MyMorse = ascii2morse("SOS SOS");
Serial.println(MyMorse);
Serial.println(morse2char(".-"));

sendDigital(ledpin, MyMorse);
pinMode(phone_pin, OUTPUT);
pinMode(pot_pin, INPUT);
pinMode(button_pin, INPUT);
sendAnalog(phone_pin, MyMorse);
}

char * char2morse(char c) {
  c = tolower(c);
  for (int i = 0; i < 27; i++){
    if (c == lettersA[i]){
    return morseA[i];
    }
  }
}

String ascii2morse (String s){
  String morse = "";
  int len = s.length();
  for (int i = 0; i < len; i++){
    morse = morse + char2morse(s[i]);
    if (s[i] != ' '      &&
      i < len - 1    &&
      s[i + 1] != ' ') {
        morse = morse + '/';
      }
    }
   return morse; 
  }

void sendDigital(int p, String message){
  int dot = 300;
  int dot3 = 3 * dot;
  int dot5 = 5 * dot;
  digitalWrite(p, LOW);
  int d;
  for (int i = 0; i < message.length(); i++){
    d = dot;
    switch (message[i]){
      case '.':
        digitalWrite(p, HIGH);
        delay(dot);
        digitalWrite(p, LOW);
        break;
      case '-':
        digitalWrite(p, HIGH);
        delay(dot3);
        digitalWrite(p, LOW);
        break;
      case '/':
        d = d + dot;
        break;
      case ' ':
        d = d + dot5;
        break;
      default:
        d = dot * 20;
    }
    delay(d);
  }
}

void sendAnalog (int pin, String message){
  int dot = 500;
  int dot3 = 3 * dot;
  int dot5 = 5 * dot;
  int freq = 440;
  int d;
  for (int i = 0; i < message.length(); i++){
    d = dot;
    switch (message[i]){
      case '.':
        tone(pin, freq, dot);
        delay(dot);
        break;
      case '-':
        tone(pin, freq, dot3);
        delay(dot3);
        break;
      case '/':
        d = d + dot;
        break;
      case ' ':
        d = d + dot5;
        break;
      default:
        d = dot * 20;
    }
    delay(d);
  }
}

char morse2char(String c) {
  for (int i = 0; i < 27; i++){
    if (c == morseA[i]){
    return lettersA[i];
    }
  }
}

String morse2ascii (String s){
  String morse = "";
  int len = s.length();
  for (int i = 0; i < len; i++){
    morse = morse + char2morse(s[i]);
    if (s[i] != ' '      &&
      i < len - 1    &&
      s[i + 1] != ' ') {
        morse = morse + '/';
      }
    }
   return morse; 
  }

void loop() {
  //if (digitalRead(button_pin)){
    //tone(phone_pin, analogRead(pot_pin) * 4);
  //} else{
    //noTone(phone_pin);
  //}
}
