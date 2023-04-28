#include <includes.h> 

int CHGCi;
//�趨������
#define right1 analog(1)  //��ǰ
#define right2 analog(2)
#define right3 analog(3)
#define right4 analog(4)
#define left4 analog(5)
#define left3 analog(6)
#define left2 analog(7)
#define left1 analog(8)//��ǰ
#define mid_left analog(17) //����
#define mid_right analog(18)//����
#define hdy analog(19)//ǰ����-1
#define hdy analog(20)//ǰ����-2
#define cz1 digital(1) 
#define cz2 digital(2)
#define cz3 digital(3)
#define W 300  //��ɫ
#define Y 100//��ɫ
#define B 100//��ɫ
#define G 100//��ɫ����ɫ��
#define R 100//��ɫ
#define BORD 400 //����
#define 	VOIDD 25  // ����
//�������� 
void fzjs(void);//��ֵ����
void fzxs(void);//��ֵ��ʾ
void mdcs(void);//������
void djcs (void);//�������
void run(int n, int p);
void line(int base);
void station1(int time1, int time2);
void motion(void);
void tai(int left, int right, int time1, int time2);
void turn_left(void);
void turn_right(void);
void start(void);
void run_utill(int speed, char color, char direction);
void line_black_brige(int base);
void from_0_to_0(void);
void from_0_to_1(void);
void from_1_to_2(void);
void from_2_to_3(void);
void from_3_to_4(void);
void peng180(int time);

int hdb[28],hdh[28],fz[28],hdc[28];//hdb[28]��ɫ�Ҷ�ֵ��hdh[28]�̵�̺�Ҷ�ֵ��fz[28]��ֵ��hdc[28]�ҶȸߵͲ�ֵ��
int i,v=0,k=0,znz=0,z=0,d=34,b=0;
//int x=50;
//int y=50:

void mainX1(void)
{ 
test();
motor( 1,20  );
}

void run(int m,int p)//������ʻ�ٶ�
{
	int rate = 1;
 motor(1,m * rate);
 motor(2,p * rate);
}
void line(int base)//ѭ�� �ٶȻ�׼
{
     if( analog(4)>W&&analog(5)>W )   
     {
          run(base,base);   
      }
     else if(analog(4)<W&&analog(5)>W) 
     { 
      run(0.9*base,1.1*base);   
     }
     else if(analog(4)>W&&analog(5)<W)   
     { 
      run(1.1*base,0.9*base);    
     }
     else if(analog(3)<W&&analog(6)>W) 
     { 
      run(0.8*base,1.3*base);   
     }
     else if(analog(3)>W&&analog(6)<W)   
     {  
      run(1.3*base,0.8*base);    
     }
     else if(analog(2)<W&&analog(7)>W)  
     {  
      run(0.5*base,1.5*base);   
     }
     else if(analog(7)<W&&analog(2)>W)   
     {  
      run(1.5*base,0.5*base);    
     }
     else if(analog(1)>	W&&analog(8)<W)
     {
      run(1.5*base,0.4*base);
     }
     else if(analog(8)>W&&analog(1)<W)
     {
      run(0.4*base,1.5*base);
     }
     //else{
     //	 run(-20,-20);
     //	 delay(0,200);
     //	 run(0,0);
     //	 delay(0,200);
 //    }
}
void station1(int time1, int time2){//��ͷ�ٶ�60��ʱ��t1+t2
	run(0,0);
	delay(0,500);
	servo(1,880);delay(0,300);//���1?
	motor(1, 60);motor(2 , -60);delay(time1,time2);//תȦ�ٶ���ʱ��
	servo(1,200);delay(0,100);//���1?
	run(0,0);
	delay(0,500);
}
void motion(void){//���ֶ��� ��ɱ�־
//	servo(2,980 );delay( 0,100);		// ������??????
  	servo(3,800 );servo(4, 800);servo(5,800 );delay(0 ,300);//ͷ������ҡ�ڣ��ֱ����°ڶ�����3/4/5�Ŷ��100<��ֵ<800��
    servo(3,200 );servo(4, 200);servo(5,200 );delay(0 ,300);//ͷ������ҡ�ڣ��ֱ����°ڶ���3/4/5�Ŷ��100<��ֵ<800��
	servo(3,800 );servo(4, 800);servo(5,800 );delay(0 ,300);//ͷ������ҡ�ڣ��ֱ����°ڶ�����3/4/5�Ŷ��100<��ֵ<800��
    servo(3,200 );servo(4, 200);servo(5,200 );delay(0 ,300);//ͷ������ҡ�ڣ��ֱ����°ڶ���3/4/5�Ŷ��100<��ֵ<800��
 // servo(2,500 );delay( 0,100);		// ������
}
void tai(int left, int right, int time1, int time2){
	run(left,right);
	delay(0, 500);
	run(0,0);
	motion();
	station1(time1, time2);//��ͷ����
	run(30,30);
	delay(0,450);//��̨
	run(0,0);
	delay(0,200);
	if(!(analog(1)>W||analog(2)>W||analog(2)>W||analog(3)>W||analog(4)>W||analog(5)>W||analog(6)>W||analog(8)>W))
		while(!(analog(2)>W||analog(3)>W||analog(4)>W||analog(5)>W||analog(6)>W||analog(7)>W))
			run(20,-20);//tai��������������+��ͷ+��̨�����??????
}
void tai2(int left, int right, int time1, int time2){
	run(left,right);
	delay(0, 500);//��ֹ̨ͣλ��
	run(0,0);
	motion();//���ֱ�־����
	run(0,0);
	delay(0,500);//�������
	servo(1,880);delay(0,300);//���1?
	motor(1, 60);motor(2 , -60);delay(time1,time2);//��ͷ��Ƕ�
	servo(1,200);delay(0,100);//���1???
	run(0,0);
	delay(0,500);//�������
	run(30,30);
	delay(0,450);//��̨
	run(0,0);
	delay(0,200);//ֹͣ�ҷ���У׼
	if(!(analog(1)>W||analog(2)>W||analog(2)>W||analog(3)>W||analog(4)>W||analog(5)>W||analog(6)>W||analog(8)>W))
		while(!(analog(2)>W||analog(3)>W||analog(4)>W||analog(5)>W||analog(6)>W||analog(7)>W))
			run(20,-20);
}

