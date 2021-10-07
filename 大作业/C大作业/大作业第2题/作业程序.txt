#include<gl/glut.h>
#include<math.h>
#include<iostream>
using namespace std;
#define PI 3.14159

void Rotate() ;
//水星、金星、地球、火星、木星、土星、天王星、和海王星
//mercury,venus,earth,mars,jupiter,saturn,uranus,neptune
static float year = 0, day = 0,mercuryYear=0,venusYear=0,marsYear=0,jupiterYear=0,saturnYear=0,uranusYear=0,neptuneYear=0,sunYear=0,month=0;
static float mar_satellite_1,mar_satellite_2 ;
float light_angle=0;
float light_radius=8.0;
double x=0,y=0;

double aix_x=0.0,aix_y=0.5,aix_z=0.5;

void lPosition()
{
     float y,z;
     y=light_radius*cos(light_angle);
     z=light_radius*sin(light_angle);
     float light_position[] = { 3.0,y,z, 0.0 }; //设定光源位置
glLightfv(GL_LIGHT0, GL_POSITION, light_position); //0号光源位置
}

void initScene(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);//背景颜色，黑色
    lPosition();
    glShadeModel (GL_SMOOTH);
    glEnable(GL_LIGHTING); //启用光源
    glEnable(GL_LIGHT0); //启用0号光源
    glEnable(GL_DEPTH_TEST); //启用深度测试
    glEnable(GL_COLOR_MATERIAL); //物体表面的颜色
}


void material_sun() //设置材料颜色，太阳
{
    GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 1.0 }; //  材质的镜面反射颜色
    GLfloat mat_shininess[] = { 60.0 };  // 镜面反射指数 GL_SHININESS的取值范围是[0.0, 128.0]－－值越高，高光点越小且越亮(聚焦越好)
    GLfloat lmodel_ambient[]={1.0,0.2,0.0,1.0};   //材质的环境颜色.太阳为橙红色
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}


