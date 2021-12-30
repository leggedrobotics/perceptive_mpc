# Perceptive Model Predictive Control for Continuous Mobile Manipulation

This repository contains the source code for our work on perceptive model predictive control.
Please find the full text of the paper [here](https://www.research-collection.ethz.ch/handle/20.500.11850/426821).

J. Pankert and M. Hutter, “Perceptive Model Predictive Control for Continuous Mobile Manipulation,” *IEEE Robotics and Automation Letters*, vol. 5, no. 4, pp. 6177–6184, Oct. 2020.

```
@article{pankertPerceptiveModelPredictive2020a,
  title = {Perceptive {{Model Predictive Control}} for {{Continuous Mobile Manipulation}}},
  author = {Pankert, Johannes and Hutter, Marco},
  year = {2020},
  month = oct,
  volume = {5},
  pages = {6177--6184},
  issn = {2377-3766},
  doi = {10.1109/LRA.2020.3010721},
  journal = {IEEE Robotics and Automation Letters},
  number = {4}
}
```

Videos of our hardware experiments can be seen [here](https://youtu.be/cTXytsWyFxE).

## Installation

The software has been tested with Ros Melodic under Ubuntu 18.04.

Create a new catkin workspace, configure it to build in release, download all dependencies with wstool and build ``perceptive_mpc``.
```
sudo apt install python-catkin-tools libglpk-dev python-wstool -y
source /opt/ros/melodic/setup.bash
mkdir perceptive_mpc_ws
cd perceptive_mpc_ws
mkdir src
catkin init
catkin config --extend /opt/ros/melodic --cmake-args -DCMAKE_BUILD_TYPE=Release
cd src
git clone https://github.com/leggedrobotics/perceptive_mpc.git
wstool init . ./perceptive_mpc/perceptive_mpc_https.rosinstall
catkin build perceptive_mpc
```

Alternatively, you can also create a docker image by running:
```
docker image build -t perceptive_mpc:v0.3 .
```
or pull the image from dockerhub:
```
docker pull rslethz/perceptive_mpc
```

## Demos

### Motion Planning
The easiest way to test the software is to use the provided launchfiles in the ```perceptive_mpc``` package.


```roslaunch perceptive_mpc demo.launch```:

This will launch a kinematic simulation of the motion planner. The computed optimal state is set as the observation of the MPC. An end-effector target can be set with an interactive marker in RVIZ.

If you use the docker image, run the following commands instead:
```
xhost local:root
docker container run -it --rm --name mpc_demo \
 -e DISPLAY=$DISPLAY \
 -v /tmp/.X11-unix:/tmp/.X11-unix \
 --device /dev/dri \
 perceptive_mpc:v0.3 ./src/perceptive_mpc/scripts/run_demo.sh
```

### Collision Avoidance

```roslaunch perceptive_mpc collision_avoidance_demo.launch```:

Launches the MPC controller with collision avoidance. Call the following service to load a Euclidian Signed Distance Field (ESDF) map:

```rosservice call /voxblox_node/load_map "file_path: '/path/to/esdf/map.esdf'"```

An demo map ```example_map.esdf``` is contained in the example directory.

If you use the docker image, run the following commands instead:
```
xhost local:root
docker container run -it --rm --name collision_avoidance_demo \
 -e DISPLAY=$DISPLAY \
 -v /tmp/.X11-unix:/tmp/.X11-unix \
 --device /dev/dri \
 perceptive_mpc:v0.3 ./src/perceptive_mpc/scripts/run_demo_collision_avoidance.sh
```
After everything started, load a map by running:
```
docker exec collision_avoidance_demo ./src/perceptive_mpc/scripts/load_map.sh
```
## Mechanical Stability
The ZMP mechanical stability constraint is active by default.
The radius of the support circle (circle inscribing the support polygon) can be set in the task.info configuration file.
In the kinematic simulation, the external wrench is set to a default value specified in the `kinematic_simulation_parameters.yaml` file. The wrench is specified in end-effector reference frame.
By sending a `WrenchPoseTrajectory` message, a time varying wrench can be specified. The wrenches in this message are again specified in the desired end-effector reference frame. The end-effector references themselves need to be specified in world frame.
## Robot integration
The software can easily be integrated with a mobile manipulator platform. The configuration can be copied from ```perceptive_mpc/example/KinematicSimulation.cpp```. The tracker thread is the main control loop. The current state estimate has to be set as the system observation. The optimal control inputs can be forwarded to the motor controllers.

The admittance control module can only be tested on hardware or in a physics based simulation. The source code of ```KinematicSimulation.[h|cpp]``` contains hints on how to interface with the module.

In order to use your custom manipulator, derive from the ```KinematicsInterface``` class and override the purely virtual methods for forward kinematics computation. We provide kinematic implementations for some popular robots:
* Mabi Speedy 12
* UR10
* UR5
* UR3

The kinematics code was generated with [RobCoGen v0.4ad.0](https://robcogenteam.bitbucket.io/index.html).
Robcogen requires robot descriptions in the .kindsl/.dtdsl format. The [urdf2robcogen](https://github.com/leggedrobotics/urdf2robcogen/tree/v1.0) tool converts to this format from .urdf files.

## License
BSD-3-Clause
Copyright (c) 2020 Johannes Pankert <pankertj@ethz.ch>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. Neither the name of this work nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
