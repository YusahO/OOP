#include "mesh_actions.h"

error_code_t process_action(action_t &action)
{
    error_code_t ec = SUCCESS;
    static mesh_t mesh = mesh_init();

    switch (action.id)
    {
    case LOAD:
        ec = mesh_load_from_file(mesh, action.filename);
        break;
    case SAVE:
        ec = mesh_save_to_file(mesh, action.filename);
        break;
    case TRANSLATE:
        ec = transform_translate(mesh, action.translation);
        break;
    case ROTATE:
        ec = transform_rotate(mesh, action.rotation);
        break;
    case SCALE:
        ec = transform_scale(mesh, action.scaling);
        break;
    case RENDER:
        ec = mesh_render(mesh, action.scene);
        break;
    case DESTROY:
        mesh_destroy(mesh);
        break;
    default:
        ec = ERR_UNKNOWN_ACTION;
        break;
    }

    return ec;
}

