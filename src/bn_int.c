#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int8_t sign;
  int16_t data_type;
  int8_t dummy;
  int32_t set_len;
  int32_t alloc_setlen;
  void *set_data;
} bn_int_t;

enum {
  BN_INT_DATA_TYPE_NORM,
  BN_INT_DATA_TYPE_32BIT,
  BN_INT_DATA_TYPE_64BIT,
  BN_INT_DATA_TYPE_128BIT,
  BN_INT_DATA_TYPE_256BIT
}BN_INT_DATA_TYPE;

#define BN_INT_SET_ALLOC_SIZE (4)

bn_int_t * bn_int_alloc(void)
{
  bn_int_t *p;

  p = (bn_int_t *)malloc(sizeof(bn_int_t));
  if (p == NULL)
    return NULL;

  //set_data is 256bit size
  p->set_data = (void *)malloc(32 * BN_INT_SET_ALLOC_SIZE);
  if (p->set_data == NULL)
    {
      free(p);
      return NULL;
    }

  memset(p->set_data, 0, 32 * BN_INT_SET_ALLOC_SIZE);
  p->set_len = 1;
  p->alloc_setlen = BN_INT_SET_ALLOC_SIZE;
  p->sign = 1;
  p->data_type = BN_INT_DATA_TYPE_NORM;

  return p;
}

void bn_int_clear(bn_int_t **);
int bn_int_length(bn_int_t *);
int bn_int_set_ui(bn_int_t **, const unsigned int);
int bn_int_set_si(bn_int_t **, const signed int);
int bn_int_set(bn_int_t *, const bn_int_t *);
int bn_int_add_ui(bn_int_t *, const bn_int_t *, const unsigned int);
int bn_int_add_si(bn_int_t *, const bn_int_t *, const signed int);
int bn_int_add(bn_int_t *, const bn_int_t *, const bn_int_t *);
int bn_int_sub_ui(bn_int_t *, const bn_int_t *, const unsigned int);
int bn_int_sub_si(bn_int_t *, const bn_int_t *, const bn_int_t *);
int bn_int_sub(bn_int_t *, const bn_int_t *, const bn_int_t *);
int bn_int_mul_ui(bn_int_t *, const bn_int_t *, const unsigned int);
int bn_int_mul_si(bn_int_t *, const bn_int_t *, const bn_int_t *);
int bn_int_mul(bn_int_t *, const bn_int_t *, const bn_int_t *);
int bn_int_div_ui(bn_int_t *, const bn_int_t *, const unsigned int);
int bn_int_div_si(bn_int_t *, const bn_int_t *, const bn_int_t *);
int bn_int_div(bn_int_t *, bn_int_t *, const bn_int_t *, const bn_int_t *);
int bn_int_mod_ui(bn_int_t *, unsigned int);
int bn_int_mod(bn_int_t *, const bn_int_t *, const bn_int_t *);

int main()
{
  return 0;
}