void material_mercury() //设置材料颜色，水星
{
    GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={1.0,1.0,1.0,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}
void material_venus() //设置材料颜色，金星
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={1.0,0.5,0.2,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_earth() //设置材料颜色，地球
{
    GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={0.1,0.2,0.6,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}

void material_mars() //设置材料颜色，火星
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={1.0,0.1,0.0,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}


void material_jupiter() //设置材料颜色，木星
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={0.2,0.2,0.0,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}


void material_saturn() //设置材料颜色，土星
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={0.2,0.0,0.1,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}


void material_uranus() //设置材料颜色，天王
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={0.3,0.3,0.7,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}


void material_neptune() //设置材料颜色，海王
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={0.0,0.1,1.0,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}
void material_moon()//设置材料颜色，月球
{
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={1.0,1.0,0.0,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}


void material_mar_satellite_1()//设置材料颜色，火星卫星1
{
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={0.0,1.0,1.0,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}




void material_mar_satellite_2()//设置材料颜色，火星卫星2
{
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={0.0,0.0,1.0,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}


void material_neptune_satellite_1()//设置材料颜色，海王星卫星1
{
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={1.0,0.0,1.0,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}


void material_neptune_satellite_2()//设置材料颜色，海王星卫星2
{
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={0.0,0.0,1.0,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}
void material_uranus_satellite_1()//设置材料颜色，天王星卫星1
{
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={0.3,0.2,1.0,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}


void material_uranus_satellite_2()//设置材料颜色，天王星卫星2
{
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={0.3,0.4,0.0,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}


void material_jupiter_satellite()//设置材料颜色，木星卫星1
{
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={0.3,0.6,1.0,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}


void material_saturn_satellite()//设置材料颜色，土星卫星1
{
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat lmodel_ambient[]={0.3,0.6,1.0,1.0};
    GLfloat white_light[]={1.0, 1.0,1.0, 1.0};


    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}


void sun()                  //绘制太阳
{
    glPushMatrix(); //压栈
material_sun();
glTranslatef (-15,0,0);
glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);   //太阳自转
    glutSolidSphere(10, 200, 200);       //画球体
    glPopMatrix(); //出栈
}


void mercury() //水星
{
    glPushMatrix();
material_mercury();
glTranslatef (-15,0,0);
    glRotatef ((GLfloat) mercuryYear, aix_x, aix_y, aix_z);  //水星公转周期，下同
    glTranslatef (15,0,0);
glTranslatef (0.2,0,0);
    glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);    //水星自转，下同
glTranslatef (-0.5,0,0);
glTranslatef (0.5,0,0);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();
}


void venus()
{
    glPushMatrix();
    material_venus();
glTranslatef (-15,0,0);
    glRotatef ((GLfloat)venusYear,aix_x, aix_y, aix_z);
glTranslatef (15,0,0);
    glTranslatef (0.8,0,0);
    glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
glTranslatef (-1,0,0);
glTranslatef (1,0,0);
    glutSolidSphere(0.8, 20, 20);
    glPopMatrix();
}


void earth()
{
    glPushMatrix();
    material_earth();
glTranslatef (-15,0,0);
    glRotatef ((GLfloat) year, aix_x, aix_y, aix_z);
glTranslatef (15,0,0);
    glTranslatef (2,0,0);
    glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
glTranslatef (-2,0,0);
glTranslatef (2,0,0);
    glutSolidSphere(1.0, 20, 20);


material_moon();           //绘制月球，以下以同样方法绘制各行星的卫星
     glRotatef(month/100, 0.0, 0.0, 1.0);
     glTranslatef(2, 0.0, 0.0);
     glutSolidSphere(0.3, 10, 10);
     glPopMatrix();
}


void mars()
{
   glPushMatrix();
   material_mars();
   glTranslatef (-15,0,0);
   glRotatef ((GLfloat)marsYear,aix_x, aix_y, aix_z);
   glTranslatef (15,0,0);
   glTranslatef (7,0,0);
   glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
   glTranslatef (-7,0,0);
   glTranslatef (7,0,0);
   glutSolidSphere(0.6, 20, 20);

    glPushMatrix();
    material_mar_satellite_1();
     glRotatef(month/20, 0.0, 1.0, 0.0);
     glTranslatef(1, 0.0, 0.0);
     glutSolidSphere(0.1, 10, 10);
glPopMatrix();


glPushMatrix();
  material_mar_satellite_2();
     glRotatef(month/46, 0.0, 1.0, 0.0);
     glTranslatef(1.5, 0.0, 0.0);
     glutSolidSphere(0.2, 10, 10);
glPopMatrix();


   glPopMatrix();
}

void jupiter()
{
   glPushMatrix();
   material_jupiter();
   glTranslatef (-15,0,0);
   glRotatef ((GLfloat)jupiterYear, aix_x, aix_y, aix_z);
   glTranslatef (15,0,0);
   glTranslatef (13,0,0);
   glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
   glTranslatef (-13,0,0);
   glTranslatef (13,0,0);
   glutSolidSphere(2.0, 20, 20);

    glPushMatrix();
    material_jupiter_satellite();//卫星
     glRotatef(90,1.0,0,0.0);
     glRotatef(month/58, 0.0, 1.0, 0.0);
     glTranslatef(3, 0.0, 0.0);
     glutSolidSphere(0.6, 10, 10);
   glPopMatrix();

   glPopMatrix();
}


void saturn()
{
     glPushMatrix();
material_saturn();
glTranslatef (-15,0,0);
     glRotatef ((GLfloat) saturnYear, aix_x, aix_y, aix_z);
glTranslatef (15,0,0);
     glTranslatef (20,0,0);
     glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
glTranslatef (-20,0,0);
glTranslatef (20,0,0);
glRotatef (0.3, 1.0, 0.0, 0.0);
     glutSolidSphere(1.4, 20, 20);

    glPushMatrix();
    glRotatef(90,1.0,0,0.0);
    glutWireTorus(0.1, 3.0, 5, 64);
    glRotatef(-90,1.0,0,0.0);

    material_saturn_satellite();
     glRotatef(month/76, 0.0, 1.0, 0.0);
     glTranslatef(2.7, 0.0, 0.0);
     glutSolidSphere(0.4, 10, 10);
    glPopMatrix();
    glPopMatrix();
}


void uranus()
{
     glPushMatrix();
material_uranus();
glTranslatef (-15,0,0);
     glRotatef ((GLfloat) uranusYear,aix_x, aix_y, aix_z);
glTranslatef (15,0,0);
     glTranslatef (28,0,0);
     glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
glTranslatef (-28,0,0);
glTranslatef (28,0,0);
glRotatef (0.5, 1.0, 0.0, 0.0);
     glutSolidSphere(1.5, 20, 20);

    glPushMatrix();
    glRotatef(90,1.0,0,0.0);
    glutWireTorus(0.1, 3.0, 5, 64);
    glRotatef(-90,1.0,0,0.0);

    glPushMatrix();
    material_uranus_satellite_1();
     glRotatef(month/108, 0.0, 1.0, 0.0);
     glTranslatef(2, 0.0, 0.0);
     glutSolidSphere(0.23, 10, 10);
    glPopMatrix();

    glPushMatrix();
    material_uranus_satellite_2();
     glRotatef(month/145, 0.0, 1.0, 0.0);
     glTranslatef(3.5, 0.0, 0.0);
     glutSolidSphere(0.35, 10, 10);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}
void neptune()
{
     glPushMatrix();
material_neptune();
glTranslatef (-15,0,0);
     glRotatef ((GLfloat) neptuneYear,aix_x, aix_y, aix_z);
glTranslatef (15,0,0);
     glTranslatef (32,0,0);
     glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
glTranslatef (-32,0,0);
glTranslatef (32,0,0);
glRotatef (0.5, 1.0, 0.0, 0.0);
     glutSolidSphere(1.3, 20, 20);

    glPushMatrix();
    material_neptune_satellite_1();
     glRotatef(month/347, 0.0, 1.0, 0.0);
     glTranslatef(2.5, 0.0, 0.0);
     glutSolidSphere(0.4, 10, 10);
    glPopMatrix();

    glPushMatrix();
    material_neptune_satellite_2();
     glRotatef(month/389, 0.0, 1.0, 0.0);
     glTranslatef(3.5, 0.0, 0.0);
     glutSolidSphere(0.3, 10, 10);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}


void display(void)
{
    lPosition();
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //清除缓冲区
    sun();
    mercury();
    venus();
    earth();
    mars();
    jupiter();
    saturn();
    uranus();
    neptune();
    Rotate();
    glutSwapBuffers(); //交换缓冲区
}


void Idle()
{
day+=10.0;
if (day>=360)
day=day-360;

glutPostRedisplay();
}


void Rotate()          //设置各行星的公转周期
{

   mercuryYear+=0.20;
   if(mercuryYear>=365)
  mercuryYear-=365;

   venusYear+=0.14;
   if(venusYear>=365)
  venusYear-=365;

   year+=0.11;
   if(year>=365)
  year-=365;

   marsYear+=0.06;
   if(marsYear>=365)
  marsYear-=365;

    jupiterYear+=0.04;
   if(jupiterYear>=365)
  jupiterYear-=365;

    saturnYear+=0.03;
   if(saturnYear>=365)
  saturnYear-=365;

   uranusYear+=0.02;
   if(uranusYear>=365)
  uranusYear-=365;

    neptuneYear+=0.01;
   if(neptuneYear>=365)
  neptuneYear-=365;
   glutPostRedisplay();
   month+=0.03;
   if(month>=365)
  month-=365;
}

void ChangeSize (int w, int h)
{
    GLfloat fAspect;
	// 防止被0所除
    if(h == 0) h = 1;
	fAspect = (GLfloat)w/(GLfloat)h;//实际窗口的纵横比
    glViewport (0, 0, w, h);
    glMatrixMode (GL_PROJECTION);  // 重置透视坐标系统
    glLoadIdentity ();
    // 产生透视投影
    gluPerspective(100, fAspect, 1.0, 220.0); /*视角，纵横比，近处
      截面（越大距离近看不到），远处截面（越小距离远看不到）*/

//重置模型视图矩阵
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-50.0);
}
int main(int argc, char** argv)
{

for(int i=0;i<argc;i++)
   glutInit(&argc, argv);//对GLUT函数库进行初始化
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//创建窗口时使用类型的显示模式
   glutInitWindowSize (800, 600);//初始化窗口大小
   glutInitWindowPosition (100, 100);//初始化窗口位置
   glutCreateWindow ("solar system"); //创建glut窗口
   initScene ();//初始化OpenGL显示场景
   glutDisplayFunc(display);
   glutReshapeFunc(ChangeSize);//注册窗口大小变化函数
   glutIdleFunc(Idle);
   glutMainLoop();  //启动GLUT框架的运行
   return 0;
}
