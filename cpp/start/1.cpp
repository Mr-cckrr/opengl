//
//#include <windows.h>      
//#include <gl/glut.h>      
//#include <math.h>     
//constexpr auto GL_PI = 3.1415f;
//
//float fMoonRot = 0.0f;
//float fAdamRot = 0.0f;
//float fEarthRot = 0.0f;
//float fMarsRot = 0.0f;
//float fMarsatellite1 = 0.0f;
//float fMarsatellite2 = 0.0f;
//float fHesperRot = 0.0f;
//float fJupiterRot = 0.0f;
//float fSaturnRot = 0.0f;
//float fSaturn1 = 0.0f;
//float fUranusRot = 0.0f;
//float fNeptuneRot = 0.0f;
//
//GLfloat  whiteLight[] = { 0.2f,0.2f,0.2f,1.0f };
//GLfloat  lightPos[] = { 0.0f,0.0f,0.0f,1.0f };
//
//void sun()
//{
//    ����̫��    
//    glColor3ub(255, 50, 0);
//    glDisable(GL_LIGHTING);   //�رչ�Դ      
//    glutSolidSphere(25.0f, 200.0f, 200.0f);
//    glEnable(GL_LIGHTING);    //�����Դ    
//    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
//}
//void Adam()
//{
//    ����ˮ��  
//    glPushMatrix();
//    glColor3ub(0, 0, 255);
//    glRotatef(fAdamRot, 0.0f, 1.0f, 0.0f);
//    glTranslatef(30.0f, 0.0f, 0.0f);
//    glutSolidSphere(2.0f, 200.0f, 200.0f);       //ˮ�ǰ뾶�ǵ����40% ��2  
//    fAdamRot += 4.152f;                        //ˮ�ǹ�ת����Ϊ����24.08% ,��4.152  
//    if (fAdamRot >= 365.0f)
//        fAdamRot = 0.0f;
//    glPopMatrix();
//}
//void Hesper()
//{
//    ���ƽ���  
//    glPushMatrix();
//    glColor3ub(255, 215, 0);
//    glRotatef(fHesperRot, 0.0f, 1.0f, 0.0f);
//    glTranslatef(40.0f, 0.0f, 0.0f);
//    glutSolidSphere(4.75f, 200.0f, 200.0f);       //���ǰ뾶�ǵ����95% ��4.75  
//    fHesperRot += 1.62f;                        //���ǹ�ת����Ϊ����61.56% ,��1.62  
//    if (fHesperRot >= 365.0f)
//        fHesperRot = 0.0f;
//    glPopMatrix();
//}
//void Earth_Moon()
//{
//
//    ���Ƶ���,�������в����Ե���Ϊ��׼  
//    glPushMatrix();
//    glColor3ub(0, 0, 255);
//    glRotatef(fEarthRot, 0.0f, 1.0f, 0.0f);
//    glTranslatef(55.0f, 0.0f, 0.0f);           //���������365  
//    glutSolidSphere(5.0f, 20.0f, 20.0f);       //�����뾶5  
//
//    ���ݻ��ڵ�������������ת������������      
//    glColor3ub(200, 200, 200);
//    glRotatef(fMoonRot, 0.0f, 1.0f, 0.0f);
//    glTranslatef(5.0f, 0.0f, 0.0f);          // ����ƽ��
//    fMoonRot += 13.3f;                     //����Ĺ�ת���� 27.3 ��  365/27.3==13.3  
//    if (fMoonRot >= 365.0f)                 // ����뾶�ǵ����3/11   ��1.363     
//        fMoonRot = 0.0f;
//    glutSolidSphere(1.363f, 200.0f, 200.0f);
//    glPopMatrix();                         //��ջ��ֵ�仯��Ҫ����һ��ѭ���в���Ч   
//    fEarthRot += 1.0f;
//    if (fEarthRot >= 365.0f)
//        fEarthRot = 0.0f;
//}
//
//void Mars()
//{
//    ���ƻ���
//    glPushMatrix();
//    glColor3ub(255, 0, 0);
//    glRotatef(fMarsRot, 0.0f, 1.0f, 0.0f);
//    glTranslatef(65.0f, 0.0f, 0.0f);
//    glutSolidSphere(2.65f, 200.0f, 200.0f);       //���ǰ뾶�ǵ����53% ��2.65
//
//    glPushMatrix();
//    ���ݻ��ڻ��ǵ����������ת�������ƻ���һ   
//    glColor3ub(255, 100, 100);
//    glRotatef(fMarsatellite1, 0.0f, 1.0f, 0.0f);
//    glTranslatef(2.0f, 0.0f, 2.0f);
//    fMarsatellite1 += 13.3f;
//    if (fMarsatellite1 >= 365.0f)
//        fMarsatellite1 = 0.0f;
//    glutSolidSphere(0.963f, 200.0f, 200.0f);
//    glPopMatrix();
//
//    glPushMatrix();
//    ���ݻ��ڻ��ǵ����������ת�������ƻ�����     
//    glColor3ub(255, 200, 200);
//    glRotatef(fMarsatellite2, 0.0f, 1.0f, 0.0f);
//    glTranslatef(-3.0f, 0.0f, -3.0f);
//    fMarsatellite2 += 13.3f;
//    if (fMarsatellite2 >= 365.0f)
//        fMarsatellite2 = 0.0f;
//    glutSolidSphere(1.20f, 200.0f, 200.0f);
//    glPopMatrix();
//
//    fMarsRot += 0.5f;                           //���ǹ�ת����Ϊ����2��
//    if (fMarsRot >= 365.0f)
//        fMarsRot = 0.0f;
//    glPopMatrix();
//}
//
//
//void Jupiter()
//{
//    ����ľ��  
//    glPushMatrix();
//    glColor3ub(200, 100, 0);
//    glRotatef(fJupiterRot, 0.0f, 1.0f, 0.0f);
//    glTranslatef(100.0f, 0.0f, 0.0f);
//    glutSolidSphere(17.0f, 200.0f, 200.0f);       //ľ�ǰ뾶�ǵ����11.21�� ��56.05  Ϊ�����ۣ���Ϊ17 
//
//    glPushMatrix();
//    glColor3ub(250, 180, 0);
//    glRotatef(70.0f, 1.0f, 0.0f, 0.0f);             //����ת70�� 
//    glutSolidTorus(1.42, 20, 10, 100);             //Ч���Ͽ�����һ��������Բ���Ŀ��
//    glPopMatrix();
//
//    fJupiterRot += 0.15f;                     //ľ�ǹ�ת����Ϊ����11.87�� ,��0.084  Ϊ�����ԣ���Ϊ0.15
//    if (fJupiterRot >= 365.0f)
//        fJupiterRot = 0.0f;
//    glPopMatrix();
//}
//void Saturn()
//{
//    ��������  
//    glPushMatrix();
//    glColor3ub(73, 60, 32);
//    glRotatef(fSaturnRot, 0.0f, 1.0f, 0.0f);
//    glTranslatef(148.0f, 0.0f, 0.0f);
//    glutSolidSphere(15.0f, 200.0f, 200.0f);       //���ǰ뾶�ǵ����9.45�� ��47.25 Ϊ�����ۣ���Ϊ15  
//    ��������һ
//
//    glPushMatrix();
//    glColor3ub(255, 200, 200);
//    glRotatef(fSaturn1, 0.0f, 1.0f, 0.0f);
//    glTranslatef(-17.0f, 0.0f, -17.0f);
//    fSaturn1 += 6.4f;
//    if (fSaturn1 >= 365.0f)
//        fSaturn1 = 0.0f;
//    glutSolidSphere(1.20f, 200.0f, 200.0f);
//    glPopMatrix();
//
//    glPushMatrix();
//    glColor3ub(200, 200, 100);
//    glRotatef(70.0f, 1.0f, 0.0f, 0.0f);             //����ת70�� 
//    glutSolidTorus(1.42, 25, 10, 100);             //Ч���Ͽ�����һ��������Բ���Ŀ��
//    glPopMatrix();
//
//    fSaturnRot += 0.03f;                        //���ǹ�ת����Ϊ����29.47�� ,��0.03  
//    if (fSaturnRot >= 365.0f)
//        fSaturnRot = 0.0f;
//    glPopMatrix();
//}
//void UranusRot()
//{
//    ����������  
//    glPushMatrix();
//    glColor3ub(0, 180, 100);
//    glRotatef(fUranusRot, 0.0f, 1.0f, 0.0f);
//    glTranslatef(202.0f, 0.0f, 0.0f);
//    glutSolidSphere(15.0f, 200.0f, 200.0f);       //�����ǰ뾶�ǵ���ı� ��4.01����15    
//
//    glPushMatrix();
//    glColor3ub(0, 100, 0);
//    glRotatef(150.0f, 1.0f, 0.0f, 0.0f);             //����ת�� 
//    glutSolidTorus(1.0, 20, 10, 100);             //Ч���Ͽ�����һ��������Բ���Ŀ��
//    glPopMatrix();
//
//    fUranusRot += 0.03f;                        //�����ǹ�ת����Ϊ����84.06�� ,��0.0124  
//    if (fUranusRot >= 365.0f)
//        fUranusRot = 0.0f;
//    glPopMatrix();
//}
//
//void Neptune()
//{
//    ���ƺ�����  
//    glPushMatrix();
//    glColor3ub(0, 0, 215);
//    glRotatef(fNeptuneRot, 0.0f, 1.0f, 0.0f);
//    glTranslatef(240.0f, 0.0f, 0.0f);
//    glutSolidSphere(19.45f, 200.0f, 200.0f);       //�����ǰ뾶�ǵ���ı� ��3.89����19.45    
//    fNeptuneRot += 2.17f;                       //�����ǹ�ת����Ϊ����46%�� ,��2.17  
//    if (fUranusRot >= 365.0f)
//        fNeptuneRot = 0.0f;
//    glPopMatrix();
//}
//void RenderScene(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glPushMatrix();
//    glTranslatef(0.0f, 0.0f, -300.0f);
//
//    sun();
//    Adam();
//    Hesper();
//    Earth_Moon();
//    Mars();
//    Jupiter();
//    Saturn();
//    UranusRot();
//    Neptune();
//
//    glPopMatrix();
//    glutSwapBuffers();
//}
//void ChangeSize(GLsizei w, GLsizei h)
//{
//    GLfloat fAspect;
//    if (h == 0) h = 1;
//    glViewport(0, 0, w, h);
//    fAspect = (GLfloat)w / (GLfloat)h;
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(60.0f, fAspect, 1.0, 4000);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//}
//
//void SetupRC(void)
//{
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_COLOR_MATERIAL);
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//    glEnable(GL_LIGHTING);                             //�����Դ      
//    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight); //ʹ��whiteLght��ָ���Ļ�����      
//    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);         //0�Ź�Դ��λ��      
//    glEnable(GL_LIGHT0);
//}
//void TimerFunc(int value)
//{
//    glutPostRedisplay();
//    glutTimerFunc(100, TimerFunc, 1);
//}
//
//int main(int argc, char* argv[])
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Orthographic Projection");
//    glutDisplayFunc(RenderScene);
//    glutReshapeFunc(ChangeSize);
//    SetupRC();
//    glutTimerFunc(250, TimerFunc, 1); //�Զ���������ʱ��   
//    glutMainLoop();
//    return 0;
//}
