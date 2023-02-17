#include <VExercise4.h>

int main() {
  VExercise4 model;
  uint8_t a, b, g;
  a = 3;
  b = 1;
  g = 2;
  model.alpha = a;
  model.beta = b;
  model.gamma = g;
  
  bool valid = true;

  model.cs = 0;
  for (int i = 0; i < 4; ++i) {
    model.sel = i;
    model.eval();
    valid = valid & (model.out == 0);
  }

  model.cs = 1;
  for (int i = 0; i < 4; ++i) {
    model.sel = i;
    model.eval();
    switch (i) {
      case 0:
        valid = valid & (model.out == a);
        break;
      case 1:
        valid = valid & (model.out == b);
        break;
      case 2:
        valid = valid & (model.out == g);
        break;
      case 3:
        valid = valid & (model.out == (a & (b | g)));
        break;
    }
  }
  return !valid;
}
