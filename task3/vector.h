#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>

struct vector;

struct vector* vector(int size);

int vector_get_size(struct vector* v);

int vector_get_capacity(struct vector* v);

int vector_get(struct vector* v, int i);

void vector_set(struct vector* v, int i, int new_value);

struct vector* vector_resize(struct vector* v, int size);

void vector_push(struct vector* v, int value);

void vector_destroy(struct vector* v);

struct vector* vector_copy(struct vector* v_target, struct vector* v_source);

void vector_print(struct vector* v, FILE* stream);
#endif