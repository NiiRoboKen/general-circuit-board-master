#pragma once

class MotorController {
 public:
  virtual void cw(int duty) = 0;
  virtual void ccw(int duty) = 0;
};