# Primitive-Planner

供 `maxt_pkg` 接入的 ROS 1 单机局部路径规划器。规划节点根据目标点、里程计和障碍物点云选择运动基元，轨迹服务器将所选基元转换为位置、速度和加速度指令。

## 构建与启动

在已加载 ROS Noetic 环境的仓库根目录执行以下命令。基元生成脚本依赖 Python 3 的 toppra、NumPy、SciPy 和 Matplotlib。脚本会重建 `src/planner/plan_manage/primitive_library/`，已有匹配的基元库时可跳过生成步骤。

```bash
catkin_make -DCMAKE_BUILD_TYPE=Release
source devel/setup.bash
python3 src/scripts/generate_primitives.py
roslaunch primitive_planner planner.launch
```

## maxt_pkg 接口

独立启动时，可在 `src/planner/plan_manage/config/topics.launch` 中修改下表四个话题的默认值。命令行或宿主 launch 传入的同名参数优先。

| 启动参数 | 默认话题 | 消息类型 | 用途 |
| --- | --- | --- | --- |
| odom | /odom | nav_msgs/Odometry | 输入当前位置、姿态与速度 |
| cloud | /cloud | sensor_msgs/PointCloud2 | 输入世界坐标系中的障碍物点云 |
| goal | /goal | geometry_msgs/PoseStamped | 输入同一世界坐标系下的目标位置 |
| position_cmd | /position_cmd | quadrotor_msgs/PositionCommand | 输出轨迹采样指令 |

在宿主 launch 中包含 `$(find primitive_planner)/launch/planner.launch`，并将上述参数映射到实际话题。目标点使用位置字段，调用方负责统一输入坐标系。`map_size_x`、`map_size_y` 和 `map_size_z` 指定规划边界尺寸（米）。`primitive_folder` 可指定已有基元库的位置。

原算法见 Hou 等发表于 IEEE Transactions on Robotics 的论文。[论文链接](https://doi.org/10.1109/TRO.2025.3573667)
