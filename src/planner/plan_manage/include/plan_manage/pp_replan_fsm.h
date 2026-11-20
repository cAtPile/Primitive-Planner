#ifndef _PP_REPLAN_FSM_H_
#define _PP_REPLAN_FSM_H_

#include <Eigen/Eigen>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <ros/ros.h>
#include <plan_manage/planner_manager.h>
#include <traj_utils/planning_visualization.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Int8MultiArray.h>
#include <traj_utils/primitiveTraj.h>
#include <traj_utils/Polynomial.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Float64MultiArray.h>
#include <geometry_msgs/PoseStamped.h>
#include <quadrotor_msgs/PositionCommand.h>
#include <nav_msgs/Odometry.h>

#include <plan_manage/CSVLogger.h>

namespace primitive_planner
{
    class PPReplanFSM
    {
        public:
            PPReplanFSM() {}

            void init(ros::NodeHandle &nh);

            EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        
        private:
            enum FSM_EXEC_STATE
            {
            INIT,
            WAIT_TARGET,
            GEN_NEW_TRAJ,
            REPLAN_TRAJ,
            EXEC_TRAJ,
            EMERGENCY_STOP,
            APPROACH_GOAL,
            CRASH_RECOVER
            };

            /* planning utils */
            PPPlannerManager::Ptr planner_manager_;
            PlanningVisualization::Ptr visualization_;

            FSM_EXEC_STATE exec_state_;

            bool flag_realworld_experiment_, have_trigger_, have_odom_, have_target_, have_log_files_;

            ros::Timer exec_timer_;
            ros::Subscriber trigger_sub_, odom_sub_, mandatory_stop_sub_, select_path_end_sub_, cmd_sub_, waypoint_sub_;

            ros::Publisher path_id_pub_, stop_pub_, heartbeat_pub_, global_pub_, poly_pub_, yaw_cmd_pub_;

            double waypoints_[10][3];
            int waypoint_num_;
            int goal_id_;
            int target_type_; // 1 mannual select, 2 hard code
            std::vector<Eigen::Vector3d> all_goal_;
            Eigen::Vector3d global_goal_;
            Eigen::Vector3d odom_pos_, odom_vel_, odom_x_dir_;
            Eigen::Quaterniond odom_q_;
            double odom_yaw_;

            vector<vector<std::pair<double, vector<Eigen::Vector3d>>>> primitve_pos_;

            Eigen::Vector3d latest_safe_pt_;
            bool have_latest_safe_pt_;


            CSVLogger odom_logger_, computing_time_logger_;

            Eigen::Vector3d start_pt_, start_v_;
            Eigen::Quaterniond start_q_;

            double no_replan_thresh_, replan_thresh_;
            ros::Time start_time_;

            bool enable_fail_safe_, flag_escape_emergency_;
            
            // crash recovery
            ros::Time crash_rec_start_time_;
            bool flag_wait_crash_rec_;
            int crash_rec_stage_;
            double final_yaw_des_;
            bool flag_pub_first_yaw_;
            int yaw_cmd_count_;
            vector<double> past_yaw_list_;
            int keep_fails_;

            Eigen::Vector3d select_path_end_, select_path_end_last_;

            std::string primitiveFolder_;


            /* state machine functions */
            void execFSMCallback(const ros::TimerEvent &e);
            void changeFSMExecState(FSM_EXEC_STATE new_state, std::string pos_call);
            void printFSMExecState();

            bool planPrimitive(bool first_plan, double xV_offset = 0.0);
            bool callEmergencyStop(Eigen::Vector3d stop_pos);
            void mandatoryStopCallback(const std_msgs::Empty &msg);
            void pubPolyTraj(const Eigen::Vector3d &start_p, const Eigen::Vector3d &start_v, const Eigen::Vector3d &end_p, const double dura);

            void triggerCallback(const geometry_msgs::PoseStampedPtr &msg);
            void odometryCallback(const nav_msgs::OdometryConstPtr &msg);
            void pathEndCallback(const std_msgs::Float64MultiArrayPtr &msg);
            void cmdCallback(const quadrotor_msgs::PositionCommandPtr &cmd);
            void waypointCallback(const geometry_msgs::PoseStampedPtr &msg);

            bool readLocalTrajPos(Eigen::Vector3d& start_pos, int& vel_id, Eigen::Matrix<double, 3, 3>& Rwv, std::vector<int>& path_id, std::vector<Eigen::Vector3d>& traj_pos, double& traj_duration);
            bool readPrimitivePos();
    };

} // namespace primitive_planner

#endif