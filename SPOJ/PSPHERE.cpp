#include <math.h>
#include <iostream>
#include <iomanip>
 
int main()
{
  int nTestCases = 0;
  std::cin >> nTestCases;
  for(int i =0;i<nTestCases;i++)
    {
      int n = 0;
      std::cin >> n;
      double pi = (M_PI);
      double s =sqrt(n * 1.0)/3.6;
      double dz = 2.0/n;
      double l = 0;
      double z = 1.0 - dz/2.0;
      for(int k = 0 ; k <=n-1; k++)
	{
	  double r = sqrt(1 - z *z);
	  std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << cos(l) * r << " " << sin(l) * r << " " << z << "\n";
	  z = z -dz;
	  l = l + s/r;
	}
    }
  return 0;
}
