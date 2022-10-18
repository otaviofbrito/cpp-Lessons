
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

  int m1[3][4]{
      {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}};

  int m2[4][5]{
      {1, 1, 1, 1, 1}, {2, 2, 2, 2, 2}, {3, 3, 3, 3, 3}, {4, 4, 4, 4, 4}};

  int m3[3][5];

  int *p1, *q1, *r, *p2, *q2;
  r = &m3[0][0];
  p1 = &m1[0][0], p2 = &m1[0][0];
  q1 = &m2[0][0], q2 = &m2[0][0];

  for (; p1 < &m1[0][0] + 12; p1+=4)
  {

    for (; q1 < &m2[0][0] + 5; q1++)
    {
      *r = 0;
      for (p2 = p1, q2 = q1; p2 < p1 + 4; p2++, q2+=5)
      {
        *r = *r + (*p2) * (*q2);
        r++;
      }
    }
  }



  for (int k = 0; k < 3; k++)
  {
    for (int l = 0; l < 4; l++)
    {
      cout << " " << m3[k][l];
    }
  }
  return 0;
}