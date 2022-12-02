#include "./vector.h"
#include <stdio.h>

int main(int argc, char** argv){
    FILE* output_stream = stdout;
    if (argc == 2)
        output_stream = fopen(argv[1], "wb");

    printf("push\n");
    struct vector* v1= vector(10);
    vector_push(v1, 321);
    vector_push(v1, 534);
    vector_push(v1, 3219);
    vector_print(v1, output_stream);
    printf("set\n");
    vector_set(v1, 2, 1337);
    vector_print(v1, output_stream);

    printf("vector 1\n");
    vector_print(v1, output_stream);

    printf("vector 2\n");
    struct vector* v2= vector(45);
    vector_push(v2, 132);
    vector_push(v2, 965);
    vector_push(v2, 0);
    vector_print(v2, output_stream);

    printf("copy v1 to v2\n");
    v2 = vector_copy(v2, v1);
    vector_print(v2, output_stream);

    printf("resize vector to less value\n");
    printf("before resize capacity : %d; size : %d\n", vector_get_capacity(v2), vector_get_size(v2));
    v2 = vector_resize(v2, 40);
    vector_print(v2, output_stream);
    printf("after resize capacity : %d; size : %d\n", vector_get_capacity(v2), vector_get_size(v2));

    printf("resize vector to bigger value\n");
    printf("before resize capacity : %d; size : %d\n", vector_get_capacity(v2), vector_get_size(v2));
    v2 = vector_resize(v2, 49);
    printf("after resize capacity : %d; size : %d\n", vector_get_capacity(v2), vector_get_size(v2));
    vector_print(v2, output_stream);

    printf("capacity : %d; size : %d\n", vector_get_capacity(v2), vector_get_size(v2));
    
    printf("free vectors\n");
    vector_destroy(v1);
    vector_destroy(v2);

    fclose(output_stream);
}