void turn_left(void){
	run(0,0);
	delay(0,200);
	motor(1, -10);motor(2 , 50);delay(0,300);// ��ת	
}
void turn_right(void){
	run(0,0);
	delay(0,200);
	motor( 1, 50);motor(2 , -10);delay(0,300);// ��ת	
}

void line_black_brige(int base){
//	servo(1,200 );delay( 0,500);
	while(!(analog(1)>W||analog(2)>W||analog(3)>W||analog(4)>W||analog(5)>W||analog(6)>W||analog(7)>W||analog(8)>W)){
	     run(base,base);
	     if(analog(6)>50&&analog(1)<50&&analog(2)<50&&analog(3)<50){
	      	run(1.4*base,0.2*base);
	     }
	     else if(analog(8)<50&&analog(7)<50&&analog(6)<50&&analog(3)){
	      	run(0.2*base,1.4*base);
	     } 
		 else if(analog(6)>50&&analog(3)<50){
	      	run(1.4*base,0.2*base);
	     }
	     else if(analog(6)<50&&analog(3)){
	      	run(0.2*base,1.4*base);
	     }
//	     else if(analog(7)>50&&analog(3)<50){
//	      	run(1.4*base,0.2*base);
//	     }
//	     else if(analog(6)<50&&analog(2)>50){
//	      	run(0.2*base,1.4*base);
//	     }
//	    else if(analog(1)<40&&analog(8)<40){
//	    		run(2*base, 2*base);
//	    }
     }
//     servo(1,500 );delay( 0,500);
//     if(!(analog(1)>W||analog(2)>W||analog(3)>W||analog(4)>W||analog(5)>W||analog(6)>W||analog(7)>W||analog(8)>W)){
//   	 run(20,-20);
//   	 delay(0,200);
//     }
//     if(!(analog(1)>W||analog(2)>W||analog(3)>W||analog(4)>W||analog(5)>W||analog(6)>W||analog(7)>W||analog(8)>W)){
//     	 run(-20,20);
//     	 delay(0,400);
//     }
}
void start(void){//��ʼ�������ٶ�30������200ms
	while(1){
		if(analog(19)>BORD){
			delay(0,300);
			run(30,30);
			delay(0, 200);
			break;
		}
	}
}
void run_utill(int speed, char color, char direction){//ѭ����ֹ�ж� A-all L-left R-right B-black W-white
	if(color=='B'&&direction=='A'){
		while(1){
			line(speed);
			if(analog(1)<B&&analog(2)<B&&analog(3)<B&&analog(4)<B&&analog(5)<B&&analog(6)<B&&analog(7)<B&&analog(8)<B){
				break;
			}
		}
	}
	else if(color=='W'&&direction=='A'){//ȫҪ
		while(1){
			line(speed);
			if(analog(1)>400&&analog(2)>400&&analog(3)>400&&analog(4)>400&&analog(5)>400&&analog(6)>400&&analog(7)>400&&analog(8)>400){
				break;
			}
		}
	}
	else if(color=='W'&&direction=='L'){//ֻҪl
		while(1){
			line(speed);
			if(analog(6)>400&&analog(7)>400&&analog(8)>400){
				break;
			}
		}
	}
	else if(color=='W'&&direction=='R'){//ֻҪr
		while(1){
			line(speed);
			if(analog(1)>400&&analog(2)>400&&analog(3)>400){
				break;
			}
		}
	}
}
void peng180(int time){//ײ�����ͷ
	run(30,30);
	delay(0,500);
	run(0,0);
	delay(0,300);
	run(-30,-30);
	delay(0,300);
	station1(0, time);
}//ײ��

void from_0_to_0(){
	start();//����ٶ���ʮ
	run_utill(30,'W','R');//��һ��ʮ��·���жϣ�
	run(50,50);
	delay(0,200);//��һ��ʮ�ֱ�����
	run_utill(60,'W','R');//?
	run(40,40);
	delay(0,100);
	run_utill(60,'W','R');//?
	run(40,40);
	delay(0,100);
	run_utill(40,'W','A');//����ֱ�߾�ͷ����·���ж�
	turn_right();
	run_utill(40,'B','A');//��ʻ��taiǰ�ж�
	tai(30,30,0,125);//��̨�ٶ� 30 �� ��ͷʱ�� 125 ms
}
void from_0_to_1(void){
	run_utill(25,'W','A');//��һ������·�ڣ���ԲȦҪע����?���ٰ�?
	run(60,60);
	delay(0,200);
	run_utill(30,'W','L');//�߳�ԲȦ�ж�
	run(0,0);//�������
	turn_left();
	run_utill(30,'B','A');//��̨������ʶ��B
	tai(30,30,0,120);
}
void from_1_to_2(void){
	run_utill(30,'W','A');//��Ȧ��ת
	turn_left();
	run_utill(30,'W','R');
	turn_right();//��Ȧ
	run_utill(10,'	W','L');//ֻҪ���?
	turn_left();
	run_utill(30,'	W','R');
	turn_right();//���ȳ�ˮ
	run_utill(30,'	W','A');//��1ʮ��·��
	run(60,60);
	delay(0,200);
	run_utill(30,'W','R');
	turn_right();//��̨����
	run_utill(30,'B','A');//��tai
	run(60,60);
	delay(0,300);
	run(0,0);
	delay(0,500);
	motion();// �ϸ�̨����ʾ��
}
void from_2_to_3(void){
	run(15,15);
	delay(0,200);//�¸�̨
	run_utill(25,'W','R');
	turn_right();
	run_utill(30,'W','A');
	turn_left();
	run_utill(30,'B','A');
	tai(30,30,0,130);// ��������
}
void from_3_to_4(void){
	run_utill(20,'W','L');
	turn_left();
	run_utill(30,'W','A');
	turn_left();
	peng180(140);//ײ�����ͷ
	run(40,40);
	delay(0,500);
	if(!(analog(1)>W||analog(2)>W||analog(2)>W||analog(3)>W||analog(4)>W||analog(5)>W||analog(6)>W||analog(8)>W))
		while(!(analog(2)>W||analog(3)>W||analog(4)>W||analog(5)>W||analog(6)>W||analog(7)>W))
			run(-20,20);
	run_utill(30,'W','L');
	turn_left();
	peng180(140);
	run(30,30);
	delay(0,250);
	turn_left();//?³��pengû��
	run_utill(40,'W','A');
	turn_right();// ���ȳ�ˮ��ʼ
	run_utill(20,'W','A');
	turn_right();// 4�ȳ�ˮ��ʼ
	run_utill(40,'W','R');
	turn_right();
	run_utill(30,'W','A');//?������ת��ʮ��·��ʶ��
	run(30,30);
	delay(0,100);
	run_utill(20,'B','A');// ����ʶ��
	line_black_brige(20); 
	run_utill(20,'W','R');
	turn_right();
	run_utill(30,'B','A');//����λ��
	run(60,60);
	delay(0,300);
	run(0,0);
}
void mainX2(void){//·����װ
	start();
	from_0_to_0();
	from_0_to_1();
	from_1_to_2();
	from_2_to_3();
	from_3_to_4();	
}

