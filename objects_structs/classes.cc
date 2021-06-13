#include <cstdio>
#include <malloc.h>

//for pre-allocated new operation
#include <new>

class MyClass {
    int test;
  public:
    MyClass(int initial_value);
    MyClass();
    int x;
    void set_private_var(int value);
    int get_private_var();

  private:
    int private_var;
};

MyClass::MyClass(int initial_value) {
  this->private_var = initial_value;
}

MyClass::MyClass() {
  this->private_var = 0;
}

void MyClass::set_private_var(int value) {
  this->private_var = value;
}

int MyClass::get_private_var() {
  return this->private_var;
}

int main() {

  MyClass obj = MyClass(5);

  printf("%d\n", obj.get_private_var());
  obj.set_private_var(10);
  printf("%d\n", obj.get_private_var());

  MyClass* obj2 = new MyClass();

  obj2->set_private_var(15);
  printf("obj2: %d\n", obj2->get_private_var());

  //example of using pre-allocated memory
  void* obj3_memory = malloc(sizeof(MyClass));
  MyClass* obj3 = new(obj3_memory) MyClass();
}
