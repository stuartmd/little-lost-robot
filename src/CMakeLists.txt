cmake_minimum_required(VERSION 2.6)

project(robopuzzle)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/CMakeConfig.h.in"
  "${PROJECT_BINARY_DIR}/CMakeConfig.h"
  )

set(robopuzzle_SRCS
    main.cpp
    TexSupport/Image.cpp
    TexSupport/TgaReader.cpp
    AnimatedRobot.cpp
    BestCamera.cpp
    Camera.cpp
    ChaseCamera.cpp
    Game.cpp
    Grid.cpp
    InteractSwitch.cpp
    Level.cpp
    Level1.cpp
    Level2.cpp
    LookAtCamera.cpp
    OverviewCamera.cpp
    Robot.cpp
    RobotCommand.cpp
    RobotInteractObject.cpp
    RobotVisionCamera.cpp
    Scene.cpp
    SceneObject.cpp
    SimpleCrate.cpp
    SOFinish.cpp
    SONormalSquare.cpp
    SOStart.cpp
    SOWall_End.cpp
    SOWall_L.cpp
    SOWall_Straight.cpp
    SOWall_T.cpp
    SOWater_L.cpp
    SOWater_Straight.cpp
    SOWater_StraightCrated.cpp
    SOWaterBridge_Straight.cpp
    TextureManager.cpp
    threed_objects.cpp
    TransitionCamera.cpp
    UnmovableCrate.cpp)
    
add_executable(robopuzzle ${robopuzzle_SRCS})
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(robopuzzle ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )

install(TARGETS robopuzzle RUNTIME DESTINATION bin)
