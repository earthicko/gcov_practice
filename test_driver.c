#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "abort_mission.h"

void test_abort_mission(
        int expected_output,
        int off_course,
        int abort_command,
        int com_stat_ok)
{
    int result_treelike;
    int result_non_treelike;

    result_treelike =
        abort_mission_treelike(off_course, abort_command, com_stat_ok);
    result_non_treelike =
        abort_mission_non_treelike(off_course, abort_command, com_stat_ok);
    assert(result_treelike == result_non_treelike);
    printf("abort_mission(%d, %d, %d) == %d",
        off_course, abort_command, com_stat_ok, result_treelike);
    if (result_treelike == expected_output)
        printf(", PASS\n");
    else
        printf(", FAIL\n");
}

int main(void)
{
    test_abort_mission(true, true, false, true);
    test_abort_mission(false, false, true, false);
    test_abort_mission(true, false, true, true);
    // test_abort_mission(false, false, false, true);

    return (0);
}
