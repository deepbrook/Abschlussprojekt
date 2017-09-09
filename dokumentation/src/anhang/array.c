typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

/**
Insert given element into array.

    :param a: Array into which the given element is to be inserted.
    :type a: Struct Array ptr

    :param element: element to be looked up.
    :type element: int

    :return: void
    :return type: void
**/
void insertArray(Array *a, int element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (int *)realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}