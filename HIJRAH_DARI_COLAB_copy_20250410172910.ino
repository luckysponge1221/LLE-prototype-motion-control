#include <Servo.h>
#include <math.h>

Servo hipR;
Servo kneeR;
Servo ankleR;

Servo hipL;
Servo kneeL;
Servo ankleL;

int T = 100;           //# waktu 1 siklus (anggap aja 0-100%)
int T1 = 0;            //# jujur gatau tapi disetting 0 semua
int t = 0;             //# waktu mula-mula adalah 0
int o_1;
int o_2;
int o_3;
float x, xb, xc;
float sudutHipL, sudutHipR, sudutKneeL, sudutKneeR, sudutAnkleL, sudutAnkleR;
const float t_11 = 0.554*T;
const float t_12 = 0.894*T;
const float o_10 = 18.32;      //# derajat
const float o_11 = -17.09;
const float o_12 = 21.31;

const float t_21 = 0.148*T;
const float t_22 = 0.451*T;
const float t_23 = 0.751*T;
const float o_20 = 2.86;
const float o_21 = 19.07;
const float o_22 = 8.30;
const float o_23 = 58.01;

const float t_31 = 0.10*T;
const float t_32 = 0.25*T;
const float t_33 = 0.5*T;
const float o_30 = -10;
const float o_31 = 30;

const float pi = 3.14159;

float O_1(float x){ 
  if (x = 0; x < t_11){
    o_1 = o_10 - (o_10 - o_11)*sin((pi*x)/(2*t_11))*sin((pi*x)/(2*t_11));
  } 
  else if (x = t_11; x < t_12){
    o_1 = o_11 + (o_12 - o_11)*sin((pi*(x-t_11)/(2*(t_12-t_11))))*sin((pi*(x-t_11)/(2*(t_12-t_11))));
  } 
  else if (x = t_12; x <= T){
    o_1 = o_12 - (o_12 - o_10)*sin((pi*(x-t_12)/(2*(T-t_12))))*sin((pi*(x-t_12)/(2*(T-t_12))));
  }
  return o_1;
};

float O_2(float xb){
  if (xb = 0; xb < t_21){
    o_2 = o_20 + (o_21 - o_20)*sin((pi*xb)/(2*t_21))*sin((pi*xb)/(2*t_21));
  } 
  else if (xb = t_21; xb < t_22){
    o_2 = o_21 - (o_21 - o_22)*sin((pi*(xb-t_21)/(2*(t_22-t_21))))*sin((pi*(xb-t_21)/(2*(t_22-t_21))));
  } 
  else if (xb = t_22; xb < t_23){
    o_2 = o_22 + (o_23 - o_22)*sin((pi*(xb-t_22)/(2*(t_23-t_22))))*sin((pi*(xb-t_22)/(2*(t_23-t_22))));    
  } 
  else if (xb = t_23; xb <= T){
    o_2 = o_23 - (o_23 - o_20)*sin((pi*(xb-t_23)/(2*(T-t_23))))*sin((pi*(xb-t_23)/(2*(T-t_23))));
  } 
  return o_2;
}

float O_3(float xc){
  if (xc = 0; xc < t_31){
    o_3 = o_30 + (0 - o_30)*sin((pi*xc)/(2*t_31));
  } 
  else if (xc = t_31; xc < t_32){
    o_3 = 0;
  } 
  else if (xc = t_32; xc < t_33){
    o_3 = 0 + (o_31 - 0)*sin((pi*(xc-t_32))/(2*(t_33-t_32)))*sin((pi*(xc-t_32))/(2*(t_33-t_32)));
  } 
  else if (xc = t_33; xc <= T){
    o_3 = o_31 - (o_31 - o_30)*sin((pi*(xc-t_33)/(2*(T-t_33))))*sin((pi*(xc-t_33)/(2*(T-t_33))));
  } 
  return o_3;
}

//# HIP
float s_1(int k){
  float p = (k-T1)%T;
  float S_1 = O_1(p);
  return S_1;
}

//# KNEE
float s_2(int kb){
  float pb = (kb-T1)%T;
  float S_2 = O_2(pb);
  return S_2;
}

//# ANKLE
float s_3(int kc){
  float pc = (kc-T1)%T;
  float S_3 = O_3(pc); //# apprx sudut antara tumit dan tanah
  int br = 7;
  float S_3AL = s_1(kc) - s_2(kc) - br + S_3;
  // #S_3AR = sudutHipR - sudutKneeR - br + s_3(t-0.5*T)
  return S_3AL;
}

void setup() {
  // put your setup code here, to run once:
  hipR.attach(A0);    // attaches hip R Servo on pin A0 to the servo object
  kneeR.attach(A1);   // attaches knee R Servo on pin A1 to the servo object
  ankleR.attach(A2);  // attaches ankle R Servo on pin A2 to the servo object
  
  hipL.attach(A5);    // attaches hip L Servo on pin A3 to the servo object
  kneeL.attach(A4);   // attaches knee L Servo on pin A4 to the servo object
  ankleL.attach(A3);  // attaches ankle L Servo on pin A5 to the servo object

}

void loop() {
  // put your main code here, to run repeatedly:
  // pindah 
  for (t = 0; t <= T;){
    sudutHipL = s_1(t);
    sudutHipR = s_1(t-0.5*T);
    sudutKneeL = s_2(t);
    sudutKneeR = s_2(t-0.5*T);
    sudutAnkleL = s_3(t);
    sudutAnkleR = s_3(t-0.5*T);

    hipL.write(sudutHipL);
    hipR.write(sudutHipR);
    kneeL.write(sudutKneeL);
    kneeR.write(sudutKneeR);
    ankleL.write(sudutAnkleL);
    ankleR.write(sudutAnkleR);

    t += 1;
    delay(10);
  } 
}
