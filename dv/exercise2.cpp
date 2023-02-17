#include <VExercise2.h>
#include <bitset>
#include <vector>

void LFSR(uint16_t& state) {
  uint16_t next = (state << 1) & ~1;
  //mimic this functionality in verilog out <= {out[14:0], out[10] ^ out[8] ^ out[3] ^ out[1]};
  next |= ((state >> 10) ^ (state >> 8) ^ (state >> 3) ^ (state >> 1)) & 1;

  state = next;
}

void step(VExercise2& model) {
  model.clk = 1;
  model.eval();
  model.clk = 0;
  model.eval();
}

bool runTest(VExercise2& model, uint16_t val, size_t steps) {
  model.reset = 1;
  model.init = val;
  step(model);
  model.reset = 0;

  uint16_t state = ~val;
  bool valid = true;
  while (--steps) {
    step(model);
    LFSR(state);
    valid = valid & (model.out == state);
  } 
  return valid;
}

int main() {
  uint16_t val = 31477;

  VExercise2 model;
  return !runTest(model, val, 1000);
}
