/*Ascending Order*/
int comp(const void *a, const void *b) {
  const int *tmp_a = (const int *)a;
  const int *tmp_b = (const int *)b;
  return *tmp_a - *tmp_b;
}

/*Descending Order*/
int comp2(const void *a, const void *b) {
  const int *tmp_a = (const int *)a;
  const int *tmp_b = (const int *)b;
  return *tmp_b - *tmp_a;
}
