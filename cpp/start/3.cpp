////  main.cpp
////  opengl_progress_struct
//
//#include <GL/GLUT.h>
////#include <GL/OpenGL.h>
//
//// ��ʼ������
//void init() {
//    glClearColor(0.1, 0.1, 0.4, 0.0);
//    glShadeModel(GL_SMOOTH);
//}
//
//// ��ͼ�ص�����
//void display() {
//
//    // ���֮ǰ֡����
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // ����������
//    glBegin(GL_TRIANGLES);
//    glColor3f(1, 0, 0);
//    glVertex3f(-1, -1, -5);
//    glColor3f(0, 1, 0);
//    glVertex3f(1, -1, -5);
//    glColor3f(0, 0, 1);
//    glVertex3f(0, 1, -5);
//    glEnd();
//    // ִ�л�ͼ����
//    glFlush();
//}
//
//// ���ڴ�С�仯�ص�����
//void reshape(int w, int h) {
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 0.1, 100000.0);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//}
//
//int main(int argc, const char* argv[]) {
//    // ��ʼ����ʾģʽ
//    glutInit(&argc, const_cast<char**>(argv));
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//
//    // ��ʼ������
//    glutInitWindowSize(500, 500);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow(argv[0]);
//
//    init();
//    glutReshapeFunc(reshape);
//    glutDisplayFunc(display);
//
//    // ��ʼ��ѭ������
//    glutMainLoop();
//    return 0;
//}
