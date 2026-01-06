#pragma once

class Motor {
 private:
  double duty = 0;
  bool is_cw = 0;
  double angle = 0;

 public:
  void cw(double duty);
  void ccw(double duty);
  void set_angle(bool is_cw, double angle);

  void run(double dir, double duty) {
    if (dir == 0) {
      ccw(duty);
    } else {
      cw(duty);
    }
  }
};