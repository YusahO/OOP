
cmake_minimum_required(VERSION 3.0.0)
project(lab3 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui/)

set(src_files
"./lib/adapters/composite/DrawCompositeAdapter.cpp"
"./lib/adapters/model/DrawCarcassModelAdapter.cpp"
"./lib/objects/BaseObject.cpp"
"./lib/objects/Composite.cpp"
"./lib/objects/invisibleobject/Camera.cpp"
"./lib/objects/invisibleobject/InvisibleObject.cpp"
"./lib/objects/visibleobject/BaseModel.cpp"
"./lib/objects/visibleobject/carcassmodel/Mesh.cpp"
"./lib/objects/visibleobject/carcassmodel/Vertex.cpp"
"./lib/objects/visibleobject/carcassmodel/CarcassModel.cpp"
"./lib/objects/visibleobject/carcassmodel/Edge.cpp"
"./lib/facade/Facade.cpp"
"./lib/actions/CameraAction.cpp"
"./lib/actions/SceneAction.cpp"
"./lib/actions/ModelAction.cpp"
"./lib/actions/BaseAction.cpp"
"./lib/actions/ModelsAction.cpp"
"./lib/matrix/errors/errors.cpp"
"./lib/matrix/matrix/matrix_base.cpp"
"./lib/load/directors/model/FileModelDirector.cpp"
"./lib/load/directors/loader/FileCarcassModelLoader.cpp"
"./lib/load/directors/loader/BaseLoader.cpp"
"./lib/load/directors/scene/FileSceneDirector.cpp"
"./lib/load/directors/camera/FileCameraDirector.cpp"
"./lib/load/builders/model/ModelBuilder.cpp"
"./lib/load/builders/scene/SceneBuilder.cpp"
"./lib/load/builders/camera/CameraBuilder.cpp"
"./lib/load/moderators/BaseLoadModerator.cpp"
"./lib/load/moderators/creators/ModelLoadModeratorCreator.cpp"
"./lib/load/moderators/creators/SceneLoadModeratorCreator.cpp"
"./lib/load/moderators/creators/CameraLoadModeratorCreator.cpp"
"./lib/load/moderators/model/ModelLoadModerator.cpp"
"./lib/load/moderators/scene/SceneLoadModerator.cpp"
"./lib/load/moderators/camera/CameraLoadModerator.cpp"
"./lib/drawer/QtDrawer.cpp"
"./lib/drawer/QtFactory.cpp"
"./lib/scene/Scene.cpp"
"./lib/managers/creators/LoadManagerCreator.cpp"
"./lib/managers/creators/DrawManagerCreator.cpp"
"./lib/managers/creators/TransformManagerCreator.cpp"
"./lib/managers/creators/SceneManagerCreator.cpp"
"./lib/managers/transform/TransformManager.cpp"
"./lib/managers/draw/DrawManager.cpp"
"./lib/managers/load/LoadManager.cpp"
"./lib/managers/scene/SceneManager.cpp"
"./src/mainwindow.cpp"
"./src/main.cpp"
)

add_executable(lab3
    ${src_files}
)
target_include_directories(lab3 PUBLIC ./lib/adapters)
target_include_directories(lab3 PUBLIC ./lib/adapters/composite)
target_include_directories(lab3 PUBLIC ./lib/adapters/model)
target_include_directories(lab3 PUBLIC ./lib/objects)
target_include_directories(lab3 PUBLIC ./lib/objects/invisibleobject)
target_include_directories(lab3 PUBLIC ./lib/objects/visibleobject)
target_include_directories(lab3 PUBLIC ./lib/objects/visibleobject/carcassmodel)
target_include_directories(lab3 PUBLIC ./lib/facade)
target_include_directories(lab3 PUBLIC ./lib/actions)
target_include_directories(lab3 PUBLIC ./lib/matrix)
target_include_directories(lab3 PUBLIC ./lib/matrix/matrix)
target_include_directories(lab3 PUBLIC ./lib/matrix/iterator)
target_include_directories(lab3 PUBLIC ./lib/load/directors)
target_include_directories(lab3 PUBLIC ./lib/load/directors/model)
target_include_directories(lab3 PUBLIC ./lib/load/directors/loader)
target_include_directories(lab3 PUBLIC ./lib/load/directors/scene)
target_include_directories(lab3 PUBLIC ./lib/load/directors/camera)
target_include_directories(lab3 PUBLIC ./lib/load/builders)
target_include_directories(lab3 PUBLIC ./lib/load/builders/model)
target_include_directories(lab3 PUBLIC ./lib/load/builders/scene)
target_include_directories(lab3 PUBLIC ./lib/load/builders/camera)
target_include_directories(lab3 PUBLIC ./lib/load/moderators)
target_include_directories(lab3 PUBLIC ./lib/load/moderators/creators)
target_include_directories(lab3 PUBLIC ./lib/load/moderators/model)
target_include_directories(lab3 PUBLIC ./lib/load/moderators/scene)
target_include_directories(lab3 PUBLIC ./lib/load/moderators/camera)
target_include_directories(lab3 PUBLIC ./lib/drawer)
target_include_directories(lab3 PUBLIC ./lib/scene)
target_include_directories(lab3 PUBLIC ./lib/exceptions)
target_include_directories(lab3 PUBLIC ./lib/managers)
target_include_directories(lab3 PUBLIC ./lib/managers/creators)
target_include_directories(lab3 PUBLIC ./lib/managers/transform)
target_include_directories(lab3 PUBLIC ./lib/managers/draw)
target_include_directories(lab3 PUBLIC ./lib/managers/load)
target_include_directories(lab3 PUBLIC ./lib/managers/scene)
target_include_directories(lab3 PUBLIC ./src)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

target_link_libraries(lab3 Qt5::Widgets)
target_include_directories(lab3 PUBLIC include)

