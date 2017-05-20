#include "common.h"

int main()
{
    int a[] = {2, 3, 1, 10, 20, 12, 38, 9, 8, 11, 33, 99, 100, 34, 38, 45, 99, 66};
    int i = 0;
    struct rb_root * root = NULL;
    root = rbtree_init();
    printf(" a= = %d\n", sizeof(a)); 
    for (i = 0; i < sizeof(a)/4; i++)
        rbtree_insert(root, a[i]);

    rbtree_trav(root);
    printf("\n\n");
    for (i = 0; i < sizeof(a)/4; i++)
    {
        printf(" key = %d\n", a[i]);
        rbtree_erase(root, a[i]);   
        rbtree_trav(root);
        printf("\n");
    } 
    rbtree_destroy(root);
    return 0;
}
