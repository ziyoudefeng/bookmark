// 1
/*调用free之后，悬挂指针未赋值为NULL的情况。*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *p = malloc(128);

    p = "hello";
    printf("%s\n", p);

    free(p); 
    printf("%s\n", p); // p = NULL未设置
    free(p); //多次释放
    return 0;
}

/*输出：
 *hello
 *hello
 */

// 2
/*free 非malloc、calloc、realloc分配的内存*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *p = NULL;

    char buf[20];
    int n = 21;

    if (n >= sizeof(buf)) {
        p = malloc(n);
    } else {
        p = buf;
    }

    free(p); //这里不会报错，但通常却会破坏内存管理的数据结构，而且直到以后才能发现。

    return 0;
}

// 3
/*返回局部变量，不会报错*/
#include <stdio.h>
#include <stdlib.h>

char *i2a(int n)
{
    char buf[43];

    sprintf(buf, "%d", n);
    return buf; // buf为局部变量
}

int main(void)
{
    int i = 125;
    char *s = i2a(i);
    printf("%d\t%s", i, s); //可以运行，不过就是返回的值不对而已。

    return 0;
}

