const char morse_a[] = ".-";
const char morse_b[] = "-...";
const char morse_c[] = "-.-.";
const char morse_d[] = "-..";
const char morse_e[] = ".";
const char morse_f[] = "..-.";
const char morse_g[] = "--.";
const char morse_h[] = "....";
const char morse_i[] = "..";
const char morse_j[] = ".---";
const char morse_k[] = "-.-";
const char morse_l[] = ".-..";
const char morse_m[] = "--";
const char morse_n[] = "-.";
const char morse_o[] = "---";
const char morse_p[] = ".--.";
const char morse_q[] = "--.-";
const char morse_r[] = ".-.";
const char morse_s[] = "...";
const char morse_t[] = "-";
const char morse_u[] = "..-";
const char morse_v[] = "...-";
const char morse_w[] = ".--";
const char morse_x[] = "-..-";
const char morse_y[] = "-.--";
const char morse_z[] = "--..";
const char morse_space[] = " ";
const char morse_asand[] = "&";

#define ledpin 5
#define phone_pin A2
#define pot_pin A0
#define button_pin 3

void setup() {
Serial.begin(9600);
pinMode(ledpin, OUTPUT);
//Serial.println(char2morse('A'));
//Serial.println(char2morse('Z'));
String MyMorse = ascii2morse("SOS SOS");
Serial.println(MyMorse);
sendDigital(ledpin, MyMorse);
pinMode(phone_pin, OUTPUT);
pinMode(pot_pin, INPUT);
pinMode(button_pin, INPUT);
sendAnalog(phone_pin, MyMorse);
}

char * char2morse(char c){
   switch(c){
    case 'A': return morse_a;
    case 'B': return morse_b;
    case 'C': return morse_c;
    case 'D': return morse_d;
    case 'E': return morse_e;
    case 'F': return morse_f;
    case 'G': return morse_g;
    case 'H': return morse_h;
    case 'I': return morse_i;
    case 'J': return morse_j;
    case 'K': return morse_k;
    case 'L': return morse_l;
    case 'M': return morse_m;
    case 'N': return morse_n;
    case 'O': return morse_o;
    case 'P': return morse_p;
    case 'Q': return morse_q;
    case 'R': return morse_r;
    case 'S': return morse_s;
    case 'T': return morse_t;
    case 'U': return morse_u;
    case 'V': return morse_v;
    case 'W': return morse_w;
    case 'X': return morse_x;
    case 'Y': return morse_y;
    case 'Z': return morse_z;
    case ' ': return morse_space;
    case '&': return morse_asand;
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

void loop() {
  if (digitalRead(button_pin)){
    tone(phone_pin, analogRead(pot_pin) * 4);
  } else{
    noTone(phone_pin);
  }
}
