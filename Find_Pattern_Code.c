#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
struct node
{
  struct node *left;
  char key;
  int onf;
  int x;
  int y;
  struct node *right;
};

int i = 0;
struct node *root = NULL;

void ledon()
{
  setcolor(10);
  setfillstyle(1, 10);
  pieslice(root->x, root->y, 0, 360, 25);
  sound(430);
  delay(100);
  nosound();
}

void ledoff()
{
  setcolor(2);
  setfillstyle(1, 2);
  pieslice(root->x, root->y, 0, 360, 25);
  sound(500);
  delay(10);
  nosound();
}

void kb(char k)
{
  if (k == (root->key))
  {
    i = 1;

    root->onf = 1;
    ledon();
    return;
  }
  else
  {
    root = root->left;
    kb(k);
    return;
  }
}

void kbb(char k)
{
  if (root->left->key == k)
  {
    root = root->left;
    i = 2;
    root->onf = 1;
    ledon();
    return;
  }
  else if (root->right->key == k)
  {
    root = root->right;
    i = 2;
    root->onf = 1;
    ledon();
    return;
  }
  else
  {
    i = 0;
    root->onf = 0;
    ledoff();
    kb(k);
    return;
  }
}

void kkbb(k)
{
  int t;
  if (root->left->onf == 1)
  {
    if (root->right->key == k)
    {
      i++;
      root = root->right;
      root->onf = 1;
      ledon();
      return;
    }
    else
    {
      for (t = 1; t <= i; t++)
      {
	root->onf = 0;
	ledoff();
	root = root->left;
      }
      i = 0;
      kb(k);
      return;
    }
  }
  else if (root->left->onf == 0)
  {
    if (root->left->key == k)
    {
      i++;
      root = root->left;
      root->onf = 1;
      ledon();
      return;
    }
    else
    {
      for (t = 1; t <= i; t++)
      {
	root->onf = 0;
	ledoff();
	root = root->right;
      }
      i = 0;
      kb(k);
      return;
    }
  }
}

void machine()
{
  setbkcolor(14);
  setfillstyle(1, 7);
  bar(120, 20, 520, 450);
  setcolor(2);
  setfillstyle(1, 2);
  circle(320, 160, 100);
  pieslice(420, 160, 0, 360, 25); // s1
  pieslice(220, 160, 0, 360, 25); // s4
  pieslice(380, 74, 0, 360, 25);  // s2
  pieslice(280, 74, 0, 360, 25);  // s3
  pieslice(280, 247, 0, 360, 25); // s5
  pieslice(380, 247, 0, 360, 25); // s6
  setfillstyle(1, 8);
  bar(180, 300, 250, 330); // q
  setcolor(16);
  settextstyle(0, 0, 3);
  outtextxy(200, 300, "q");
  bar(180, 350, 250, 380); // a
  outtextxy(200, 350, "a");
  bar(180, 400, 250, 430); // z
  outtextxy(200, 400, "z");
  bar(380, 300, 450, 330); // w
  outtextxy(400, 305, "w");
  bar(380, 350, 450, 380); // s
  outtextxy(400, 350, "s");
  bar(380, 400, 450, 430); // x
  outtextxy(400, 405, "x");
}

void buttonpress(char b)
{
  if (b == 'q')
  {
    setfillstyle(1, 11);
    bar(180, 300, 250, 330);
    setcolor(16);
    settextstyle(0, 0, 3);
    outtextxy(200, 300, "q");
    delay(20);
    setfillstyle(1, 8);
    bar(180, 300, 250, 330);
    outtextxy(200, 300, "q");
  }
  else if (b == 'a')
  {
    setfillstyle(1, 11);
    bar(180, 350, 250, 380);
    setcolor(16);
    settextstyle(0, 0, 3);
    outtextxy(200, 350, "a");
    delay(20);
    setfillstyle(1, 8);
    bar(180, 350, 250, 380);
    outtextxy(200, 350, "a");
  }
  else if (b == 'z')
  {
    setfillstyle(1, 11);
    bar(180, 400, 250, 430);
    setcolor(16);
    settextstyle(0, 0, 3);
    outtextxy(200, 400, "z");
    delay(20);
    setfillstyle(1, 8);
    bar(180, 400, 250, 430);
    outtextxy(200, 400, "z");
  }
  else if (b == 'w')
  {
    setfillstyle(1, 11);
    bar(380, 300, 450, 330);
    setcolor(16);
    settextstyle(0, 0, 3);
    outtextxy(400, 305, "w");
    delay(20);
    setfillstyle(1, 8);
    bar(380, 300, 450, 330);
    outtextxy(400, 305, "w");
  }
  else if (b == 's')
  {
    setfillstyle(1, 11);
    bar(380, 350, 450, 380);
    setcolor(16);
    settextstyle(0, 0, 3);
    outtextxy(400, 350, "s");
    delay(20);
    setfillstyle(1, 8);
    bar(380, 350, 450, 380);
    outtextxy(400, 350, "s");
  }
  else if (b == 'x')
  {
    setfillstyle(1, 11);
    bar(380, 400, 450, 430);
    setcolor(16);
    settextstyle(0, 0, 3);
    outtextxy(400, 405, "x");
    delay(20);
    setfillstyle(1, 8);
    bar(380, 400, 450, 430);
    outtextxy(400, 405, "x");
  }
}

void main()
{
  struct node s1, s2, s3, s4, s5, s6;
  int gd = DETECT, gm, x, y;
  char l;
  clrscr();
  root = &s1;
  s1.right = &s2;
  s1.x = 420;
  s1.left = &s6;
  s1.y = 160;
  s1.key = 'q';
  s1.onf = 0;
  s2.right = &s3;
  s2.x = 380;
  s2.left = &s1;
  s2.y = 74;
  s2.key = 'a';
  s2.onf = 0;
  s3.right = &s4;
  s3.x = 280;
  s3.left = &s2;
  s3.y = 74;
  s3.key = 'z';
  s3.onf = 0;
  s4.right = &s5;
  s4.x = 220;
  s4.left = &s3;
  s4.y = 160;
  s4.key = 'w';
  s4.onf = 0;
  s5.right = &s6;
  s5.x = 280;
  s5.left = &s4;
  s5.y = 247;
  s5.key = 's';
  s5.onf = 0;
  s6.right = &s1;
  s6.x = 380;
  s6.left = &s5;
  s6.y = 247;
  s6.key = 'x';
  s6.onf = 0;
  initgraph(&gd, &gm, "");
  machine();
  while (i != 6)
  {
    kbhit();
    l = getch();
    if (l == 27)
    {
      exit(0);
    }
    buttonpress(l);
    if (i == 0)
    {
      kb(l);
    }
    else if (i == 1)
    {
      kbb(l);
    }
    else if (i > 1)
    {
      kkbb(l);
    }
  }
  setfillstyle(1, 4);
  bar(200, 200, 450, 350);
  setcolor(3);
  settextstyle(0, 0, 3);
  outtextxy(210, 210, "you won");
  sound(500);
  delay(400);
  outtextxy(210, 260, "!you won!");
  sound(550);
  delay(200);
  outtextxy(210, 310, "!you won!");
  sound(600);
  sound(400);
  delay(1000);
  nosound();

  getch();
  closegraph();
}