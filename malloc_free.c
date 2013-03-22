
/*调用free之后，悬挂指针未赋值为NULL的情况。*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *p = malloc(128);

    p = "hello";
    printf("%s\n", p);

    free(p);
    printf("%s\n", p);

    return 0;
}

/*输出：
 *hello
 *hello
 */
