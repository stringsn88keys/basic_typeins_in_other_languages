//
// Created by Thomas Powell on 12/10/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *countInsideHits(void *ptrNp) {
  int *nh;
  nh = (int*)malloc(sizeof(int));
  int np = *((int *) ptrNp);
  for(int j=0; j < np; j++) {
    double x,y;
    x = rand() * 1.0 / RAND_MAX;
    y = rand() * 1.0 / RAND_MAX;

    if(x*x+y*y < 1.0) {
        (*nh)++;
    }
  }
  return (void*)nh;
}

void title() {
  printf("%6s%s\n","","A DARTBOARD PI CALCULATOR");
}

int main(int argc, char **argv) {
    long long t = 0, th = 0;
    int np;
    int nThreads;
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

    while(1) {
        printf("NUMBER OF THREADS ");
        scanf("%d", &nThreads);
        if(nThreads >= 1) {
            break;
        }
    }

    printf("%-10s %-10s %15s\n", "# HITS", "# THROWN", "PI");

    while(1) {
        pthread_t threads[nThreads];
        int *nh[nThreads];
        for (int i = 0; i < nThreads; i++) {
            pthread_create(&threads[i], NULL, countInsideHits, (void*)&np);
        }
        for (int i = 0; i < nThreads; i++) {
            pthread_join(threads[i], (void*)&nh[i]);
            th += *(nh[i]);
            free(nh[i]);
            t += np;
            p = 4.0 * th / t;
            printf("%10lld %10lld %15.13f\n", th, t, p);
        }
    }
    return 0;
}