# Primitive-Planner 文件结构

以下按目录列出仓库中的文件，省略隐藏项。第三方数值积分库仅列出顶层目录和文件。

```text
Primitive-Planner/
├── doc/                                                        # 项目文档
│   └── pkg_structor.md
├── misc/                                                       # 系统概览图与集群仿真动图
│   ├── 40_drone.gif
│   ├── dpnet_system_overview.png
│   ├── neural_primitive_system_overview.svg
│   └── system overview.png
├── src/                                                        # ROS 功能包及配套脚本
│   ├── Utils/                                                  # 目标设置、消息定义、位姿处理与可视化工具
│   │   ├── assign_goals/                                       # 为无人机分配目标点
│   │   │   ├── src/
│   │   │   │   └── assign_goals_node.cpp
│   │   │   ├── CMakeLists.txt
│   │   │   └── package.xml
│   │   ├── manual_take_over/                                   # 集群飞行的手动接管节点
│   │   │   ├── launch/
│   │   │   │   ├── take_over_drone.launch
│   │   │   │   └── take_over_station.launch
│   │   │   ├── src/
│   │   │   │   ├── ground_station.cpp
│   │   │   │   └── manual_take_over.cpp
│   │   │   ├── CMakeLists.txt
│   │   │   └── package.xml
│   │   ├── odom_visualization/                                 # 根据里程计位姿显示无人机模型
│   │   │   ├── launch/
│   │   │   │   └── run_vis_rotate.launch
│   │   │   ├── meshes/
│   │   │   │   ├── car.dae
│   │   │   │   └── fake_drone.dae
│   │   │   ├── src/
│   │   │   │   ├── odom_visualization.cpp
│   │   │   │   └── rotate_tf_for_vis.py
│   │   │   ├── CMakeLists.txt
│   │   │   ├── Makefile
│   │   │   ├── OgreMeshUpgrade.log
│   │   │   ├── mainpage.dox
│   │   │   └── package.xml
│   │   ├── pose_utils/                                         # 位姿与坐标变换工具
│   │   │   ├── include/
│   │   │   │   └── pose_utils.h
│   │   │   ├── src/
│   │   │   │   ├── pose_utils.cpp
│   │   │   │   └── pose_utils.cpp~
│   │   │   ├── CMakeLists.txt
│   │   │   ├── Makefile
│   │   │   └── package.xml
│   │   ├── quadrotor_msgs/                                     # 四旋翼控制、状态与轨迹消息
│   │   │   ├── cmake/
│   │   │   │   └── FindEigen3.cmake
│   │   │   ├── include/
│   │   │   │   └── quadrotor_msgs/                             # 四旋翼控制、状态与轨迹消息
│   │   │   │       ├── comm_types.h
│   │   │   │       ├── decode_msgs.h
│   │   │   │       └── encode_msgs.h
│   │   │   ├── msg/
│   │   │   │   ├── AuxCommand.msg
│   │   │   │   ├── Corrections.msg
│   │   │   │   ├── Gains.msg
│   │   │   │   ├── GoalSet.msg
│   │   │   │   ├── LQRTrajectory.msg
│   │   │   │   ├── Odometry.msg
│   │   │   │   ├── OutputData.msg
│   │   │   │   ├── PPROutputData.msg
│   │   │   │   ├── PolynomialTrajectory.msg
│   │   │   │   ├── PolynomialTrajectory.msg~
│   │   │   │   ├── PositionCommand.msg
│   │   │   │   ├── PositionCommand.msg~
│   │   │   │   ├── SO3Command.msg
│   │   │   │   ├── Serial.msg
│   │   │   │   ├── StatusData.msg
│   │   │   │   └── TRPYCommand.msg
│   │   │   ├── src/
│   │   │   │   ├── quadrotor_msgs/                             # 四旋翼控制、状态与轨迹消息
│   │   │   │   │   ├── msg/
│   │   │   │   │   │   ├── _AuxCommand.py
│   │   │   │   │   │   ├── _Corrections.py
│   │   │   │   │   │   ├── _Gains.py
│   │   │   │   │   │   ├── _OutputData.py
│   │   │   │   │   │   ├── _PPROutputData.py
│   │   │   │   │   │   ├── _PositionCommand.py
│   │   │   │   │   │   ├── _SO3Command.py
│   │   │   │   │   │   ├── _Serial.py
│   │   │   │   │   │   ├── _StatusData.py
│   │   │   │   │   │   ├── _TRPYCommand.py
│   │   │   │   │   │   └── __init__.py
│   │   │   │   │   ├── __init__.py
│   │   │   │   │   └── __init__.pyc
│   │   │   │   ├── decode_msgs.cpp
│   │   │   │   └── encode_msgs.cpp
│   │   │   ├── CMakeLists.txt
│   │   │   └── package.xml
│   │   ├── random_goals/                                       # 生成随机飞行目标
│   │   │   ├── launch/
│   │   │   │   ├── launch_gen_circle.py
│   │   │   │   ├── launch_gen_square.py
│   │   │   │   └── random_goals.launch
│   │   │   ├── src/
│   │   │   │   └── random_goals_node.cpp
│   │   │   ├── CMakeLists.txt
│   │   │   └── package.xml
│   │   ├── rviz_plugins/                                       # 在 RViz 中设置目标和位姿的交互工具
│   │   │   ├── config/
│   │   │   │   └── rviz_config.rviz
│   │   │   ├── src/
│   │   │   │   ├── goal_tool.cpp
│   │   │   │   ├── goal_tool.h
│   │   │   │   ├── pose_tool.cpp
│   │   │   │   └── pose_tool.h
│   │   │   ├── CMakeLists.txt
│   │   │   ├── package.xml
│   │   │   └── plugin_description.xml
│   │   ├── selected_points_publisher/                          # 发布 RViz 中选取的点
│   │   │   ├── include/
│   │   │   │   └── selected_points_publisher/                  # 发布 RViz 中选取的点
│   │   │   │       └── selected_points_publisher.hpp
│   │   │   ├── src/
│   │   │   │   └── selected_points_publisher.cpp
│   │   │   ├── CMakeLists.txt
│   │   │   ├── README.md
│   │   │   ├── package.xml
│   │   │   └── plugin_description.xml
│   │   └── uav_utils/                                          # 无人机通用工具与脚本
│   │       ├── include/
│   │       │   └── uav_utils/                                  # 无人机通用工具与脚本
│   │       │       ├── converters.h
│   │       │       ├── geometry_utils.h
│   │       │       └── utils.h
│   │       ├── scripts/
│   │       │   ├── odom_to_euler.py
│   │       │   ├── send_odom.py
│   │       │   ├── tf_assist.py
│   │       │   └── topic_statistics.py
│   │       ├── src/
│   │       │   └── uav_utils_test.cpp
│   │       ├── CMakeLists.txt
│   │       └── package.xml
│   ├── planner/                                                # 集群规划、轨迹处理与通信
│   │   ├── plan_manage/                                        # primitive_planner 包，管理运动基元规划与轨迹执行
│   │   │   ├── include/
│   │   │   │   └── plan_manage/                                # primitive_planner 包，管理运动基元规划与轨迹执行
│   │   │   │       ├── CSVLogger.h
│   │   │   │       ├── planner_manager.h
│   │   │   │       ├── pp_replan_fsm.h
│   │   │   │       └── shared_memory.h
│   │   │   ├── launch/
│   │   │   │   ├── advanced_param.xml
│   │   │   │   ├── drone_1000.rviz
│   │   │   │   ├── run_in_sim.xml
│   │   │   │   ├── simulator.xml
│   │   │   │   ├── swarm.launch                                # 启动集群规划仿真
│   │   │   │   └── verbose.rviz
│   │   │   ├── src/
│   │   │   │   ├── planner_manager.cpp                         # 实现运动基元规划逻辑
│   │   │   │   ├── pp_replan_fsm.cpp                           # 管理重规划状态机
│   │   │   │   ├── primitive_planner_node.cpp                  # 启动规划节点
│   │   │   │   └── traj_server.cpp
│   │   │   ├── CMakeLists.txt
│   │   │   └── package.xml
│   │   ├── swarm_bridge/                                       # 通过 TCP 或 UDP 在集群节点间转发消息
│   │   │   ├── include/
│   │   │   │   └── reliable_bridge.hpp
│   │   │   ├── launch/
│   │   │   │   ├── bridge_tcp_drone.launch
│   │   │   │   ├── bridge_tcp_station.launch
│   │   │   │   └── bridge_udp.launch
│   │   │   ├── src/
│   │   │   │   ├── bridge_node_tcp.cpp
│   │   │   │   ├── bridge_node_udp.cpp
│   │   │   │   └── traj2odom_node.cpp
│   │   │   ├── CMakeLists.txt
│   │   │   └── package.xml
│   │   └── traj_utils/                                         # 轨迹消息与可视化工具
│   │       ├── include/
│   │       │   └── traj_utils/                                 # 轨迹消息与可视化工具
│   │       │       ├── plan_container.hpp
│   │       │       └── planning_visualization.h
│   │       ├── msg/
│   │       │   ├── Polynomial.msg
│   │       │   ├── primitiveTraj.msg
│   │       │   └── swarmPrimitiveTraj.msg
│   │       ├── src/
│   │       │   └── planning_visualization.cpp
│   │       ├── CMakeLists.txt
│   │       └── package.xml
│   ├── scripts/                                                # 生成运动基元、配置集群场景和运行仿真的脚本
│   │   ├── dynamic_forest.py
│   │   ├── gen_position_swap.py                                # 按无人机数量生成位置交换场景的 swarm.launch
│   │   ├── gen_primitive_planner_launch.py
│   │   ├── gen_random_goal_flight.py
│   │   ├── gen_run_odom_vis.py
│   │   ├── gen_start_goal.py
│   │   ├── pub_trigger.sh                                      # 发布集群起飞任务的触发消息
│   │   ├── record_odom.sh
│   │   ├── run_batch.py
│   │   ├── run_swarm.sh
│   │   ├── start_and_goals.txt
│   │   └── swarm_path.py                                       # 离线生成运动基元库，输出到 src/planner/plan_manage/primitive_library/
│   └── uav_simulator/                                          # 无人机动力学、控制、感知与地图仿真
│       ├── fake_drone/                                         # 简化的无人机运动仿真
│       │   ├── src/
│       │   │   └── poscmd_2_odom.cpp
│       │   ├── CMakeLists.txt
│       │   └── package.xml
│       ├── local_sensing/                                      # 模拟机载传感器对局部环境的观测
│       │   ├── CMakeModules/
│       │   │   ├── FindCUDA/
│       │   │   │   ├── make2cmake.cmake
│       │   │   │   ├── parse_cubin.cmake
│       │   │   │   └── run_nvcc.cmake
│       │   │   ├── FindCUDA.cmake
│       │   │   ├── FindEigen.cmake
│       │   │   └── FindEigen.cmake~
│       │   ├── cfg/
│       │   │   └── local_sensing_node.cfg
│       │   ├── params/
│       │   │   └── camera.yaml
│       │   ├── src/
│       │   │   ├── AlignError.h
│       │   │   ├── ceres_extensions.h
│       │   │   ├── csv_convert.py
│       │   │   ├── cuda_exception.cuh
│       │   │   ├── depth_render.cu
│       │   │   ├── depth_render.cuh
│       │   │   ├── device_image.cuh
│       │   │   ├── empty.cpp
│       │   │   ├── empty.h
│       │   │   ├── euroc.cpp
│       │   │   ├── helper_math.h
│       │   │   ├── pcl_render_node.cpp
│       │   │   └── pointcloud_render_node.cpp
│       │   ├── CMakeLists.txt
│       │   └── package.xml
│       ├── map_generator/                                      # 生成仿真障碍物地图
│       │   ├── src/
│       │   │   └── random_forest_sensing.cpp
│       │   ├── CMakeLists.txt
│       │   └── package.xml
│       ├── mockamap/                                           # 生成迷宫、柱状障碍物等测试地图
│       │   ├── config/
│       │   │   └── rviz.rviz
│       │   ├── include/
│       │   │   ├── maps.hpp
│       │   │   └── perlinnoise.hpp
│       │   ├── launch/
│       │   │   ├── maze2d.launch
│       │   │   ├── maze3d.launch
│       │   │   ├── mockamap.launch
│       │   │   ├── perlin3d.launch
│       │   │   └── post2d.launch
│       │   ├── src/
│       │   │   ├── ces_randommap.cpp
│       │   │   ├── maps.cpp
│       │   │   ├── mockamap.cpp
│       │   │   └── perlinnoise.cpp
│       │   ├── CMakeLists.txt
│       │   └── package.xml
│       ├── so3_control/                                        # 四旋翼 SO(3) 控制器
│       │   ├── config/
│       │   │   ├── corrections_hummingbird.yaml
│       │   │   ├── corrections_pelican.yaml
│       │   │   ├── gains.yaml
│       │   │   ├── gains_hummingbird.yaml
│       │   │   └── gains_pelican.yaml
│       │   ├── include/
│       │   │   └── so3_control/                                # 四旋翼 SO(3) 控制器
│       │   │       └── SO3Control.h
│       │   ├── src/
│       │   │   ├── SO3Control.cpp
│       │   │   ├── control_example.cpp
│       │   │   └── so3_control_nodelet.cpp
│       │   ├── CMakeLists.txt
│       │   ├── mainpage.dox
│       │   ├── nodelet_plugin.xml
│       │   └── package.xml
│       └── so3_quadrotor_simulator/                            # 四旋翼动力学仿真器
│           ├── config/
│           │   └── rviz.rviz
│           ├── include/
│           │   ├── ode/                                        # 随仓库附带的 Boost.Odeint 数值积分库
│           │   │   ├── boost/
│           │   │   ├── libs/
│           │   │   ├── CHANGELOG
│           │   │   ├── Jamroot
│           │   │   └── README
│           │   └── quadrotor_simulator/
│           │       └── Quadrotor.h
│           ├── launch/
│           │   └── simulator_example.launch
│           ├── src/
│           │   ├── dynamics/
│           │   │   └── Quadrotor.cpp
│           │   ├── test_dynamics/
│           │   │   └── test_dynamics.cpp
│           │   └── quadrotor_simulator_so3.cpp
│           ├── CMakeLists.txt
│           └── package.xml
├── LICENSE                                                     # 项目许可证
└── README.md                                                   # 项目说明、编译方法与仿真运行步骤
```
