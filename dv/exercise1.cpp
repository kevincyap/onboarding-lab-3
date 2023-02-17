#include <VExercise1.h>

bool checkFunction(uint8_t op) {
  bool valid = true;
  VExercise1 model;
  model.a = 0;
  model.b = 0;
  model.op = op;
  do {
    do {
      model.eval();
      uint8_t result;
      switch (op) {
        case 0:
          result = model.a ^ model.b;
          break;
        case 1:
          result = model.a << model.b;
          if (model.b >= 8) {
            result = 0;
          }
          break;
        case 2: 
          if (model.b == 0) {
            result = 0;
          } else {
            result = model.a % model.b;
          }
          break;
        case 3:
          result = ~(model.a & model.b);
          break;
      }
      valid = valid && (result == model.out);
    } while (++model.b);
  } while (++model.a);
  return valid;
}

int main() {
  bool valid = true;
  valid = valid && checkFunction(0);
  valid = valid && checkFunction(1);
  valid = valid && checkFunction(2);
  valid = valid && checkFunction(3);
  if (!valid) {
    return 1;
  }
}

