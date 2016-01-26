#ifndef RWX_H
#define RWX_H

#define READ 4U
#define WRITE 2U
#define EXEC 1U

typedef struct {
  unsigned int user : 3;
  unsigned int group : 3;
  unsigned int all : 3;
} permissions;

void check_permissions(permissions p);

#endif /* !RWX_H */
