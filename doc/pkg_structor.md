# Primitive-Planner 文件结构

以下按目录列出源码文件，省略隐藏项和本地生成的基元库。

```text
Primitive-Planner/
├── doc/                                                    # 项目文档
│   └── pkg_structor.md
├── src/                                                    # ROS 功能包与离线生成工具
│   ├── Utils/
│   │   └── quadrotor_msgs/                                 # 轨迹服务器的位置指令消息
│   │       ├── msg/
│   │       │   └── PositionCommand.msg
│   │       ├── CMakeLists.txt
│   │       └── package.xml
│   ├── planner/
│   │   ├── plan_manage/                                    # 局部规划、重规划状态机与轨迹服务器
│   │   │   ├── include/
│   │   │   │   └── plan_manage/
│   │   │   │       ├── CSVLogger.h
│   │   │   │       ├── planner_manager.h
│   │   │   │       └── pp_replan_fsm.h
│   │   │   ├── launch/
│   │   │   │   └── planner.launch                          # 单机规划入口
│   │   │   ├── src/
│   │   │   │   ├── planner_manager.cpp
│   │   │   │   ├── pp_replan_fsm.cpp
│   │   │   │   ├── primitive_planner_node.cpp
│   │   │   │   └── traj_server.cpp
│   │   │   ├── CMakeLists.txt
│   │   │   └── package.xml
│   │   └── traj_utils/                                     # 轨迹消息与可视化
│   │       ├── include/
│   │       │   └── traj_utils/
│   │       │       └── planning_visualization.h
│   │       ├── msg/
│   │       │   ├── Polynomial.msg
│   │       │   └── primitiveTraj.msg
│   │       ├── src/
│   │       │   └── planning_visualization.cpp
│   │       ├── CMakeLists.txt
│   │       └── package.xml
│   └── scripts/
│       └── generate_primitives.py                          # 生成运动基元和障碍物碰撞查询表
├── LICENSE
└── README.md
```
