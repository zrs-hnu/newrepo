#ifndef DEFINE_H
#define DEFINE_H

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// vehicle‘s physical coff，maybe need
struct mkz_veh {
  /// mkz param
  double front_edge_to_center = 3.0;
  double back_edge_to_center = 1.043;
  double left_edge_to_center = 1.055;
  double right_edge_to_center = 1.055;
  double length = 4.933;
  double width = 2.11;
  double height = 1.48;
  double min_turn_radius = 5.05386147161;
  double max_acceleration = 2.0;
  double max_deceleration = -6.0;
  double max_steer_angle = 8.20304748437;
  double max_steer_angle_rate = 6.98131700798;
  double min_steer_angle_rate = 0;
  double steer_ratio = 16;
  double wheel_base = 2.8448;
  double wheel_rolling_radius = 0.335;
  double max_abs_speed_when_stopped = 0.2;
};

struct Truck {
  double front_edge_to_center = 3.89;
  double back_edge_to_center = 1.043;
  double left_edge_to_center = 1.055;
  double right_edge_to_center = 1.055;
  double length = 4.933;
  double width = 2.11;
  double height = 1.48;
  double min_turn_radius = 5.05386147161;
  double max_acceleration = 2.0;   //最大加速度
  double max_deceleration = -6.0;  //最大减速度
  double max_steer_angle = 8.20304748437;
  double max_steer_angle_rate = 6.98131700798;
  double min_steer_angle_rate = 0;
  double steer_ratio = 24.4;
  double wheel_base = 4.8;
  double wheel_rolling_radius = 0.335;
  double max_abs_speed_when_stopped = 0.2;
};
//**vehicle‘s physical coff

// zrs's work,MATLAB's statefcn's vehicle‘s physical coff
// #define m_car 2270
// #define C_ry 130000
// #define lr 1.434 //质心与后轴的轴距
// #define C_fy 127000
// #define lf 1.421 //质心与前轴的轴距
// #define Iz 4600
// zrs's work,<<无人驾驶车辆模型预测控制>>p117 vehicle‘s physical coff
#define m_car 1723
#define C_ry 62700
#define lr 1.468  //质心与后轴的轴距
#define C_fy 66900
#define lf 1.232  //质心与前轴的轴距
#define Iz 4175
#define v0 16.67            //初始速度60km/h
#define acc 6.86            //最大减速度 0.7*9.8
#define f_rx_max -11819.78  //最大制动力 -0.7*9.8*m
//#define f_rx_max -5909.9 //最大制动力 0.5*(-0.7*9.8*m)

//**zrs's work

int get_mpc_n(vector<double> ref_traj_x, double x_veh) {
  int index;
  for (int i = 1; i < ref_traj_x.size(); i++) {
    if ((x_veh <= ref_traj_x[i]) && (x_veh >= ref_traj_x[i - 1])) {
      index = i;
    } else if (abs(x_veh) < 0.001) {
      index = 0;
    }
  }
  return index;
}
#endif
