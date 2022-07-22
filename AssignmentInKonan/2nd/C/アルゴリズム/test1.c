#include <stdio.h>
#include <stdlib.h>

struct BinarySearchTree {
   int key;
   int data;
   struct BinarySearchTree *left;
   struct BinarySearchTree *right;
};

int search(struct BinarySearchTree *r, int key) {
    while (r != NULL) {
        if (r->key == key) return r->data;
        else if (r->key > key) r = r->left;
        else r = r->right;
    }
    return -1;
}

int main() {
    int n, m, i, key, data;
    struct BinarySearchTree n2, n4, n6, n8, n10, n12, n14;

    /* 二分探索木の初期化 */
    n8.key = 8;
    n8.data = 64;
    n8.left = &n4;
    n8.right = &n12;

    n4.key = 4;
    n4.data = 16;
    n4.left = &n2;
    n4.right = &n6;

    n2.key = 2;
    n2.data = 4;
    n2.left = NULL;
    n2.right = NULL;

    n6.key = 6;
    n6.data = 36;
    n6.left = NULL;
    n6.right = NULL;

    n12.key = 12;
    n12.data = 144;
    n12.left = &n10;
    n12.right = &n14;

    n10.key = 10;
    n10.data = 100;
    n10.left = NULL;
    n10.right = NULL;

    n14.key = 14;
    n14.data = 196;
    n14.left = NULL;
    n14.right = NULL;

    /* 二分探索木の探索 */
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        printf("キー(%d)を探索．\n", key);
        data = search(&n8, key);
        if (data == -1) {
            printf("キー(%d)を持つレコードは登録されていません．\n", key);
        } else {
            printf("キー(%d)のデータは%dです．\n", key, data);
        }
    }
}


//////////
#include <stdio.h>
#include <stdlib.h>

struct BinarySearchTree {
    int key;
    int data;
    struct BinarySearchTree *left;
    struct BinarySearchTree *right;
};

int search(struct BinarySearchTree *r, int key) {
    while (r != NULL) {
        if (r->key == key) return r->data;
        else if (r->key > key) r = r->left;
        else r = r->right;
    }
    return -1;
}

struct BinarySearchTree *regist(struct BinarySearchTree *r, int key, int data) {
    struct BinarySearchTree *p;
    if (r == NULL) {
        /* 初回登録の場合 */
        r = malloc(sizeof(struct BinarySearchTree));
        r->key = key;
        r->data = data;
        r->left = NULL;
        r->right = NULL;
        return r;
    }
    for (;;) {
        if (r->key == key) {
            r->data = data;
            return r;
        } else if (r->key > key) {
            if (r->left == NULL) {
                p = malloc(sizeof(struct BinarySearchTree));
                r->left = p;
                break;
            }
            r = r->left;
        } else {
            if (r->right == NULL) {
                p = malloc(sizeof(struct BinarySearchTree));
                r->right = p;
                break;
            }
            r = r->right;
        }
    }
    p->key = key;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int main() {
    int n, m, i, key, data;
    struct BinarySearchTree *root = NULL;

    /* 二分探索木への登録 */
    scanf("%d", &n);
    printf("レコード数(%d)\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        scanf("%d", &data);
        printf("キー(%d), データ(%d)を登録\n", key, data);
        if (root == NULL) {
            /* 初回登録の場合 */
            root = regist(root, key, data);
        } else {
            /* 二回目以降の登録の場合 */
            regist(root, key, data);
        }
    }

    /* 二分探索木の探索 */
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &key);
        printf("キー(%d)を探索．\n", key);
        data = search(root, key);
        if (data == -1) {
            printf("キー(%d)を持つレコードは登録されていません．\n", key);
        } else {
            printf("キー(%d)のデータは%dです．\n", key, data);
        }
    }
}