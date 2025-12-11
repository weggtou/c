#include <stdio.h>
#include <stdlib.h>

#define MAXR 100   /* 结果项数上限 */

typedef struct { int coef, exp; } Term;

/* 多项式结构：项数组 + 项数 */
typedef struct {
    Term t[MAXR];
    int  n;
} Poly;

/* 工具：按指数降序排序 */
static int cmp_desc(const void *a, const void *b) {
    return ((Term*)b)->exp - ((Term*)a)->exp;
}
/* 工具：按指数升序排序 */
static int cmp_asc(const void *a, const void *b) {
    return ((Term*)a)->exp - ((Term*)b)->exp;
}

/*------------------------------------------------
 * 多项式乘法：A 降序，B 升序，双索引扫描
 *------------------------------------------------*/
Poly poly_mul(const Poly *A, const Poly *B)
{
    Poly C = {0};               /* 结果多项式，初始项数=0 */
    int  pa = 0, pb = 0;        /* 当前下标 */

    /* 预处理：A 降序，B 升序 */
    qsort(A->t, A->n, sizeof(Term), cmp_desc);
    qsort(B->t, B->n, sizeof(Term), cmp_asc);

    /* 最大可能的指数和 */
    int max_exp = A->t[0].exp + B->t[B->n-1].exp;

    /* 从最大指数和递减扫描 */
    for (int k = max_exp; k >= 0; --k) {
        int sum_coef = 0;
        /* 双索引扫描：pa 向后，pb 向前 */
        int i = 0, j = B->n - 1;
        while (i < A->n && j >= 0) {
            int s = A->t[i].exp + B->t[j].exp;
            if (s < k)        /* 和太小，B 往后走（升序，指数变大）*/
                --j;
            else if (s > k)   /* 和太大，A 往后走（降序，指数变小）*/
                ++i;
            else {            /* s == k */
                sum_coef += A->t[i].coef * B->t[j].coef;
                ++i; --j;     /* 继续找同一 k 的其余项 */
            }
        }
        if (sum_coef != 0) {  /* 系数非零才保留 */
            C.t[C.n].coef = sum_coef;
            C.t[C.n].exp  = k;
            ++C.n;
        }
    }
    return C;
}

/*------------------------------------------------
 * 主函数：读入两个多项式，输出乘积
 *------------------------------------------------*/
int main(void)
{
    Poly A, B;
    printf("请输入 A 的项数："); scanf("%d", &A.n);
    for (int i = 0; i < A.n; ++i)
        scanf("%d%d", &A.t[i].coef, &A.t[i].exp);

    printf("请输入 B 的项数："); scanf("%d", &B.n);
    for (int i = 0; i < B.n; ++i)
        scanf("%d%d", &B.t[i].coef, &B.t[i].exp);

    Poly C = poly_mul(&A, &B);

    printf("\n乘积 C(x) = ");
    for (int i = 0; i < C.n; ++i) {
        printf("%+dx^%d ", C.t[i].coef, C.t[i].exp);
    }
    puts("");
    return 0;
}