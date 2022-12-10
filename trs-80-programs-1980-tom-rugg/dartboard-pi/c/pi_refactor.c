#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// originally subroutine on line 500
int countInsideHits(int np) {
  int nh = 0;
  for(int j=0; j < np; j++) {
    double x,y;
    x = rand() * 1.0 / RAND_MAX;
    y = rand() * 1.0 / RAND_MAX;

    if(x*x+y*y < 1.0) {
      nh++;
    }
  }
  return nh;
}

// originally subroutine on line 600
void title() {
  printf("%6s%s\n","","A DARTBOARD PI CALCULATOR");
}

int main(int argc, char **argv) {
  long long t = 0, th = 0;
  int np;
  double p;
  time_t _time;

  srand((unsigned) time(&_time));
  title();

  while(1) {
    printf("SAMPLE SIZE FOR PRINTING ");
    scanf("%d", &np);
    if(np >= 1) {
      break;
    }
  }

  printf("%-10s %-10s %15s\n", "# HITS", "# THROWN", "PI");

  while(1) {
    int nh = countInsideHits(np);
    th += nh;
    t += np;
    p = 4.0 * th / t;
    printf("%10lld %10lld %15.13f\n", th, t, p);
  }
  return 0;
}


