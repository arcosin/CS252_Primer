#include <stdio.h>
#include <malloc.h>

typedef int hello;

struct mystruct {
  int x;
  char a;
  int y;
};

typedef struct mystruct mystruct_t;

void printstruct(struct mystruct*);

int main() {
  //create struct, initializing all fields to zero
  mystruct_t obj1 = {0};

  hello x = 0;
  printf("%d\n", sizeof(x));

  printf("address of struct: 0x%x\n", &obj1);

  printf("address of x: 0x%x\n", &obj1.x);
  printf("address of a: 0x%x\n", &obj1.a);
  printf("address of y: 0x%x\n", &obj1.y);

  printf("difference: 0x%x\n", (char*) &obj1.y - (char*) &obj1.x);
  printf("sizeof int: %d\n", sizeof(int));

  obj1.x = 5;
  obj1.a = 'a';
  obj1.y = 6;

  printstruct(&obj1);

  struct mystruct* obj2 = malloc(sizeof(struct mystruct));
  obj2->x = 7;
  obj2->a = 'b';
  obj2->y = 8;

  printstruct(obj2);

  return 0;
}

void printstruct(struct mystruct* obj) {
  printf("struct value: (%d, %c, %d)\n", obj->x, obj->a, obj->y);
}
