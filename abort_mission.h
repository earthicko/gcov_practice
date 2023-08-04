#ifndef ABORT_MISSION_H
#define ABORT_MISSION_H

int abort_mission_treelike(int off_course, int abort_command, int com_stat_ok);
int abort_mission_non_treelike(int off_course, int abort_command, int com_stat_ok);

#endif
