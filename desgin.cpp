// Miranda Ramirez Cospin

#include <iostream>

using namespace std;

gcd(int a, int b)
{
  if(b == 0)
    return a;
  return gcd(b, a % b);
}

GeometricConfections(int A[], int k, int n)
{
  int j = 1, V = 0;
  int p, q, f1, f2, sum1, sum2, total;
  
  if(n == 1)
    return 1;
  else if(n == 2)
  {
    p = A[j];
    q = A[j+1];
    V = (p * q) - p - q;
  }
  else if(n == 3)
    V = gcd(A[j],A[j+1]) + gcd(A[j],A[j+2]) - A[j] - A[j+1] - A[j+2];
  else
  {
    while(n)
    {
      f1 = (j - 1) * k;
      f2 = j * k;
      sum1 = (f1 * (f1 + 1)) / 2;
      sum2 = (f2 * (f2 + 1)) / 2;
      total = sum2 - sum1;
      if(total <= n)
        n -= total;
      else
        V = total;
    }
  }
  
  return V;
}

int main()
{
  int list[] = {5,8,18};
  int size;
  int k = 3;
  
  cout << "The Geometric Confections for the order ";
  cout << list[0];
  for(int i = 1, i < size; i++)
    cout << "," << list[i];
  cout << " is " << GeometricConfections(list, k, size) << endl;
}
