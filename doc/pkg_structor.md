# Primitive-Planner 文件结构

以下按目录列出源码文件，省略隐藏项和本地生成的基元库。

```text
Primitive-Planner/
├── doc/                                                    # 项目文档
│   └── pkg_structor.md                                     # 本文档，说明仓库目录和各文件的职责。
├── src/                                                    # ROS 功能包与离线生成工具
│   ├── Utils/
│   │   └── quadrotor_msgs/                                 # 轨迹服务器的位置指令消息
│   │       ├── msg/
│   │       │   └── PositionCommand.msg                     # 定义位置指令消息，包含位置、速度、加速度、加加速度、航向、航向角速度及轨迹状态。
│   │       ├── CMakeLists.txt                              # 从 PositionCommand.msg 生成 ROS 消息代码，供发布者和订阅者使用。
│   │       └── package.xml                                 # 声明 quadrotor_msgs 包及其消息生成和运行依赖。
│   ├── planner/
│   │   ├── plan_manage/                                    # 局部规划、重规划状态机与轨迹服务器
│   │   │   ├── include/
│   │   │   │   └── plan_manage/
│   │   │   │       ├── CSVLogger.h                         # 提供 CSV 日志工具，用于创建日志目录、格式化数据和写入记录。
│   │   │   │       ├── planner_manager.h                   # 声明 PPPlannerManager 的基元加载、碰撞标记和路径评分接口。
│   │   │   │       └── pp_replan_fsm.h                     # 声明 PPReplanFSM 的执行状态、状态转换函数、订阅回调和定时器回调。
│   │   │   ├── launch/
│   │   │   │   └── planner.launch                          # 启动规划节点和轨迹服务器，配置节点参数与话题映射。
│   │   │   ├── src/
│   │   │   │   ├── planner_manager.cpp                     # 实现基元筛选与排序，用障碍物点云查询碰撞表，标记受阻路径，再结合目标位置给候选路径评分。
│   │   │   │   ├── pp_replan_fsm.cpp                       # 实现重规划状态机，根据里程计、目标点和执行状态决定何时选取新基元、发布轨迹或急停。
│   │   │   │   ├── primitive_planner_node.cpp              # 规划节点的 main 入口，初始化 ROS 和状态机，进入事件循环处理回调。
│   │   │   │   └── traj_server.cpp                         # 实现轨迹服务器，读取选中基元的采样数据或计算多项式轨迹，按执行时间发布位置指令。
│   │   │   ├── CMakeLists.txt                              # 配置 primitive_planner_node 和 traj_server 两个可执行文件的编译与链接。
│   │   │   └── package.xml                                 # 声明 ROS 包名 primitive_planner 及其依赖，启动文件通过该包名查找节点。
│   │   └── traj_utils/                                     # 轨迹消息与可视化
│   │       ├── include/
│   │       │   └── traj_utils/
│   │       │       └── planning_visualization.h            # 声明 PlanningVisualization 类，提供显示目标点、候选路径和选中轨迹等接口。
│   │       ├── msg/
│   │       │   ├── Polynomial.msg                          # 定义五次多项式轨迹，保存起始时间、持续时间及 x、y、z 各轴的六个系数。
│   │       │   └── primitiveTraj.msg                       # 描述选中的基元，包含速度档位、路径编号、起始时间、起点位置与速度、终点位置和旋转矩阵。
│   │       ├── src/
│   │       │   └── planning_visualization.cpp              # 将目标点和轨迹点列转换为球体、折线或箭头等 ROS 标记，供 RViz 显示。
│   │       ├── CMakeLists.txt                              # 配置两种轨迹消息的代码生成，并将可视化实现编译为 traj_utils 库。
│   │       └── package.xml                                 # 声明 traj_utils 包及其消息生成、运行与可视化依赖。
│   └── scripts/
│       └── generate_primitives.py                          # 离线生成运动基元，按起始速度和路径编号保存轨迹采样，并建立障碍物体素到受影响路径的查询表。
├── LICENSE                                                 # 收录 GNU 通用公共许可证第 3 版（GPLv3）全文。
└── README.md                                               # 说明项目的构建与启动步骤，以及与 maxt_pkg 对接的接口。
```
