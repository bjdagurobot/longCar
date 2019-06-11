
/*==========================定义===========================*/
#include <PS2X_lib.h>  //库版本 v1.6  
PS2X ps2x;             //创建PS2控制格式
int error;
byte vibrate = 0;

int armSp =8;


const int leftR = 10; //左轮转动方向，引脚D11
const int leftS = 11; //左轮转动速度，引脚D6
const int rightR = 2; //右轮转动方向，引脚D10
const int rightS = 3; //右轮转动方向，引脚D5
int dataSp[]={10,255};        //小车速度
int sp=0;

int carSpL;
int carSpR;
/*==========================结束===========================*/

/*==========================初始化===========================*/
void setup() {
error = ps2x.config_gamepad(8,6,7,5, true, true);   //PS接线定义
//小车控制脚定义
pinMode(leftR,OUTPUT);
pinMode(leftS,OUTPUT);
pinMode(rightR,OUTPUT);
pinMode(rightS,OUTPUT);


carSpL=140;//左轮速度
carSpR=100;//右轮速度
carStop();
}
/*==========================结束===========================*/

/*==========================主循环===========================*/
void loop() 
{
if(error ==1 )return;
ps2x.read_gamepad(false, vibrate);

if(ps2x.Button(PSB_PAD_UP))     //小车控制
 {
 carGo(carSpL,carSpR);
 }
 else if(ps2x.Button(PSB_PAD_DOWN))
 {
 carBack(carSpL,carSpR);
 }
 else if(ps2x.Button(PSB_PAD_LEFT))
  {
 carLeft(carSpL,carSpR);
 }
 else if(ps2x.Button(PSB_PAD_RIGHT))
 {
 carRight(carSpL,carSpR);
 }
 else
{carStop();}
delay(20);

}


/*==========================结束===========================*/




/*==========================小车动作函数===========================*/
void carGo(int carSpL,int carSpR)
{
  //前进
  digitalWrite(leftR,HIGH);
  analogWrite(leftS,carSpL);
  digitalWrite(rightR,HIGH);
  analogWrite(rightS,carSpR);
}
void carBack(int carSpL,int carSpR)
{
   //后退
  digitalWrite(leftR,LOW);
  analogWrite(leftS,carSpL);
  digitalWrite(rightR,LOW);
  analogWrite(rightS,carSpR);
}
void carStop()
{
  //停止
  digitalWrite(leftS,LOW);
  digitalWrite(rightS,LOW);
}
void carLeft(int carSpL,int carSpR)
{
  //左转
  digitalWrite(leftR,LOW);
  analogWrite(leftS,carSpL);
  digitalWrite(rightR,HIGH);
  analogWrite(rightS,carSpR);
}
void carRight(int carSpL,int carSpR)
{
  //右转
  digitalWrite(leftR,HIGH);
  analogWrite(leftS,carSpL);
  digitalWrite(rightR,LOW);
  analogWrite(rightS,carSpR);
}
/*==========================结束===========================*/
