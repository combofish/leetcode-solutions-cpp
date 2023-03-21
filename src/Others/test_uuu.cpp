#include <cstdio>
#include <cstdlib>

typedef struct BstNode {
    int data;
    struct BstNode *lchild, *rchild;
} BstNode, *Bstree;

BstNode *Getprior(Bstree T);

BstNode *Getnext(Bstree T);

void Insert(Bstree &T, int k);

BstNode *Search(Bstree T, int k);

void Inorder(Bstree T);

void Delete(Bstree &T, Bstree Root);

BstNode *Getparent(Bstree T, BstNode *t);

int main() {
    int N, d, K;
    Bstree T = NULL, t;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &d);
        Insert(T, d);
    }
    Inorder(T);
    printf("\n");
    t = Search(T, K);
    Delete(t, T);
    Inorder(T);
}

BstNode *Getprior(Bstree T) {
    while (T->rchild)
        T = T->rchild;
    return T;
}

BstNode *Getnext(Bstree T) {
    while (T->lchild)
        T = T->lchild;
    return T;
}

void Insert(Bstree &T, int k) {
    if (!T) {
        T = (BstNode *) malloc(sizeof(BstNode));
        T->data = k;
        T->lchild = T->rchild = NULL;
    } else if (T->data > k)
        Insert(T->lchild, k);
    else if (T->data < k)
        Insert(T->rchild, k);
}

BstNode *Search(Bstree T, int k) {
    if (T) {
        if (T->data == k)
            return T;
        else if (T->data > k)
            return Search(T->lchild, k);
        return Search(T->rchild, k);
    }
}

void Inorder(Bstree T) {
    if (T) {
        Inorder(T->lchild);
        printf("%d ", T->data);
        Inorder(T->rchild);
    }
}

void Delete(Bstree &T, Bstree Root) {
    if (!T)
        return;
    if (!T->lchild && !T->rchild) {
        if (T == Root)
            free(T);
        else {
            BstNode *p = Getparent(Root, T);
            free(T);
            if (p->lchild == T)
                p->lchild = NULL;
            else if (p->rchild == T)
                p->rchild = NULL;
        }
    } else if (T->rchild) {
        BstNode *t = Getnext(T->rchild);
        T->data = t->data;
        Delete(t, Root);
    } else {
        BstNode *t = Getnext(T->lchild);
        T->data = t->data;
        Delete(t, Root);
    }
}

BstNode *Getparent(Bstree T, BstNode *t) {
    if (T) {
        if (T->rchild == t || T->lchild == t)
            return T;
        if (T->data > t->data)
            return Getparent(T->lchild, t);
        return Getparent(T->rchild, t);
    }
}
