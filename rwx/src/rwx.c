#include "rwx.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * from http://stackoverflow.com/questions/1024389/ \
 * print-an-int-in-binary-representation-using-c
 */

void check_permissions(permissions p) {
  if (p.user & READ) {
    printf("r");
  } else {
    printf("-");
  }
  if (p.user & WRITE) {
    printf("w");
  } else {
    printf("-");
  }
  if (p.user & EXEC) {
    printf("x");
  } else {
    printf("-");
  }


  if (p.group & READ) {
    printf("r");
  } else {
    printf("-");
  }
  if (p.group & WRITE) {
    printf("w");
  } else {
    printf("-");
  }
  if (p.group & EXEC) {
    printf("x");
  } else {
    printf("-");
  }

  if (p.all & READ) {
    printf("r");
  } else {
    printf("-");
  }
  if (p.all & WRITE) {
    printf("w");
  } else {
    printf("-");
  }
  if (p.all & EXEC) {
    printf("x");
  } else {
    printf("-");
  }
  printf("\n");
}
