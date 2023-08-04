#include <stdbool.h>

int abort_mission_non_treelike(
        int off_course,
        int abort_command,
        int com_stat_ok)
{
    int result;

    result = false;
    if ((abort_command && com_stat_ok) || off_course)
        result = true;
    else
        result = false;
    return (result);
}
