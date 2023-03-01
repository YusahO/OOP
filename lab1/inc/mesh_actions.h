#ifndef __MESH_ACTIONS_H__
#define __MESH_ACTIONS_H__

#include "vec.h"
#include "mesh.h"
#include "scene.h"
#include "transforms.h"
#include "error_processor.h"

struct scene;

enum action_id
{
    LOAD,
    SAVE,
    TRANSLATE,
    ROTATE,
    SCALE,
    RENDER,
    DESTROY
};

struct action_t
{
    action_id id;
    union
    {
        filename_t filename;
        translation_data_t translation;
        rotation_data_t rotation;
        scaling_data_t scaling;
        scene_t scene;
    };
};

error_code_t process_action(action_t &action);

#endif // __MESH_ACTIONS_H__