#include <stdbool.h>

int abort_mission_treelike(
        int off_course,
        int abort_command,
        int com_stat_ok)
{
    int result;

    result = false;
    if (off_course || (abort_command && com_stat_ok))
        result = true;
    else
        result = false;
    return (result);
}