void fzjs()//��ֵ����
 	 {int i=0;
 	 for(i=0;i<28;i++)
 	 {	hdb[i]=record_analog(i+1, 1);
 	 	hdh[i]=record_analog(i+1, 2);
			fz[i]=(hdb[i]+hdh[i])/2;
			hdc[i]=abs(hdb[i]-hdh[i]);
			}
			clear_lcd( );
}
void mainX3(void)//��ֵ����
{
fzjs();
k=1;
    clear_lcd( );
  
    while(k!=0)
    {	
   display_str(4,1,"FZ  1: 1-14");
	display_str(4,17,"1:");display_int(28,17,fz[0]);display_str(69,17,"2:");display_int(93,17,fz[1]);
	display_str(4,33,"3:");display_int(28,33,fz[2]);display_str(69,33,"4:");display_int(93,33,fz[3]);
	display_str(4,49,"5:");display_int(28,49,fz[4]);display_str(69,49,"6:");display_int(93,49,fz[5]);
	display_str(4,65,"7:");display_int(28,65,fz[6]);display_str(69,65,"8:");display_int(93,65,fz[7]);
      display_str(4,81,"9:");display_int(28,81,fz[8]);display_str(69,81,"10:");display_int(93,81,fz[9]);
      display_str(4,97,"11:");display_int(28,97,fz[10]);display_str(69,97,"12:");display_int(93,97,fz[11]);
      display_str(4,113,"13:");display_int(28,113,fz[12]);display_str(69,113,"14:");display_int(93,113,fz[13]);  
      k=key(2 );
      
    }
	 k=1;
    clear_lcd( );
    while(k!=0)
    {	
    	display_str(4,1,"FZ  2: 15-28");
   display_str(4,17,"15:");display_int(28,17,fz[14]);display_str(69,17,"16:");display_int(93,17,fz[15]);
    display_str(4,33,"17:");display_int(28,33,fz[16]);display_str(69,33,"18:");display_int(93,33,fz[17]);
      display_str(4,49,"19:");display_int(28,49,fz[18]);display_str(69,49,"20:");display_int(93,49,fz[19]);
      display_str(4,65,"21:");display_int(28,65,fz[20]);display_str(69,65,"22:");display_int(93,65,fz[21]);
	display_str(4,81,"23:");display_int(28,81,fz[22]);display_str(69,81,"24:");display_int(93,81,fz[23]);
      display_str(4,97,"25:");display_int(28,97,fz[24]);display_str(69,97,"26:");display_int(93,97,fz[25]);
      display_str(4,113,"27:");display_int(28,113,fz[26]);display_str(69,113,"28:");display_int(93,113,fz[27]);
        k=key(2 );
    }	 
     k=1;
    clear_lcd( );
    while(k!=0)
    {
    
      	display_str(4,1,"HDC  1: 1-14");
     display_str(4,17,"1:");display_int(28,17,hdc[0]);display_str(69,17,"2:");display_int(93,17,hdc[1]);
     display_str(4,33,"3:");display_int(28,33,hdc[2]);display_str(69,33,"4:");display_int(93,33,hdc[3]);
      display_str(4,49,"5:");display_int(28,49,hdc[4]);display_str(69,49,"6:");display_int(93,49,hdc[5]);
	display_str(4,65,"7:");display_int(28,65,hdc[6]);display_str(69,65,"8:");display_int(93,65,hdc[7]);
      display_str(4,81,"9:");display_int(28,81,hdc[8]);display_str(69,81,"10:");display_int(93,81,hdc[9]);
      display_str(4,97,"11:");display_int(28,97,hdc[10]);display_str(69,97,"12:");display_int(93,97,hdc[11]);
      display_str(4,113,"13:");display_int(28,113,hdc[12]);display_str(69,113,"14:");display_int(93,113,hdc[13]);   
k=key( 2);  	
    }
    k=1;
    clear_lcd( );
    while(k!=0)
    {
   	display_str(4,1,"HDC  2: 15-28");
   display_str(4,17,"15:");display_int(28,17,hdc[14]);display_str(69,17,"16:");display_int(93,17,hdc[15]);
    display_str(4,33,"17:");display_int(28,33,hdc[16]);display_str(69,33,"18:");display_int(93,33,hdc[17]);
      display_str(4,49,"19:");display_int(28,49,hdc[18]);display_str(69,49,"20:");display_int(93,49,hdc[19]);
      display_str(4,65,"21:");display_int(28,65,hdc[20]);display_str(69,65,"22:");display_int(93,65,hdc[21]);
	display_str(4,81,"23:");display_int(28,81,hdc[22]);display_str(69,81,"24:");display_int(93,81,hdc[23]);
      display_str(4,97,"25:");display_int(28,97,hdc[24]);display_str(69,97,"26:");display_int(93,97,hdc[25]);
      display_str(4,113,"27:");display_int(28,113,hdc[26]);display_str(69,113,"28:");display_int(93,113,hdc[27]);
      k=key( 2);
    }  
}

