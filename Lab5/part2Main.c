#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern void addHeap(int);
extern void heapXML(int);
extern int heapDelete();

int main(int argc, char * argv[])
{
  int value;
  int i =0, j,temp, max=0, begin = 0, initialArray[100];
  
  while (scanf("%d\n", &value) != EOF) {
    fprintf(stderr, "READING INPUT: %d\n", value);
     initialArray[i++] = value; 
  }

  while (begin <i){
    max = begin;
    for( j = begin; j<i; j++){
      if(initialArray[j] > initialArray[max]){
        max = j;
      }

    }
    addHeap(initialArray[max]);
    temp = initialArray[begin];
    initialArray[begin] = initialArray[max];
    initialArray[max] = temp;
    begin++;
  }
 
  fprintf(stderr, "\n");
  heapXML(1);
  fprintf(stderr, "\n\n");
  for(i=0; i<begin;i++){
    push(heapDelete());
  }
  fprintf(stderr, "\n");
  for(i=0; i < begin; i++){
    fprintf(stderr, "%d\n", pop());
  }
  exit(0);
}
