#include "common.h"

int main()
{
    int a[] = {2, 3, 1, 10, 20, 12, 38, 9, 8, 11, 33, 99, 100, 34, 38, 45, 99, 66};
    int i = 0;
    struct rb_root * root = NULL;
    root = rbtree_init();
     
    for (i = 0; i < sizeof(a); i++)
        rbtree_insert(root, a[i]);

    rbtree_trav(root);

    for (i = 0; i < sizeof(a); i++)
        rbtree_erase(root, a[i]);    
    rbtree_destroy(root);
    return 0;
}