void mdcs()//������ δʹ��
{ 
  motor( 1, 30);motor(2 , 30);delay( 4,0);mot_stop( );delay(0 ,500);//ǰ��
  motor( 1, -30);motor(2 , -30);delay( 4,0);mot_stop( );delay(0 ,500);//����
  motor( 1, -40);motor(2 , 40);delay( 3,0);mot_stop( );delay(0 ,500);//��ת
  motor( 1, 40);motor(2 , -40);delay( 3,0);//��ת
  mot_stop( );
}
void mainX4(void)//������
{
	run_utill(20,'B','A');
	// ����
	line_black_brige(20); 
	run_utill(20,'W','R');
	turn_right();
	run_utill(30,'B','A');
	run(60,60);
	delay(0,300);
	run(0,0);
}

void djcs()//�������
  {
 servo(1,880 );delay( 0,500); servo(1,500 );delay( 0,500);servo(1,200 );delay( 0,500);servo(1,500 );delay( 0,500);//����(1�Ŷ��)̧����£�200<��ֵ<880��
  delay(1 ,0);
   servo(2,980 );delay( 0,500);servo(4,900 );servo(5,100 );delay(0 ,500);delay(1 ,500);servo(2,500 );servo(4,500 );servo(5,500 );delay( 0,500);//����(2�Ŷ��)��������500<��ֵ<980��
  delay(1 ,0);
  servo(3,800 );servo(4, 800);servo(5,800 );delay(0 ,500);//ͷ������ҡ�ڣ��ֱ����°ڶ�����3/4/5�Ŷ��100<��ֵ<800��
    servo(3,200 );servo(4, 200);servo(5,200 );delay(0 ,500);//ͷ������ҡ�ڣ��ֱ����°ڶ���3/4/5�Ŷ��100<��ֵ<800��
    servo(3,800 );servo(4, 800);servo(5,800 );delay(0 ,500);//ͷ������ҡ�ڣ��ֱ����°ڶ���3/4/5�Ŷ��100<��ֵ<800��
    servo(3,200 );servo(4, 200);servo(5,200 );delay(0 ,500);//ͷ������ҡ�ڣ��ֱ����°ڶ���3/4/5�Ŷ��100<��ֵ<800��
    servo(3,500 );servo(4, 500);servo(5,500 );delay(0,500);//ͷ������ҡ�ڣ��ֱ����°ڶ���3/4/5�Ŷ��100<��ֵ<800��
  }
void mainX5(void)//�������
{
djcs();
}

void mainX6(void)
{
record();
}
void mainX7(void)
{
motor( 1, 30);motor(2 , 18);delay(100,0);mot_stop( );delay(0 ,500);
}	

void mainX(void *p_arg) //��װall
{
  set_name(MAINX1,"main1--SJCS");//���������ݲ���
  set_name(MAINX2,"main2--SJDQ");//ģ�⴫�������ݶ�ȡ
  set_name(MAINX3,"main3--FZJS");//��ֵ����
  set_name(MAINX4,"main4--MDCS");//������
  set_name(MAINX5,"main5--DJCS");//�������
  set_name(MAINX6,"main6");//�û�����
  set_name(MAINX7,"main7");//�û�����
  // .... x7��ͨ����Զ����㷧ֵ
  set_digital( 1,0 );
 	 i=0; //ͨ����Զ����㷧ֵ
   servo(1,500 );servo(2,500 );servo(3,500 );servo(4,500 );servo(5,500 );servo(6,500 );
 	 while(i<28)
 	 {
 	 	hdb[i]=record_analog(i+1, 1);
 	 	hdh[i]=record_analog(i+1, 2);
			fz[i]=(hdb[i]+hdh[i])/2;
			hdc[i]=abs(hdb[i]-hdh[i]);
			i=i+1;
			}
  select_main();
}