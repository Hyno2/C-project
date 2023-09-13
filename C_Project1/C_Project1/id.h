#pragma once

void saveUsers(struct User users[], int numUsers);
extern int loadUsers(struct User users[]);
extern int checkID(struct User users[], int numUsers, const char* id);
extern int main();