# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct C:\Users\andrew_clinkenbeard1\Box\SOC\project_workspace\final_project\platform.tcl
# 
# OR launch xsct and run below command.
# source C:\Users\andrew_clinkenbeard1\Box\SOC\project_workspace\final_project\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {final_project}\
-hw {C:\Users\andrew_clinkenbeard1\Box\SOC\Basic_FPro2\project_xsa.xsa}\
-proc {microblaze_I} -os {standalone} -out {C:/Users/andrew_clinkenbeard1/Box/SOC/project_workspace}

platform write
platform generate -domains 
platform active {final_project}
platform generate
